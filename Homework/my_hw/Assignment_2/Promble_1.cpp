# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string str;
  cin >> str;// 输入非空字符串

  int len = str.size();
  for (int i = 0, j = len - 1; i < j; i ++, j --) {
    if (str[i] < str[j]) {
      str[j] = str[i];
    } else if (str[i] > str[j]) {
      str[i] = str[j];
    } else {
      ;
    }
  }
  cout << str << endl;
}