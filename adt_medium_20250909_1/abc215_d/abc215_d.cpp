#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(N);
  std::set<int> S;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    if (A[i] != 1) {
      S.insert(A[i]);
      for (int j = 2; j * j <= A[i]; ++j) {
        if (A[i] % j == 0) {
          S.insert(j);
          S.insert(A[i] / j);
        }
      }
    }
  }

  std::vector<int> ans;
  for (int i = 1; i <= M; ++i) {
    bool chk = true;
    for (int j = 1; j * j <= i; ++j) {
      if ((i % j == 0 && (S.contains(i / j) || (j != 1 && S.contains(j))))) {
        chk = false;
        break;
      }
    }
    if (chk) ans.push_back(i);
  }

  std::cout << ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); ++i) {
    std::cout << ans[i] << "\n";
  }
}