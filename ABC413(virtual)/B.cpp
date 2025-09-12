#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<std::string> S(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> S[i];
  }
  std::set<std::string> C;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j)
        continue;
      C.insert(S[i] + S[j]);
    }
  }
  std::cout << C.size() << "\n";
}