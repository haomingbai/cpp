/*************************************************************************
    > File Name: 5-005.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Fri Nov 24 20:01:45 2023
 ************************************************************************/

#include<iostream>
using namespace std;

// 一个用C++写的进行线性拟合的函数
// 输入是一个二维数组用于存放数据，一个整数表示变量的组数，一个一维数组用于计算出的直线的斜率和截距
// 输出是一个布尔值，表示是否成功进行了线性拟合

#include <iostream>
#include <cmath>

#include<malloc.h>
using namespace std;

// 定义一个二维数组的类，方便操作
class Matrix {
    private:
        int rows; // 行数
        int cols; // 列数
        double** data; // 数据
    public:
        // 构造函数，根据给定的行数和列数创建一个二维数组，并初始化为0
        Matrix(int r, int c) {
            rows = r;
            cols = c;
            data = new double*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new double[cols];
                for (int j = 0; j < cols; j++) {
                    data[i][j] = 0;
                }
            }
        }

        // 析构函数，释放内存
        ~Matrix() {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }

        // 获取行数
        int getRows() {
            return rows;
        }

        // 获取列数
        int getCols() {
            return cols;
        }

        // 获取指定位置的元素
        double get(int i, int j) {
            return data[i][j];
        }

        // 设置指定位置的元素
        void set(int i, int j, double value) {
            data[i][j] = value;
        }

        // 打印矩阵
        void print() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }

        // 矩阵相加，返回一个新的矩阵
        Matrix add(Matrix m) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.set(i, j, data[i][j] + m.get(i, j));
                }
            }
            return result;
        }

        // 矩阵相减，返回一个新的矩阵
        Matrix subtract(Matrix m) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.set(i, j, data[i][j] - m.get(i, j));
                }
            }
            return result;
        }

        // 矩阵相乘，返回一个新的矩阵
        Matrix multiply(Matrix m) {
            Matrix result(rows, m.getCols());
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < m.getCols(); j++) {
                    double sum = 0;
                    for (int k = 0; k < cols; k++) {
                        sum += data[i][k] * m.get(k, j);
                    }
                    result.set(i, j, sum);
                }
            }
            return result;
        }

		//矩阵乘系数
		void multiply(double n) {
			for(int r=0;r<rows;r++) for(int c=0;c<cols;c++) data[r][c]*=n;
		}

        // 矩阵转置，返回一个新的矩阵
        Matrix transpose() {
            Matrix result(cols, rows);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.set(j, i, data[i][j]);
                }
            }
            return result;
        }

        // 矩阵求逆，返回一个新的矩阵，使用高斯-约当消元法
        Matrix inverse() {
            Matrix result(rows, cols);
            Matrix temp(rows, 2 * cols); // 扩展矩阵
            // 将原矩阵和单位矩阵复制到扩展矩阵中
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    temp.set(i, j, data[i][j]);
                }
                for (int j = cols; j < 2 * cols; j++) {
                    if (i == j - cols) {
                        temp.set(i, j, 1);
                    } else {
                        temp.set(i, j, 0);
                    }
                }
            }
            // 进行行变换，将左边的矩阵变为上三角矩阵
            for (int i = 0; i < rows - 1; i++) {
                // 如果主对角线上的元素为0，就交换两行
                if (temp.get(i, i) == 0) {
                    for (int j = i + 1; j < rows; j++) {
                        if (temp.get(j, i) != 0) {
                            for (int k = 0; k < 2 * cols; k++) {
                                double t = temp.get(i, k);
                                temp.set(i, k, temp.get(j, k));
                                temp.set(j, k, t);
                            }
                            break;
                        }
                    }
                }
                // 如果主对角线上的元素仍然为0，说明矩阵不可逆，返回空矩阵
                if (temp.get(i, i) == 0) {
                    return Matrix(0, 0);
                }
                // 用主对角线上的元素将下面的元素消为0
                for (int j = i + 1; j < rows; j++) {
                    double t = temp.get(j, i) / temp.get(i, i);
                    for (int k = 0; k < 2 * cols; k++) {
                        temp.set(j, k, temp.get(j, k) - t * temp.get(i, k));
                    }
                }
            }
            // 进行行变换，将左边的矩阵变为单位矩阵
            for (int i = rows - 1; i >= 0; i--) {
                // 用主对角线上的元素将上面的元素消为0
                for (int j = i - 1; j >= 0; j--) {
                    double t = temp.get(j, i) / temp.get(i, i);
                    for (int k = 0; k < 2 * cols; k++) {
                        temp.set(j, k, temp.get(j, k) - t * temp.get(i, k));
                    }
                }
                // 将主对角线上的元素变为1
                double t = temp.get(i, i);
                for (int j = 0; j < 2 * cols; j++) {
                    temp.set(i, j, temp.get(i, j) / t);
                }
            }
            // 将右边的矩阵复制到结果矩阵中
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.set(i, j, temp.get(i, j + cols));
                }
            }
            return result;
        }
};

