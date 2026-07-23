#include <iostream>
#include <vector>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * 主函数 - 判断是否存在长度不超过k且某元素出现次数至少为f的子数组
 * 
 * 问题: 给定数组nums和整数k、f,判断是否存在长度 <= k 的连续子数组,
 *       其中某个元素出现至少f次
 * 
 * 方法: 使用滑动窗口+哈希表统计频率,动态维护窗口内最大出现次数
 * 时间复杂度: O(n²) 最坏情况 - remove时需要重新计算max_appear
 * 空间复杂度: O(n) - 哈希表可能存储所有不同元素
 */
int main() {
  int n;
  cout << "请输入数组长度:";
  cin >> n;
  vector<int> nums(n);
  cout << "请依次输入数组元素" << endl;
  
  // 初始化哈希表,统计窗口内每个元素的出现次数
  std::unordered_map<int, int> count;
  for (auto& num : nums) {
    cin >> num;
    count[num] = 0;  // 预先注册所有可能的元素
  }
  
  int k, f;
  cout << "请输入k, f值:";
  cin >> k >> f;
  bool found = false;
  int max_appear = 0;  // 记录窗口内元素的最大出现次数

  // match函数: 检查窗口内是否有元素出现至少f次
  auto match = [&](int l, int r) {
    return max_appear >= f;
  };
  
  // insert函数: 将新元素加入窗口,更新频率和最大出现次数
  auto insert = [&](int l, int r) {
    count[nums[r]] ++;
    max_appear = std::max(max_appear, count[nums[r]]);
  };
  
  // remove函数: 移除左边界元素,必要时重新计算最大出现次数
  auto remove = [&](int l, int r) {
    count[nums[l]] --;
    // 如果移除的元素恰好是最大频率元素,需要重新扫描所有元素
    if (count[nums[l]] + 1 == max_appear) {
      max_appear = 0;
      for (const auto& [num, freq] : count) {
        max_appear = std::max(max_appear, freq);
      }
    }
  };
  
  // update函数: 检查满足条件的窗口长度是否 <= k
  auto update = [&](int l, int r) {
    if (r - l + 1 <= k) found = true;
  };

  // 滑动窗口主循环
  for (int l = 0, r = 0; l < n; ) {
    // 扩展右边界直到满足条件(某元素出现f次)
    while (l == r || (r < n && !match(l, r))) insert(l, r ++);
    
    // 检查当前窗口是否满足长度要求
    if (match(l, r)) update(l, r - 1);
    else if (!match(l, r)) ;  // 到达边界但未满足条件
    
    // 收缩左边界
    remove(l ++, r);
  }
  
  cout << (found ? "true" : "false") << endl;
}