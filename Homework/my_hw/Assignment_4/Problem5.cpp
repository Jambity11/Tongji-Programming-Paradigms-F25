#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

/*
 * Shape基类 - 表示几何形状
 * 提供虚函数clone()用于创建形状的副本
 */
class Shape {
 public:
  /*
   * 虚函数clone() - 返回当前形状的副本
   * 使用智能指针管理内存
   */
  virtual std::unique_ptr<Shape> clone() const = 0;

  /*
   * 虚函数display() - 显示形状信息
   */
  virtual void display() const = 0;

  /*
   * 虚析构函数
   */
  virtual ~Shape() { std::cout << "Shape析构" << std::endl; }
};

/*
 * Circle类 - 圆形
 */
class Circle : public Shape {
 private:
  double radius;  // 半径

 public:
  /*
   * 构造函数
   */
  Circle(double r) : radius(r) {
    std::cout << "Circle构造，半径: " << radius << std::endl;
  }

  /*
   * 重写clone()函数 - 返回Circle副本
   */
  std::unique_ptr<Shape> clone() const override {
    std::cout << "克隆Circle对象" << std::endl;
    return std::make_unique<Circle>(*this);
  }

  /*
   * 重写display()函数
   */
  void display() const override {
    std::cout << "Circle - 半径: " << radius << std::endl;
  }

  /*
   * 获取半径
   */
  double getRadius() const { return radius; }

  /*
   * 析构函数
   */
  ~Circle() { std::cout << "Circle析构，半径: " << radius << std::endl; }
};

/*
 * Rectangle类 - 矩形
 */
class Rectangle : public Shape {
 private:
  double width;   // 宽度
  double height;  // 高度

 public:
  /*
   * 构造函数
   */
  Rectangle(double w, double h) : width(w), height(h) {
    std::cout << "Rectangle构造，宽: " << width << ", 高: " << height
              << std::endl;
  }

  /*
   * 重写clone()函数 - 返回Rectangle副本
   */
  std::unique_ptr<Shape> clone() const override {
    std::cout << "克隆Rectangle对象" << std::endl;
    return std::make_unique<Rectangle>(*this);
  }

  /*
   * 重写display()函数
   */
  void display() const override {
    std::cout << "Rectangle - 宽: " << width << ", 高: " << height << std::endl;
  }

  /*
   * 获取宽度和高度
   */
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  /*
   * 析构函数
   */
  ~Rectangle() {
    std::cout << "Rectangle析构，宽: " << width << ", 高: " << height
              << std::endl;
  }
};

int main() {
  std::cout << "=== 创建形状对象 ===" << std::endl;

  // 创建形状向量，使用智能指针
  std::vector<std::unique_ptr<Shape>> shapes;

  // 添加Circle和Rectangle对象
  shapes.push_back(std::make_unique<Circle>(5.0));
  shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));

  std::cout << "\n=== 显示原始形状 ===" << std::endl;
  for (const auto& shape : shapes) {
    shape->display();
  }

  std::cout << "\n=== 克隆形状对象 ===" << std::endl;
  std::vector<std::unique_ptr<Shape>> clonedShapes;

  for (const auto& shape : shapes) {
    // 调用clone()创建副本
    clonedShapes.push_back(shape->clone());
  }

  std::cout << "\n=== 显示克隆后的形状 ===" << std::endl;
  for (const auto& shape : clonedShapes) {
    shape->display();
  }

  std::cout << "\n=== 验证克隆对象的类型 ===" << std::endl;

  // 方法1: 使用typeid验证类型
  std::cout << "使用typeid验证:" << std::endl;
  for (size_t i = 0; i < clonedShapes.size(); ++i) {
    std::cout << "对象 " << i << " 的类型: " << typeid(*clonedShapes[i]).name()
              << std::endl;

    if (typeid(*clonedShapes[i]) == typeid(Circle)) {
      std::cout << "  -> 确认为Circle类型" << std::endl;
    } else if (typeid(*clonedShapes[i]) == typeid(Rectangle)) {
      std::cout << "  -> 确认为Rectangle类型" << std::endl;
    }
  }

  // 方法2: 使用dynamic_cast验证类型
  std::cout << "\n使用dynamic_cast验证:" << std::endl;
  for (size_t i = 0; i < clonedShapes.size(); ++i) {
    Circle* circlePtr = dynamic_cast<Circle*>(clonedShapes[i].get());
    Rectangle* rectPtr = dynamic_cast<Rectangle*>(clonedShapes[i].get());

    if (circlePtr) {
      std::cout << "对象 " << i << " 是Circle，半径: " << circlePtr->getRadius()
                << std::endl;
    } else if (rectPtr) {
      std::cout << "对象 " << i << " 是Rectangle，宽: " << rectPtr->getWidth()
                << ", 高: " << rectPtr->getHeight() << std::endl;
    }
  }

  std::cout << "\n=== 智能指针的优势 ===" << std::endl;
  std::cout << "1. 自动内存管理 - 不需要手动delete，防止内存泄漏" << std::endl;
  std::cout << "2. 异常安全 - 即使发生异常，也能正确释放内存" << std::endl;
  std::cout << "3. 所有权明确 - unique_ptr表示独占所有权，防止多次释放"
            << std::endl;
  std::cout << "4. 移动语义 - unique_ptr支持移动但不支持拷贝，避免意外共享"
            << std::endl;
  std::cout << "5. 代码更简洁 - 减少样板代码，提高可读性" << std::endl;
  std::cout << "6. 与容器配合好 - 可以安全地存储在STL容器中" << std::endl;

  std::cout << "\n=== 程序结束，智能指针自动释放内存 ===" << std::endl;

  return 0;
}