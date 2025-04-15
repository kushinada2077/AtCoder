#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K;
  std::cin >> N >> K;
  std::string S;
  std::cin >> S;
  int ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    ans += S[i] == S[i + 1];
  }
  int cnt1 = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (S[i] == 'R' && S[i + 1] == 'L') {
      cnt1++;
    }
  }

  ans += 2 * std::min(cnt1, K);
  K -= cnt1;
  if (K > 0 && S[0] == 'L') {
    ans++;
    K--;
  }
  if (K > 0 && S.back() == 'R') {
    ans++;
    K--;
  }

  ans = std::min(ans, N - 1);
  std::cout << ans << "\n";
}