// 定义一个进行线性拟合的函数
// 输入是一个二维数组用于存放数据，一个整数表示变量的组数，一个一维数组用于计算出的直线的斜率和截距
// 输出是一个布尔值，表示是否成功进行了线性拟合
bool linearFit(double** data, int n, double* result) {
    // 检查输入是否合法
    if (data == NULL || n <= 0 || result == NULL) {
        return false;
    }
    // 创建一个矩阵对象，用于存放数据
    Matrix m(n, 2);
    // 将数据复制到矩阵中
    for (int i = 0; i < n; i++) {
        m.set(i, 0, data[i][0]); // x值
        m.set(i, 1, data[i][1]); // y值
    }
    // 创建一个矩阵对象，用于存放x的平方和
    Matrix x2(n, 1);
    // 计算x的平方和，并存放到矩阵中
    for (int i = 0; i < n; i++) {
        x2.set(i, 0, pow(m.get(i, 0), 2));
    }
    // 创建一个矩阵对象，用于存放x和y的乘积
    Matrix xy(n, 1);
    // 计算x和y的乘积，并存放到矩阵中
    for (int i = 0; i < n; i++) {
        xy.set(i, 0, m.get(i, 0) * m.get(i, 1));
    }
    // 创建一个矩阵对象，用于存放x的和
    Matrix xsum(1, 1);
    // 计算x的和，并存放到矩阵中
    for (int i = 0; i < n; i++) {
        xsum.set(0, 0, xsum.get(0, 0) + m.get(i, 0));
    }
    // 创建一个矩阵对象，用于存放y的和
    Matrix ysum(1, 1);
    // 计算y的和，并存放到矩阵中
    for (int i = 0; i < n; i++) {
        ysum.set(0, 0, ysum.get(0, 0) + m.get(i, 1));
    }
    // 创建一个矩阵对象，用于存放系数矩阵
    Matrix a(2, 2);
    // 计算系数矩阵，并存放到矩阵中
    /*a.set(0, 0, x2.multiply(Matrix::transpose(x2)).get(0, 0));
    a.set(0, 1, xsum.multiply(Matrix::transpose(x2)).get(0, 0));
    a.set(1, 0, x2.multiply(Matrix::transpose(xsum)).get(0, 0));
    a.set(1, 1, xsum.multiply(Matrix::transpose(xsum)).get(0, 0));*/
    a.set(0, 0, x2.multiply(x2.transpose()).get(0, 0));
    a.set(0, 1, xsum.multiply(x2.transpose()).get(0, 0));
    a.set(1, 0, x2.multiply(xsum.transpose()).get(0, 0));
    a.set(1, 1, xsum.multiply(xsum.transpose()).get(0, 0));
    // 创建一个矩阵对象，用于存放常数矩阵
    Matrix b(2, 1);
    // 计算常数矩阵，并存放到矩阵中
    /*b.set(0, 0, xy.multiply(Matrix::transpose(x2)).get(0, 0));
    b.set(1, 0, xy.multiply(Matrix::transpose(xsum)).get(0, 0));*/
    b.set(0, 0, xy.multiply(xsum.transpose()).get(0, 0));
    b.set(1, 0, xy.multiply(xsum.transpose()).get(0, 0));
    // 创建一个矩阵对象，用于存放解矩阵
    Matrix c(2, 1);
    // 计算解矩阵，即直线的斜率和截距，并存放到矩阵中
    c = a.inverse().multiply(b);
    // 将解矩阵的元素复制到结果数组中
	cout<<"Well"<<endl;
    result[0] = c.get(0, 0); // 斜率
    result[1] = c.get(1, 0); // 截距
    // 返回成功的标志
    return true;
}

int main(){
	int N;
	cin>>N;
	double **data=(double **)(malloc(N*sizeof(double*)));
	double **tmp=data;
	for(int i=0;i<N;i++){
		*tmp=(double *)malloc(2*sizeof(double));
		cin>>**tmp>>*(*(tmp)+1);
		tmp++;
	}
	double *out=(double *)(malloc(sizeof(double)*2));
	linearFit(data,N,out);
	cout<<*out<<" "<<*(out+1)<<endl;
	return 0;
}
