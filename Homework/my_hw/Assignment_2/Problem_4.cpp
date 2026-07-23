#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

// base P to base 10
int basePToDecimal(int num, int P) {
  int weight = 1, ans = 0;
  for ( ; num; num /= 10) {
    ans += (num % 10) * weight;
    weight *= P;
  }
  return ans;
}

vector<int> decimalToBaseM (int num, int M) {
  vector<int> ans;
  for ( ; num; num /= M) {
    ans.push_back(num % M);
  }
  return ans;
}

void outPut(const vector<int>& num) {
  for (auto& x : num) {
    if (x >= 10) cout << (char)('A' + x - 10);
    else cout << x;
  } 
  cout << std::endl;
}

int main() {
  int p, m, num;
  cin >> p >> m >> num;
  int dec = basePToDecimal(num, p);
  vector<int> ans = decimalToBaseM(dec, m);
  outPut(ans);

}