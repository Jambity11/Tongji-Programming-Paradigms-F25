/*
Create two functions, 
one that takes a string* and one that takes a string&. 
Each of these functions should modify the outside string object in its own unique way. 
In main(), create and initialize a string object, print it, 
then pass it to each of the two functions, printing the results.
*/
#include <iostream>

using namespace std;

// 将字符串整体变大写
// 传入参数：string*
string* ToUpper(string* p_str) {
  if (p_str == nullptr) return nullptr; // 防止传入空指针
  else {
    for (int i = 0; i < p_str->length(); i ++) {
      if ('a' <= (*p_str)[i] && (*p_str)[i] <= 'z') {
        (*p_str)[i] += 'A' - 'a';
      }
    }
    return p_str;
  }
}

// 将字符串整体变成小写
// 传入参数：string&
string ToLower(string& str) {
  for (int i = 0; i < str.length(); i ++) {
    if ('A' <= str[i] && str[i] <= 'Z') {
      str[i] += 'a' - 'A';
    }
  }
  return str;
}

int main() {
  string str = "TongjiUniversity";
  string* p_str1 = &str;
  string str2 = "TongjiUniversity";
  cout << "Initialization: " << str << endl;
  cout << "ToUpper(传址): " << *ToUpper(p_str1) << endl;
  cout << "ToLower(引用): " << ToLower(str2) << endl;
  return 0;
}



