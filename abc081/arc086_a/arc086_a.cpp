#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K, num = 0;
  std::cin >> N >> K;
  std::vector<int> A(N), cnt(N + 1, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    if (cnt[A[i]] == 0) num++;
    cnt[A[i]]++;
  }
  std::vector<int> P;
  for (int i = 1; i <= N; ++i) {
    if (cnt[i] > 0) {
      P.push_back(cnt[i]);
    }
  }
  sort(P.begin(), P.end());
  int ans = 0;
  for (int i = K; i < num; ++i) {
    if (i - K < P.size()) ans += P[i - K];
  }
  std::cout << ans << "\n";
}