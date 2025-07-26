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
    while (N - tot >= 9 && ans[2] > 0) {
      ans[2]--;
      ans[0] += 10;
      tot += 9;
    }
    while (N - tot >= 4 && ans[1] > 0) {
      ans[1]--;
      ans[0] += 5;
      tot += 4;
    }
    while (N - tot >= 1 && ans[2] > 0) {
      ans[2]--;
      ans[1] += 2;
      tot += 1;
    }

    if (N != tot) {
      for (int i = 0; i < 3; ++i) {
        ans[i] = -1;
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    std::cout << ans[2 - i] << " \n"[i == 2];
  }
}