#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::string S;
  std::cin >> N >> S;
  int ans = 0;
  for (int i = 1; i < N; ++i) {
    std::vector<bool> cnt(26, false);
    for (int j = 0; j < i; ++j) {
      cnt[S[j] - 'a'] = true;
    }
    int c = 0;
    for (int j = i; j < N; ++j) {
      if (cnt[S[j] - 'a'] == true) {
        c++;
        cnt[S[j] - 'a'] = false;
      }
    }
    ans = std::max(ans, c);
  }
  std::cout << ans << "\n";
}