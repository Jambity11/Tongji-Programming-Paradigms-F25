# include <iostream>
# include <cassert>
const int kNumOfVowels = 5;
const int kNumOfConsonants = 21;

// n^m
int myPow(int n, int m) {
  int ans = 1;
  while (m --) {
    ans *= n;
  }
  return ans;
}

int numOfPosLuckyStr(int n) {
  int num_of_vowels = n / 2 + n % 2;
  int num_of_cons = n / 2;
  return myPow(kNumOfVowels, num_of_vowels) * myPow(kNumOfConsonants, num_of_cons);

}

int main() {
  // 0 1 0 1 0 1 0 1 0 1 
  // 1 2 3 4 5 6 7 8 9 10 11 12 13
  int n;
  std::cin >> n;

  std::cout << numOfPosLuckyStr(n) << std::endl;

}