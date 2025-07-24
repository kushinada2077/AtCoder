#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S, K = "keyence";
  std::cin >> S;
  int N = S.size(), M = K.size();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::string s = S.substr(0, i) + S.substr(j);
      if (s == K) {
        std::cout << "YES\n";
        return 0;
      }
    }
  }
  std::cout << "NO\n";
}