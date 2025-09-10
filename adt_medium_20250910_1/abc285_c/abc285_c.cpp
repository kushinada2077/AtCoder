#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int N = (int)S.size();
  i64 ans = 0, offset = 1;

  for (int i = N - 1; i >= 0; --i, offset *= 26) {
    ans += (S[i] - 'A' + 1) * offset;
  }

  std::cout << ans << "\n";
}