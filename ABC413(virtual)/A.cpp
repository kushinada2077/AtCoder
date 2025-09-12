#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    sum += x;
  }

  if (sum > M) {
    std::cout << "No\n";
  } else {
    std::cout << "Yes\n";
  }
}