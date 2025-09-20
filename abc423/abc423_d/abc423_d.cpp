#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<i64, i64>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N, K;
  std::cin >> N >> K;

  std::vector<i64> A(N), B(N), C(N), ans(N);
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i] >> B[i] >> C[i];
  }

  i64 t = 0, cur = 0;
  for (int i = 0; i < N; ++i) {
    while (!pq.empty() && cur + C[i] > K) {
      auto [a, c] = pq.top();
      pq.pop();
      cur -= c;
      t = std::max(t, a);
    }
    ans[i] = std::max(A[i], t);
    cur += C[i];
    t = ans[i];
    pq.push({ans[i] + B[i], C[i]});
  }

  for (int i = 0; i < N; ++i) {
    std::cout << ans[i] << "\n";
  }
}