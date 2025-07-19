#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int N = S.size();
  i64 ans = 0, c = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (S[i] == 'B') {
      ans += c;
    } else {
      c += 'W' == S[i];
    }
  }

  std::cout << ans << "\n";
}