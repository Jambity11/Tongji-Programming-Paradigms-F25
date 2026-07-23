#include <iostream>
#include <chrono>

/*
 * Processor基类
 * 包含一个虚函数process()和一个非虚函数compute()
 */
class Processor {
public:
    /*
     * 虚函数 - 可以被派生类重写
     */
    virtual void process() {
        // 简单的计算操作
        volatile int result = 0;
        for (int i = 0; i < 100; ++i) {
            result += i;
        }
    }

    /*
     * 非虚函数 - 派生类可以隐藏但不是重写
     */
    void compute() {
        // 简单的计算操作
        volatile int result = 0;
        for (int i = 0; i < 100; ++i) {
            result += i;
        }
    }

    virtual ~Processor() {}
};

/*
 * AdvancedProcessor派生类
 * 重写虚函数process()，隐藏非虚函数compute()
 */
class AdvancedProcessor : public Processor {
public:
    /*
     * 重写虚函数process()
     */
    void process() override {
        // 简单的计算操作
        volatile int result = 0;
        for (int i = 0; i < 100; ++i) {
            result += i;
        }
    }

    /*
     * 隐藏基类的compute()函数
     */
    void compute() {
        // 简单的计算操作
        volatile int result = 0;
        for (int i = 0; i < 100; ++i) {
            result += i;
        }
    }
};

int main() {
    // 创建AdvancedProcessor对象
    AdvancedProcessor advProc;
    
    // 上转型为基类指针
    Processor* basePtr = &advProc;

    const int iterations = 10000000;  // 调用次数

    // 测试虚函数process()的执行时间
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        basePtr->process();  // 通过基类指针调用虚函数
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto virtualDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // 测试非虚函数compute()的执行时间
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        basePtr->compute();  // 通过基类指针调用非虚函数
    }
    end = std::chrono::high_resolution_clock::now();
    auto nonVirtualDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // 输出结果
    std::cout << "=== 性能测试结果 (调用次数: " << iterations << ") ===" << std::endl;
    std::cout << "虚函数 process() 总时间: " << virtualDuration.count() << " 微秒" << std::endl;
    std::cout << "非虚函数 compute() 总时间: " << nonVirtualDuration.count() << " 微秒" << std::endl;
    
    double avgVirtual = static_cast<double>(virtualDuration.count()) / iterations;
    double avgNonVirtual = static_cast<double>(nonVirtualDuration.count()) / iterations;
    
    std::cout << "\n平均每次调用时间:" << std::endl;
    std::cout << "虚函数: " << avgVirtual << " 微秒" << std::endl;
    std::cout << "非虚函数: " << avgNonVirtual << " 微秒" << std::endl;
    
    double difference = avgVirtual - avgNonVirtual;
    double percentage = (difference / avgNonVirtual) * 100;
    
    std::cout << "\n时间差异: " << difference << " 微秒" << std::endl;
    std::cout << "虚函数比非虚函数慢约 " << percentage << "%" << std::endl;
    
    std::cout << "\n分析:" << std::endl;
    std::cout << "- 虚函数通过虚函数表(vtable)进行间接调用，需要额外的查表开销" << std::endl;
    std::cout << "- 非虚函数是直接调用，编译器可以进行更多优化" << std::endl;
    std::cout << "- 在大量调用的情况下，虚函数的开销会累积" << std::endl;

    return 0;
}