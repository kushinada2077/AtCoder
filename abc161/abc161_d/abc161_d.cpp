#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int k;
  std::cin >> k;
  std::queue<i64> q;
  for (int i = 1; i <= 9; ++i) {
    q.push(i);
  }

  for (int i = 0; i < k - 1; ++i) {
    i64 x = q.front();
    q.pop();
    if (x % 10 != 0) q.push(10 * x + (x % 10 - 1));
    q.push(10 * x + x % 10);
    if (x % 10 != 9) q.push(10 * x + (x % 10 + 1));
  }

  std::cout << q.front() << "\n";
}