#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::string s, t;
  std::cin >> N >> s >> t;

  int common = 0;
  for (int i = 0; i < N; ++i) {
    int cnt = 0;
    for (int j = i; j < N; ++j) {
      if (s[j] != t[j - i]) break;
      cnt++;
    }
    common = std::max(common, cnt);
  }

  std::cout << 2 * N - common << "\n";
}