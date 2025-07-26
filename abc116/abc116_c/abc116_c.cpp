#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> h(N), a(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> h[i];
  }

  int ans = 0;
  while (true) {
    int st = -1, cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (h[i] != a[i]) {
        if (st == -1) st = i;
        a[i]++;
        cnt++;
      } else if (st != -1 && h[i] == a[i]) {
        ans++;
        st = -1;
      }
    }

    if (st != -1) ans++;
    if (cnt == 0) break;
  }
  std::cout << ans << "\n";
}