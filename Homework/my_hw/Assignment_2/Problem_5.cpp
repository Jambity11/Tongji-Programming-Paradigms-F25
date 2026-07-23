#include <iostream>
#include <cstring>
using std::string;
using std::istream;
using std::ostream;

// 实现高精度大数  实现乘法
class BigInt {
  int *digits_;
  int size_; // 位数
  // 将一个对象重设为长度为len，每一位都是0
  void reset(int len) {
    if (digits_ != nullptr) {
      delete[] digits_;
      digits_ = nullptr;
    }
    size_ = len;
    digits_ = new int[size_];
    memset(digits_, 0, sizeof(int) * size_);
  }
  // 把高位的0舍去
  void trim() {
    while (size_ > 1 && digits_[size_ - 1] == 0) size_ --;
  }
 public:
  BigInt() : digits_(nullptr), size_(0) {}
  // 析构函数，释放空间
  ~BigInt() {
    if (digits_ == nullptr) return ;
    delete[] digits_;
    digits_ = nullptr;
  }
  // 赋值运算符重载，通过字符串的形式赋值
  BigInt& operator=(const string& rhs) {
    size_ = rhs.size();
    if (digits_ != nullptr) {
      delete[] digits_;
      digits_ = nullptr;
    }
    digits_ = new int[size_];
    for (int i = 0; i < size_; i ++) {
      digits_[i] = rhs[size_ - 1 - i] - '0';
    }
    return *this;
  }
  // 重载高精度乘法
  BigInt operator* (const BigInt& rhs) {
    BigInt ret;
    // 开辟理论上不可能超过的长度
    ret.reset(size_ + rhs.size_);
    for (int i = 0; i < size_; i ++) {
      for (int j = 0; j < rhs.size_; j ++) {
        ret.digits_[i + j] += digits_[i] * rhs.digits_[j];
      }
    }
    // 统一进位
    for (int i = 0; i < ret.size_; i ++) {
      if (ret.digits_[i] >= 10) {
        ret.digits_[i + 1] += ret.digits_[i] / 10;
        ret.digits_[i] %= 10; 
      }
    }
    // 舍去高位0
    ret.trim();
    return ret;
  }
  // 重载输入输出运算符
  friend istream& operator>>(istream& lhs, BigInt& rhs) {
    string str;
    lhs >> str;
    rhs = str;
    return lhs;
  }
  friend ostream& operator<<(ostream& lhs, const BigInt& rhs) {
    for (int i = rhs.size_ - 1; i >= 0; i --) {
      lhs << rhs.digits_[i];
    }
    return lhs;
  }
};


int main() {
  BigInt a, b;
  std::cin >> a >> b;
  std::cout << a * b << std::endl;

}