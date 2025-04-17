#include <bits/stdc++.h>
using i64 = long long;

void solve(std::string& S, std::vector<bool>& c, int k, i64& ans) {
  if (k + 1 == S.size()) {
    i64 tot = 0, cur = 0;
    for (int i = 0; i < S.size(); ++i) {
      cur *= 10;
      cur += S[i] - '0';
      if (i + 1 != S.size() && c[i] == true) {
        tot += cur;
        cur = 0;
      }
    }
    tot += cur;
    ans += tot;
    return;
  }

  solve(S, c, k + 1, ans);
  c[k] = true;
  solve(S, c, k + 1, ans);
  c[k] = false;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  i64 ans = 0;
  std::vector<bool> c(S.size());
  solve(S, c, 0, ans);
  std::cout << ans << "\n";
}