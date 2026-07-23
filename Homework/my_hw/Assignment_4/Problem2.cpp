#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
 * Vector3D类 - 表示三维浮点向量
 * 支持向量加法、点积、叉积等基本运算
 * 以及运算符重载功能
 */
class Vector3D {
 private:
  float x, y, z;  // 向量的三个分量

 public:
  /*
   * 默认构造函数
   * 从标准输入读取三个浮点数值
   */
  Vector3D() {
    cout << "请输入三个浮点数 (x y z): ";
    cin >> x >> y >> z;
  }

  /*
   * 带参数的构造函数
   * 接受三个浮点数值
   */
  Vector3D(float x_val, float y_val, float z_val) {
    x = x_val;
    y = y_val;
    z = z_val;
  }

  /*
   * 数组构造函数
   * arr: 大小为3的浮点数组
   */
  Vector3D(const float arr[3]) {
    x = arr[0];
    y = arr[1];
    z = arr[2];
  }

  /*
   * add - 向量加法
   * v: 要相加的向量
   * 返回: 两个向量的和
   */
  Vector3D add(const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
  }

  /*
   * dot - 点积运算
   * v: 另一个向量
   * 返回: 两个向量的点积（标量）
   */
  float dot(const Vector3D& v) const { return x * v.x + y * v.y + z * v.z; }

  /*
   * cross - 叉积运算
   * v: 另一个向量
   * 返回: 两个向量的叉积（新向量）
   */
  Vector3D cross(const Vector3D& v) const {
    float cx = y * v.z - z * v.y;
    float cy = z * v.x - x * v.z;
    float cz = x * v.y - y * v.x;
    return Vector3D(cx, cy, cz);
  }

  /*
   * print - 打印向量
   * 格式: (x, y, z)
   */
  void print() const {
    cout << "(" << std::fixed << std::setprecision(2) << x << ", " << y << ", " << z << ")";
  }

  /*
   * 重载+运算符 - 向量加法
   */
  Vector3D operator+(const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
  }

  /*
   * 重载-运算符 - 向量减法
   */
  Vector3D operator-(const Vector3D& v) const {
    return Vector3D(x - v.x, y - v.y, z - v.z);
  }

  /*
   * 重载*运算符 - 标量乘法
   * scalar: 标量值
   */
  Vector3D operator*(float scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
  }

  /*
   * 重载+=运算符 - 向量加法并赋值
   * v: 要加到当前向量的向量
   */
  Vector3D& operator+=(const Vector3D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  /*
   * 重载[]运算符 - 下标访问（非const版本）
   * index: 索引 (0=x, 1=y, 2=z)
   * 返回: 对应分量的引用
   */
  float& operator[](int index) {
    if (index == 0)
      return x;
    else if (index == 1)
      return y;
    else
      return z;
  }

  /*
   * 重载[]运算符 - 下标访问（const版本）
   * index: 索引 (0=x, 1=y, 2=z)
   * 返回: 对应分量的值
   */
  float operator[](int index) const {
    if (index == 0)
      return x;
    else if (index == 1)
      return y;
    else
      return z;
  }
};

// 主函数 - 测试Vector3D类的各项功能
int main() {
  // 测试1：带参数的构造函数
  cout << "=== 测试带参数构造函数 ===" << endl;
  Vector3D v1(1.0, 2.0, 3.0);
  cout << "v1 = ";
  v1.print();
  cout << endl << endl;

  // 测试2：数组构造函数
  cout << "=== 测试数组构造函数 ===" << endl;
  float arr[3] = {4.0, 5.0, 6.0};
  Vector3D v2(arr);
  cout << "v2 = ";
  v2.print();
  cout << endl << endl;

  // 测试3：add函数
  cout << "=== 测试add函数 ===" << endl;
  Vector3D v3 = v1.add(v2);
  cout << "v1.add(v2) = ";
  v3.print();
  cout << endl << endl;

  // 测试4：点积
  cout << "=== 测试点积 ===" << endl;
  float dotProduct = v1.dot(v2);
  cout << "v1.dot(v2) = " << dotProduct << endl << endl;

  // 测试5：叉积
  cout << "=== 测试叉积 ===" << endl;
  Vector3D v4 = v1.cross(v2);
  cout << "v1.cross(v2) = ";
  v4.print();
  cout << endl << endl;

  // 测试6：运算符+
  cout << "=== 测试运算符+ ===" << endl;
  Vector3D v5 = v1 + v2;
  cout << "v1 + v2 = ";
  v5.print();
  cout << endl << endl;

  // 测试7：运算符-
  cout << "=== 测试运算符- ===" << endl;
  Vector3D v6 = v2 - v1;
  cout << "v2 - v1 = ";
  v6.print();
  cout << endl << endl;

  // 测试8：标量乘法
  cout << "=== 测试标量乘法 ===" << endl;
  Vector3D v7 = v1 * 2.5;
  cout << "v1 * 2.5 = ";
  v7.print();
  cout << endl << endl;

  // 测试9：运算符+=
  cout << "=== 测试运算符+= ===" << endl;
  cout << "v1 += v2 之前, v1 = ";
  v1.print();
  cout << endl;
  v1 += v2;
  cout << "v1 += v2 之后, v1 = ";
  v1.print();
  cout << endl << endl;

  // 测试10：下标访问（非const）
  cout << "=== 测试下标访问（修改） ===" << endl;
  Vector3D v8(7.0, 8.0, 9.0);
  cout << "修改前 v8 = ";
  v8.print();
  cout << endl;
  v8[0] = 10.0;
  v8[1] = 11.0;
  v8[2] = 12.0;
  cout << "修改后 v8 = ";
  v8.print();
  cout << endl << endl;

  // 测试11：下标访问（const）
  cout << "=== 测试下标访问（读取） ===" << endl;
  const Vector3D v9(13.0, 14.0, 15.0);
  cout << "v9[0] = " << v9[0] << endl;
  cout << "v9[1] = " << v9[1] << endl;
  cout << "v9[2] = " << v9[2] << endl;
  cout << endl;

  // 测试12：多个向量的独立性
  cout << "=== 测试向量独立性 ===" << endl;
  Vector3D va(1.0, 1.0, 1.0);
  Vector3D vb(2.0, 2.0, 2.0);
  cout << "va = ";
  va.print();
  cout << endl;
  cout << "vb = ";
  vb.print();
  cout << endl;
  va[0] = 100.0;
  cout << "修改va[0]后:" << endl;
  cout << "va = ";
  va.print();
  cout << endl;
  cout << "vb = ";
  vb.print();
  cout << " (保持不变)" << endl;

  return 0;
}