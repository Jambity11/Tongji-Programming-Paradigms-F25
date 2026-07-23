#include <iostream>
#include <vector>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * 增量枚举函数模板 - 使用滑动窗口遍历所有满足条件的区间
 * 
 * @tparam M 匹配函数类型,判断当前区间是否满足条件
 * @tparam I 插入函数类型,向窗口中插入新元素
 * @tparam R 移除函数类型,从窗口中移除元素
 * @tparam U 更新函数类型,处理满足条件的区间
 * @param s 起始索引
 * @param e 结束索引
 * @param match 匹配函数,接受(left, right)参数,返回bool表示区间是否满足条件
 * @param insert 插入函数,接受(left, right)参数,将nums[right]加入窗口
 * @param remove 移除函数,接受(left, right)参数,将nums[left]移出窗口
 * @param update 更新函数,接受(left, right)参数,处理满足条件的区间
 */
template<typename M, typename I, typename R, typename U>
void increase_enumerate(int s, int e,
                        const M& match,
                        const I& insert,
                        const R& remove,
                        const U& update) {
  // 双指针滑动窗口
  for (int l = s, r = s; l <= e; ) {
    // 扩展右边界直到满足match条件或到达边界
    while (l == r || (r <= e && !match(l, r - 1))) insert(l, r++);
    
    // 处理当前满足条件的窗口
    if (match(l, r - 1)) update(l, r - 2);
    else update(l, r - 1);
    
    // 收缩左边界
    remove(l++, r);
  }
}


/**
 * 主函数 - 判断数组中是否存在长度为k的子数组包含重复元素
 * 
 * 问题: 给定数组nums和整数k,判断是否存在长度为k的连续子数组包含重复元素
 * 方法: 使用滑动窗口+哈希表统计窗口内元素频率
 * 时间复杂度: O(n) - 每个元素最多被访问两次
 * 空间复杂度: O(k) - 哈希表最多存储k个不同元素
 */
int main() {
  int n, k;
  cout << "请输入数组大小：";
  cin >> n;
  vector<int> nums(n);
  cout << "请依次输入数组元素" << endl;
  for (auto& num : nums) cin >> num;
  cin >> k;
  
  // 哈希表统计窗口内每个元素的出现次数
  std::unordered_map<int, int> count;
  bool has_duplicate = false;
  
  increase_enumerate(0, n - 1,
    // match函数: 检查窗口长度是否达到k
    [&](int l, int r) {
      return r - l == k;
    },
    // insert函数: 将新元素加入窗口并更新计数
    [&](int l, int r) {
      if (count.find(nums[r]) == count.end()) {
        count[nums[r]] = 1;
      } else {
        count[nums[r]] ++;
        // 如果窗口长度为k且存在重复元素,标记为true
        if (r - l + 1 == k && count[nums[r]] >= 2) {
          has_duplicate = true;
        }
      }
    }, 
    // remove函数: 将左边界元素移出窗口并更新计数
    [&](int l, int r) {
      if (count[nums[l]] == 1) {
        count.erase(nums[l]);
      } else {
        count[nums[l]] --;
      }
    },
    // update函数: 本题中不需要额外处理
    [&](int l, int r) {
      // 空函数,因为检查在insert中完成
    });
    
  cout << (has_duplicate ? "true" : "false") << endl;
}


