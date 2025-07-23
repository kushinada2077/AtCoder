#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::string S;
  std::cin >> N >> S;
  int ans = 0;
  for (int i = 1; i < N; ++i) {
    std::string s1 = S.substr(0, i);
    std::string s2 = S.substr(i);
    std::set<char> A1(s1.begin(), s1.end()), A2(s2.begin(), s2.end());
    int cnt = 0;
    for (auto c : A1) {
      cnt += A2.contains(c);
    }
    ans = std::max(ans, cnt);
  }
  std::cout << ans << "\n";
}