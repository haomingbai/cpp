#include <iostream>
#include <string>
using namespace std;

// 定义替换函数
void str_replace(string &str, string olds, string news) {
  // 获取olds和news的长度
  int len1 = olds.length();
  int len2 = news.length();
  // 遍历str，找到所有出现olds的位置
  for (int i = 0; i < str.length(); i++) {
    // 如果当前位置开始的子串和olds相同
    if (str.substr(i, len1) == olds) {
      // 用news替换olds
      str.replace(i, len1, news);
      // 跳过news的长度，继续查找
      i += len2;
    }
  }
}

int main() {
  // 定义三个字符串变量
  string str, olds, news;
  // 读入输入
  getline(cin,str);
  cin >> olds >> news;
  // 调用替换函数
  str_replace(str, olds, news);
  // 输出结果
  cout << str << endl;
  return 0;
}
