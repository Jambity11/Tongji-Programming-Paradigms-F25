#include <iostream>
#include <vector>
#include <set>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * 主函数 - 判断是否存在索引距离不超过k且值差不超过t的两个元素
 * 
 * 问题: 给定数组nums和整数k、t,判断是否存在两个不同索引i和j,
 *       满足 abs(i - j) <= k 且 abs(nums[i] - nums[j]) <= t
 * 
 * 方法: 使用有序集合(红黑树)维护大小为k的滑动窗口,利用二分查找快速检查
 * 时间复杂度: O(n log k) - 每次插入/删除/查找都是O(log k)
 * 空间复杂度: O(k) - 窗口最多存储k个元素
 */
int main() {
  int n, k, t;
  cout << "请输入数组大小：";
  cin >> n;
  vector<long long> nums(n);
  cout << "请依次输入数组元素：" << endl;
  for (auto& num : nums) cin >> num;
  cout << "请输入k值：";
  cin >> k;
  cout << "请输入t值：";
  cin >> t;
  
  // 使用set维护滑动窗口内的有序元素
  std::set<long long> window;
  bool found = false;
  
  for (int i = 0; i < n; ++i) {
    // 在窗口中二分查找: 寻找 >= nums[i] - t 的第一个元素
    // 如果该元素 <= nums[i] + t, 则找到了满足条件的配对
    auto it = window.lower_bound(nums[i] - t);
    
    // 检查找到的元素是否在 [nums[i] - t, nums[i] + t] 范围内
    if (it != window.end() && *it <= nums[i] + t) {
      found = true;
      break;
    }
    
    // 将当前元素加入窗口
    window.insert(nums[i]);
    
    // 维护窗口大小不超过k: 移除最早加入的元素
    if (window.size() > k) {
      window.erase(nums[i - k]);
    }
  }
  
  cout << (found ? "true" : "false") << endl;
  return 0;
}