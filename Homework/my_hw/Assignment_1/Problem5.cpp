/*
Given an array prices, 
where the i-th element prices[i] represents the price of a given stock on day i.
You are only allowed to choose one day to buy this stock 
and choose a different day in the future to sell it.
Design an algorithm to calculate the maximum profit you can achieve.
Return the maximum profit you can obtain from this transaction. 
If no profit can be achieved, return 0.
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>

using namespace std;
/*
7 1 5 3 6 4
从第一个元素开始，遍历每个元素
代表在该天抛出
要找：在该天之前，最低的售价
维护利润最大值
（若利润小于0，则令利润为0，还不如不交易）

*/
int main() {
  int n;
  cin >> n;
  vector<int> prices(n);
  for (int i = 0; i < n; i ++) {
    cin >> prices[i];
  }
  
  //-----------------以上为输入处理-------------------
  // 以下为算法：
  /*
  prices 存放 以下标为天数 
  用栈存放 天 
  1. 遍历每一天，作为抛出股票的那天
  2. 每遍历一天，就把这一天的价格和栈顶的天数的价格比较，
  如果这一天的价格比栈顶那一天的价格低，则出栈，直到栈为空或栈顶的天数的价格比该天小
  */
// 7 1 5 3 6 4
  deque<int> days;
  int profit = 0;
  for (int i = 0; i < prices.size(); i ++) {
    while (!days.empty() && prices[days.back()] >= prices[i]) days.pop_back();
    if (!days.empty()) profit = max(profit, prices[i] - prices[days.front()]);
    days.push_back(i);
  }
  cout << profit << endl;

  return 0;
}
