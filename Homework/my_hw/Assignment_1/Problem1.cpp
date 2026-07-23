/*
Create a program that counts the occurrence of the word ‘that’ in a file 
(use the string class’ operator ‘==’ to find the word)
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const string target = "that";

int main() {
  string filename;
  cout << "请输入文件名：";
  cin >> filename;

  ifstream file(filename);
  if (!file.is_open()) {
        cout << "无法打开文件: " << filename << endl;
        return 1;
    }
    
  string word;
  int count = 0;
  
  // 逐个读取单词
  while (file >> word) {
      // 使用string类的operator==来比较
      if (word == target) {
          count++;
      }
  }
  
  file.close();
  
  cout << "单词 '" << target << "' 在文件中出现了 " << count << " 次" << endl;
  
  return 0;
}