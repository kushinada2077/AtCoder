#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int N = S.size();
  std::vector<int> U(N + 1), D(N + 1);
  for (int i = 0; i < N; ++i) {
    U[i + 1] += U[i];
    D[i + 1] += D[i];
    U[i + 1] += S[i] == 'U';
    D[i + 1] += S[i] == 'D';
  }

  i64 ans = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'U') {
      ans += N - i - 1;
      if (D[N] - D[i + 1] > 0) {
        ans += 2 * i;
      }
    } else if (S[i] == 'D') {
      ans += i;
      if (U[i] > 0) {
        ans += 2 * (N - i - 1);
      }
    }
  }

  std::cout << ans << "\n";
}