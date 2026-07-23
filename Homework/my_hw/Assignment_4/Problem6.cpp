#include <cmath>
#include <iostream>
#include <string>

/*
 * Point结构体 - 表示二维坐标点
 */
struct Point {
  int x, y;

  /*
   * 构造函数
   */
  Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

  /*
   * 计算到原点的欧几里得距离
   */
  double dist() const { return std::sqrt(x * x + y * y); }

  /*
   * 重载<运算符 - 比较两个点的距离
   * 距离小的点更小
   */
  bool operator<(const Point& other) const { return dist() < other.dist(); }

  /*
   * 重载==运算符 - 判断两个点距离是否相等
   */
  bool operator==(const Point& other) const {
    return std::abs(dist() - other.dist()) < 1e-9;
  }
};

/*
 * 重载<<运算符 - 输出Point对象
 */
std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << p.x << "," << p.y;
  return os;
}

/*
 * string比较特化 - 字符串长度短的更小
 */
bool isLess(const std::string& a, const std::string& b) {
  return a.length() < b.length();
}

/*
 * 通用比较函数 - 使用<运算符
 */
template <typename T>
bool isLess(const T& a, const T& b) {
  return a < b;
}

/*
 * Point指针比较特化 - 解引用后比较
 */
bool isLess(const Point* a, const Point* b) { return *a < *b; }

/*
 * 通用相等性检查
 */
template <typename T>
bool isEqual(const T& a, const T& b) {
  return !(a < b) && !(b < a);  // 如果a不小于b且b不小于a，则相等
}

/*
 * string相等性特化
 */
bool isEqual(const std::string& a, const std::string& b) {
  return a.length() == b.length();
}

/*
 * Point相等性特化
 */
bool isEqual(const Point& a, const Point& b) { return a == b; }

/*
 * Point指针相等性特化
 */
bool isEqual(const Point* a, const Point* b) { return *a == *b; }

/*
 * findMin函数模板 - 找出三个值中的最小值
 * 如果有多个最小值，返回最后一个
 */
template <typename T>
T findMin(const T& a, const T& b, const T& c) {
  T minVal = a;

  // 检查b是否更小，或者与当前最小值相等（则更新为b，保证返回最后一个）
  if (isLess(b, minVal)) {
    minVal = b;
  } else if (isEqual(b, minVal)) {
    minVal = b;  // 相等时更新，确保返回最后出现的
  }

  // 检查c是否更小，或者与当前最小值相等
  if (isLess(c, minVal)) {
    minVal = c;
  } else if (isEqual(c, minVal)) {
    minVal = c;  // 相等时更新，确保返回最后出现的
  }

  return minVal;
}

int main() {
  std::cout << "=== 测试1: int类型 ===" << std::endl;
  int i1 = 1, i2 = 2, i3 = 3;
  std::cout << "输入: " << i1 << " " << i2 << " " << i3 << std::endl;
  std::cout << "最小值: " << findMin(i1, i2, i3) << std::endl;
  std::cout << std::endl;

  std::cout << "=== 测试2: double类型 ===" << std::endl;
  double d1 = 1.3, d2 = 2.4, d3 = 0.6;
  std::cout << "输入: " << d1 << " " << d2 << " " << d3 << std::endl;
  std::cout << "最小值: " << findMin(d1, d2, d3) << std::endl;
  std::cout << std::endl;

  std::cout << "=== 测试3: char类型 ===" << std::endl;
  char c1 = 'a', c2 = 'b', c3 = 'c';
  std::cout << "输入: " << c1 << " " << c2 << " " << c3 << std::endl;
  std::cout << "最小值: " << findMin(c1, c2, c3) << std::endl;
  std::cout << std::endl;

  std::cout << "=== 测试4: string类型（比较长度） ===" << std::endl;
  std::string s1 = "hello", s2 = "hi", s3 = "he";
  std::cout << "输入: " << s1 << " " << s2 << " " << s3 << std::endl;
  std::cout << "最小值: " << findMin(s1, s2, s3) << std::endl;
  std::cout << std::endl;

  std::cout << "=== 测试5: Point类型（比较到原点距离） ===" << std::endl;
  Point p1(1, 2), p2(3, 4), p3(0, 1);
  std::cout << "输入: " << p1 << " " << p2 << " " << p3 << std::endl;
  std::cout << "距离: " << p1.dist() << " " << p2.dist() << " " << p3.dist()
            << std::endl;
  std::cout << "最小值: " << findMin(p1, p2, p3) << std::endl;
  std::cout << std::endl;

  std::cout << "=== 测试6: Point*类型（指针解引用后比较） ===" << std::endl;
  Point p4(1, 2), p5(0, 1), p6(3, 4);
  Point* pp1 = &p4;
  Point* pp2 = &p5;
  Point* pp3 = &p6;
  std::cout << "输入: " << *pp1 << " " << *pp2 << " " << *pp3 << std::endl;
  std::cout << "距离: " << pp1->dist() << " " << pp2->dist() << " "
            << pp3->dist() << std::endl;
  std::cout << "最小值: " << *findMin(pp1, pp2, pp3) << std::endl;
  std::cout << std::endl;

  std::cout << "=== 测试7: 多个相同最小值（返回最后一个） ===" << std::endl;
  int i4 = 5, i5 = 3, i6 = 3;
  std::cout << "输入: " << i4 << " " << i5 << " " << i6 << std::endl;
  int result = findMin(i4, i5, i6);
  std::cout << "最小值: " << result << " (应该返回最后一个3)" << std::endl;

  // 验证返回的是最后一个
  if (&result == &i6) {
    std::cout << "确认：返回的是第三个参数" << std::endl;
  }
  std::cout << std::endl;

  std::cout << "=== 测试8: Point类型多个相同最小值 ===" << std::endl;
  Point p7(1, 0), p8(0, 1), p9(1, 0);  // p7和p9距离相同
  std::cout << "输入: " << p7 << " " << p8 << " " << p9 << std::endl;
  std::cout << "距离: " << p7.dist() << " " << p8.dist() << " " << p9.dist()
            << std::endl;
  Point resultPoint = findMin(p7, p8, p9);
  std::cout << "最小值: " << resultPoint << " (应该返回最后一个1,0)"
            << std::endl;
  std::cout << std::endl;

  return 0;
}