#include <iostream>
#include <string>

/*
 * Author类 - 表示作者
 * 没有默认构造函数，必须提供作者名字
 */
class Author {
 private:
  std::string name;  // 作者名字

 public:
  /*
   * 构造函数
   * authorName: 作者名字
   */
  Author(const std::string& authorName) {
    name = authorName;
    std::cout << "Author构造函数: " << name << std::endl;
  }

  /*
   * 拷贝构造函数
   * other: 要拷贝的Author对象
   */
  Author(const Author& other) {
    name = other.name;
    std::cout << "Author拷贝构造函数: " << name << std::endl;
  }

  /*
   * 再写一个移动构造函数
   */
  Author(Author&& other) noexcept {
    name = std::move(other.name);
    std::cout << "Author移动构造函数: " << name << std::endl;
  }

  /*
   * 赋值运算符
   * other: 要赋值的Author对象
   */
  Author& operator=(const Author& other) {
    if (this != &other) {  // 防止自我赋值
      name = other.name;
      std::cout << "Author赋值运算符: " << name << std::endl;
    }
    return *this;
  }
  // 移动赋值运算符
  Author& operator=(Author&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        std::cout << "Author移动赋值运算符: " << name << std::endl;
    }
    return *this;
  }
  /*
   * 获取作者名字
   */
  std::string getName() const { return name; }

  /*
   * 析构函数
   */
  ~Author() { std::cout << "Author析构函数: " << name << std::endl; }
};

/*
 * Publisher类 - 表示出版社
 * 没有默认构造函数，必须提供出版社名字
 */
class Publisher {
 private:
  std::string name;  // 出版社名字

 public:
  /*
   * 构造函数
   * publisherName: 出版社名字
   */
  Publisher(const std::string& publisherName) {
    name = publisherName;
    std::cout << "Publisher构造函数: " << name << std::endl;
  }

  /*
   * 拷贝构造函数
   * other: 要拷贝的Publisher对象
   */
  Publisher(const Publisher& other) {
    name = other.name;
    std::cout << "Publisher拷贝构造函数: " << name << std::endl;
  }
  /*
   * 移动构造函数
   * other: 要移动的Publisher对象
   */
  Publisher(Publisher&& other) noexcept {
    name = std::move(other.name);
    std::cout << "Publisher移动构造函数: " << name << std::endl;
  }
  /*
   * 赋值运算符
   * other: 要赋值的Publisher对象
   */
  Publisher& operator=(const Publisher& other) {
    if (this != &other) {  // 防止自我赋值
      name = other.name;
      std::cout << "Publisher赋值运算符: " << name << std::endl;
    }
    return *this;
  }
  /*
   * 移动赋值运算符
   */
  Publisher& operator=(Publisher&& other) noexcept {
    if (this != &other) {  // 防止自我赋值
      name = std::move(other.name);
      std::cout << "Publisher移动赋值运算符: " << name << std::endl;
    }
    return *this;
  }
  /*
   * 获取出版社名字
   */
  std::string getName() const { return name; }

  /*
   * 析构函数
   */
  ~Publisher() { std::cout << "Publisher析构函数: " << name << std::endl; }
};

/*
 * Book类 - 表示书籍
 * 继承自Author类，包含Publisher成员对象
 */
class Book : public Author {
 private:
  Publisher publisher;  // 出版社成员对象

 public:
  /*
   * 默认构造函数
   * 使用默认的作者名和出版社名
   */
  Book() : Author("Unknown Author"), publisher("Unknown Publisher") {
    std::cout << "Book默认构造函数" << std::endl;
  }

  /*
   * 带参数的构造函数
   * authorName: 作者名字
   * publisherName: 出版社名字
   */
  Book(const std::string& authorName, const std::string& publisherName)
      : Author(authorName), publisher(publisherName) {
    std::cout << "Book带参数构造函数" << std::endl;
  }

  /*
   * 拷贝构造函数
   * other: 要拷贝的Book对象
   * 注意：需要显式调用基类和成员对象的拷贝构造函数
   */
  Book(const Book& other) : Author(other), publisher(other.publisher) {
    std::cout << "Book拷贝构造函数" << std::endl;
  }
  // 移动构造函数
  Book(Book&& other) noexcept : Author(std::move(other)),  publisher(std::move(other.publisher)) {
    std::cout << "Book移动构造函数" << std::endl;
  }
  /*
   * 赋值运算符
   * other: 要赋值的Book对象
   */
  Book& operator=(const Book& other) {
    if (this != &other) {  // 防止自我赋值
      // 调用基类的赋值运算符
      Author::operator=(other);
      // 调用成员对象的赋值运算符
      publisher = other.publisher;
      std::cout << "Book赋值运算符" << std::endl;
    }
    return *this;
  }
  // 移动赋值函数
  Book& operator=(Book&& other) noexcept {
    if (this != &other) {  // 防止自我赋值
      // 调用基类的赋值运算符
      Author::operator=(std::move(other));
      // 调用成员对象的赋值运算符
      publisher = std::move(other.publisher);
      std::cout << "Book移动赋值运算符" << std::endl;
    }
    return *this;
  }
  /*
   * 打印书籍信息
   */
  void print() const {
    std::cout << "书籍信息 - 作者: " << getName()
              << ", 出版社: " << publisher.getName() << std::endl;
  }

  /*
   * 析构函数
   */
  ~Book() { std::cout << "Book析构函数" << std::endl; }
};

// 主函数 - 测试各个类的功能
int main() {
  std::cout << "=== 测试1: Book默认构造函数 ===" << std::endl;
  Book book1;
  book1.print();
  std::cout << std::endl;

  std::cout << "=== 测试2: Book带参数构造函数 ===" << std::endl;
  Book book2("鲁迅", "人民文学出版社");
  book2.print();
  std::cout << std::endl;

  std::cout << "=== 测试3: Book拷贝构造函数 ===" << std::endl;
  Book book3(book2);
  book3.print();
  std::cout << std::endl;

  std::cout << "=== 测试4: Book赋值运算符 ===" << std::endl;
  Book book4("老舍", "商务印书馆");
  book4.print();
  std::cout << "执行赋值操作..." << std::endl;
  book4 = book2;
  book4.print();
  std::cout << std::endl;

  std::cout << "=== 测试5: 自我赋值 ===" << std::endl;
  book2 = book2;  // 应该不执行任何操作
  book2.print();
  std::cout << std::endl;

  std::cout << "=== 测试6: 连续赋值 ===" << std::endl;
  Book book5("巴金", "新华出版社");
  Book book6("茅盾", "作家出版社");
  book6 = book5 = book2;  // 连续赋值
  book5.print();
  book6.print();
  std::cout << std::endl;

  std::cout << "=== 程序结束，对象开始析构 ===" << std::endl;
  return 0;
}