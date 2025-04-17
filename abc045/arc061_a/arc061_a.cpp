#include <bits/stdc++.h>
using i64 = long long;

void solve(std::string& S, int k, i64 tot, i64 cur, i64& ans) {
  if (k == S.size()) {
    ans += tot + cur;
    return;
  }

  solve(S, k + 1, tot + cur, 0, ans);
  solve(S, k + 1, tot, 10 * cur + (S[k] - '0'), ans);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  i64 ans = 0;
  solve(S, 0, 0, 0, ans);
  std::cout << ans << "\n";
}