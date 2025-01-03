#include <bits/stdc++.h>
using i64 = long long;

int operate(int a, int b, int t) {
  if (t == 1) return a & b;
  if (t == 2) return a | b;
  return a ^ b;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, c;
  std::cin >> n >> c;
  int s0 = 0, s1 = (1 << 30) - 1, m = (1 << 30) - 1;
  for (int i = 0; i < n; ++i) {
    int t, a;
    std::cin >> t >> a;
    s0 = operate(s0, a, t);
    s1 = operate(s1, a, t);
    c = ((c & s1) | (~c & s0));
    std::cout << c << "\n";
  }
}