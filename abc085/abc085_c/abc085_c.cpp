#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, Y, tot = 0;
  std::cin >> N >> Y;
  std::vector<int> M = {10000, 5000, 1000}, ans(3, 0);
  for (int i = 0; i < 3; ++i) {
    ans[2 - i] += Y / M[i];
    Y %= M[i];
    tot += ans[2 - i];
  }

  if (tot > N) {
    for (int i = 0; i < 3; ++i) {
      ans[i] = -1;
    }
  } else if (tot < N) {
    int D = N - tot;
    int x = std::min(ans[2], D / 9);
    ans[2] -= x;
    ans[0] += 10 * x;
    tot += 9 * x;
    D -= 9 * x;

    x = std::min(ans[1], D / 4);
    ans[1] -= x;
    ans[0] += 5 * x;
    tot += 4 * x;
    D -= 4 * x;

    x = std::min(ans[2], D / 1);
    ans[2] -= x;
    ans[1] += 2 * x;
    tot += x;
    D -= x;

    if (D > 0) {
      for (int i = 0; i < 3; ++i) {
        ans[i] = -1;
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    std::cout << ans[2 - i] << " \n"[i == 2];
  }
}