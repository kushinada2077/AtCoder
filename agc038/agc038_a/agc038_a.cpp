#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int H, W, A, B;
  std::cin >> H >> W >> A >> B;
  std::vector ans = std::vector(H, std::vector<int>(W, 0));
  for (int i = 0; i < B; ++i) {
    for (int j = A; j < W; ++j) {
      ans[i][j] = 1;
    }
  }
  for (int i = B; i < H; ++i) {
    for (int j = 0; j < A; ++j) {
      ans[i][j] = 1;
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      std::cout << ans[i][j];
    }
    std::cout << "\n";
  }
}