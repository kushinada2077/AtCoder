#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n), p(n, -1), chk(n + 1);
  int cnt_p = 0, cnt_a = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] != -1) {
      p[i] = a[i];
      if (chk[a[i]] == 0) cnt_p++;
      chk[a[i]] = 1;
    } else cnt_a++;
  }

  if (n - cnt_a == cnt_p) {
    std::cout << "Yes\n";
    int j = 1;
    for (int i = 0; i < n; ++i) {
      if (p[i] == -1) {
        while (chk[j] == 1) j++;
        chk[j] = 1;
        p[i] = j;
      }
      std::cout << p[i] << " ";
    }
  } else {
    std::cout << "No\n";
  }
}