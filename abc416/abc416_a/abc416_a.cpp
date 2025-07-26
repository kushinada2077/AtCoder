#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, L, R;
  std::string S;
  std::cin >> N >> L >> R >> S;
  for (int i = L - 1; i < R; ++i) {
    if (S[i] == 'x') {
      std::cout << "No\n";
      return 0;
    }
  }
  std::cout << "Yes\n";
}