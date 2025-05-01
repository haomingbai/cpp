#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string add(string a, string b) {
    string res;
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        int x = i < a.size() ? digits.find(a[i]) : 0;
        int y = i < b.size() ? digits.find(b[i]) : 0;
        int sum = x + y + carry;
        carry = sum / 36;
        res.push_back(digits[sum % 36]);
    }
    if (carry) {
        res.push_back(digits[carry]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}

