#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::map<int, int> M;
  for (int i = 0; i < N; ++i) {
    int a;
    std::cin >> a;
    M[a - 1]++;
    M[a]++;
    M[a + 1]++;
  }
  int ans = 0;
  for (auto [k, v] : M) {
    ans = std::max(ans, v);
  }
  std::cout << ans << "\n";
}