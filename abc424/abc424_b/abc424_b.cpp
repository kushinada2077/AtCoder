#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M, K;
  std::cin >> N >> M >> K;
  std::vector chk(N, std::vector<int>(M, 0));
  std::vector<int> ans;
  for (int i = 0; i < K; ++i) {
    int a, b;
    std::cin >> a >> b;
    chk[a - 1][b - 1] = 1;
    if (std::ranges::all_of(chk[a - 1], [&](int x) -> bool { return x == 1; })) {
      ans.push_back(a);
    }
  }

  for (auto i : ans) {
    std::cout << i << " ";
  }
}