#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<i64> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  std::map<i64, int> h;
  h[0] = 1;
  i64 sum = 0, ans = 0;
  for (int i = 0; i < N; ++i) {
    sum += A[i];
    ans += h[sum];
    h[sum]++;
  }

  std::cout << ans << "\n";
}