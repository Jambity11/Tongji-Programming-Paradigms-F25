#include <iomanip>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
/*
 * BankAccount类 - 模拟银行账户系统
 * 包含账户名、余额、账户类型等基本信息
 * 支持存款、取款、显示信息等操作
 */
class BankAccount {
 private:
  string accountName;  // 账户名
  double balance;      // 余额
  string accountType;  // 账户类型：saving或current

 public:
  /*
   * 默认构造函数
   * 初始化账户名为"anonymous"，余额为0.0，类型为"saving"
   */
  BankAccount() {
    accountName = "anonymous";
    balance = 0.0;
    accountType = "saving";
  }

  /*
   * 带参数的构造函数
   * name: 账户名
   * initial: 初始余额，默认为0.0
   * type: 账户类型，默认为"saving"
   */
  BankAccount(string name, double initial = 0.0, string type = "saving") {
    accountName = name;
    balance = (initial >= 0) ? initial : 0.0;  // 确保余额非负
    // 确保类型有效，否则设为默认值
    accountType = (type == "saving" || type == "current") ? type : "saving";
  }

  /*
   * deposit - 存款操作
   * amount: 存款金额
   * 如果金额无效（<=0），则显示错误信息并返回
   */
  void deposit(double amount) {
    if (amount <= 0) {
      cout << "存款金额必须大于0！" << endl;
      return;
    }
    balance += amount;
    cout << "存款成功！金额：" << std::fixed << std::setprecision(2) << amount
         << endl;
  }

  /*
   * withdraw - 取款操作
   * amount: 取款金额
   * 如果余额不足，显示警告信息并返回
   */
  void withdraw(double amount) {
    if (amount <= 0) {
      cout << "取款金额必须大于0！" << endl;
      return;
    }
    if (amount > balance) {
      cout << "警告：余额不足！" << endl;
      cout << "当前余额：" << std::fixed << std::setprecision(2) << balance
           << "，请求取款：" << amount << endl;
      return;
    }
    balance -= amount;
    cout << "取款成功！金额：" << std::fixed << std::setprecision(2) << amount
         << endl;
  }

  /*
   * display - 显示账户详细信息
   * 打印账户名、余额和账户类型
   */
  void display() {
    cout << "----------------------------------------" << endl;
    cout << "账户名：" << accountName << endl;
    cout << "余额：" << std::fixed << std::setprecision(2) << balance << endl;
    cout << "类型：" << accountType << endl;
    cout << "----------------------------------------" << endl;
  }

  /*
   * 重载==运算符
   * 根据账户名判断两个账户是否相等
   */
  bool operator==(const BankAccount& other) const { return this == &other; }

  /*
   * 重载!=运算符
   * 根据账户名判断两个账户是否不等
   */
  bool operator!=(const BankAccount& other) const { return this != &other; }
};

// 主函数 - 测试BankAccount类的各项功能
int main() {
  // 测试1：默认构造函数
  cout << "=== 测试默认构造函数 ===" << endl;
  BankAccount acc1;
  acc1.display();
  cout << endl;

  // 测试2：带参数的构造函数
  cout << "=== 测试带参数构造函数 ===" << endl;
  BankAccount acc2("张三", 1000.0, "saving");
  acc2.display();
  cout << endl;

  // 测试3：存款操作
  cout << "=== 测试存款操作 ===" << endl;
  acc2.deposit(500.0);
  acc2.display();
  cout << endl;

  // 测试4：取款操作（成功情况）
  cout << "=== 测试取款操作（成功） ===" << endl;
  acc2.withdraw(300.0);
  acc2.display();
  cout << endl;

  // 测试5：取款操作（余额不足）
  cout << "=== 测试取款操作（余额不足） ===" << endl;
  acc2.withdraw(2000.0);
  cout << endl;

  // 测试6：运算符重载
  cout << "=== 测试运算符重载 ===" << endl;
  BankAccount acc3("张三", 500.0, "current");
  BankAccount acc4("李四", 800.0, "saving");

  cout << "acc2和acc3账户名是否相同：" << (acc2 == acc3 ? "是" : "否") << endl;
  cout << "acc2和acc4账户名是否相同：" << (acc2 == acc4 ? "是" : "否") << endl;
  cout << "acc2和acc4是否不同：" << (acc2 != acc4 ? "是" : "否") << endl;
  cout << endl;

  // 测试7：多个匿名账户的独立性
  cout << "=== 测试多个匿名账户的独立性 ===" << endl;
  BankAccount anon1, anon2;
  anon1.deposit(100);
  anon2.deposit(200);

  cout << "匿名账户1：" << endl;
  anon1.display();
  cout << "匿名账户2：" << endl;
  anon2.display();

  cout << "两个匿名账户是否被认为相等：" << (anon1 == anon2 ? "是" : "否")
       << endl;

  return 0;
}