/*
Create a vector <float> and put 25 numbers into it. 
Then square each number and put the result back into the same location in the vector. 
Display the vector before and after the multiplications.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // 创建容量为25个浮点数的vector，并输入
  vector<float> nums(25);
  for (int i = 0; i < 25; i ++) {
    cout << "输入第" << i + 1 << "个数：";  
    cin >> nums[i];
  }
  // 显示原始 vector
  cout << "------------------------------" << endl;
  cout << "vector before multiplication: " << endl;
  for (int i = 0; i < 25; i ++) {
    cout << nums[i] << ' ';
    nums[i] = nums[i] * nums[i];
  }
  cout << endl;

  cout << "vector after multiplication: " << endl;
  for (int i = 0; i < 25; i ++) {
    cout << nums[i] << ' ';
  }
  cout << endl;
    

  return 0;
}

