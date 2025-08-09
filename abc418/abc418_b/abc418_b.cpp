#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int N = S.size();
  double ans = 0;
  for (int i = 0; i < N - 2; ++i) {
    for (int j = i + 2; j < N; ++j) {
      if (S[i] == 't' && S[j] == 't') {
        int cnt = 0;
        for (int k = i; k <= j; ++k) {
          cnt += S[k] == 't';
        }
        ans = std::max(ans, (double)(cnt - 2) / (j - i - (double)1));
      }
    }
  }
  std::cout << std::fixed << std::setprecision(10);
  std::cout << ans << "\n";
}