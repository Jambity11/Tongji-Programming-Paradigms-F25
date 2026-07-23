#include <iostream>
#include <vector>
#include <cassert>

// 计算将长度 n 拆分成不同长度段后的最大乘积
long long maxProductOfDifferentLengths(int n) {
  assert(n >= 1);
  
  if (n == 1) return 1;
  if (n == 2) return 2;
  if (n == 3) return 3;
  
  std::vector<int> pieces;
  int currentPiece = 2;
  int sum = 0;
  
  // 贪心选择：从 2 开始依次选不同的数
  while (sum + currentPiece * 2 + 1 < n) {
    pieces.push_back(currentPiece);
    sum += currentPiece;
    currentPiece++;
  }
  
  // 将剩余部分加到最后一个数上（保证所有数不同）
  int remaining = n - sum;
  if (remaining > 0) {
    if (!pieces.empty() && remaining == pieces.back()) {
      // 如果剩余值等于最后一个数，则合并到前一个
      pieces.back() += remaining;
    } else {
      pieces.push_back(remaining);
    }
  }
  
  // 计算乘积
  long long product = 1;
  for (int piece : pieces) {
    product *= piece;
  }
  
  return product;
}

int main() {
  int n;
  std::cin >> n;
  
  std::cout << maxProductOfDifferentLengths(n) << std::endl;
  
  return 0;
}