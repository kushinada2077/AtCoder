#include <bits/stdc++.h>
using i64 = long long;

i64 f2(int k, std::vector<int>& digit) {
  if (k == digit.size()) return 1;
  int h = *digit.begin();
  i64 ret = 0;
  for (int i = 0; i < std::min(h, digit[k]); ++i) {
    i64 d = 1;
    for (int j = k + 1; j < digit.size(); ++j) {
      d *= h;
    }
    ret += d;
  }
  if (digit[k] >= h) return ret;

  ret += f2(k + 1, digit);
  return ret;
}
i64 f(i64 n) {
  if (n < 10) return 0;
  std::vector<int> digit;
  i64 ret = 0;
  while (n) {
    digit.push_back(n % 10);
    n /= 10;
  }

  std::reverse(digit.begin(), digit.end());
  int l = digit.size();

  for (int i = 2; i < l; ++i) {
    for (int h = 1; h <= 9; ++h) {
      i64 d = 1;
      for (int j = 0; j < i - 1; ++j) {
        d *= h;
      }
      ret += d;
    }
  }

  for (int h = 1; h < *digit.begin(); ++h) {
    i64 d = 1;
    for (int j = 1; j < l; ++j) {
      d *= h;
    }
    ret += d;
  }

  ret += f2(1, digit);
  return ret;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 l, r;
  std::cin >> l >> r;
  std::cout << f(r) - f(l - 1) << "\n";
}