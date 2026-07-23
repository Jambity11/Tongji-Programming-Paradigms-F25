/*
Create a struct that holds two string objects and one int. 
Use a typedef for the struct name. 
Create an instance of the struct, 
initialize all three values in your instance, and print them out. 
Take the address of your instance and assign it to a pointer to your struct type. 
Change the three values in your instance and print them out, all using the pointer.
*/

#include <iostream>

using namespace std;

struct MyStruct {
  string str1;
  string str2;
  int num;
};

typedef MyStruct MyData;

int main() {
  MyData mydata{"string1", "string2", 666};
  cout << "Before Change:" << endl;
  cout << "str1:" << mydata.str1 << endl;
  cout << "str2:" << mydata.str2 << endl;
  cout << "num:" << mydata.num << endl;
  cout << "-----------------------" << endl;
  MyData* ptr_mydata = &mydata;
  ptr_mydata->str1 = "Hello";
  ptr_mydata->str2 = "World";
  ptr_mydata->num = 999;
    cout << "After Change:" << endl;
  cout << "str1:" << mydata.str1 << endl;
  cout << "str2:" << mydata.str2 << endl;
  cout << "num:" << mydata.num << endl;


  return 0;
}