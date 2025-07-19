#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int cnt = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == '#') {
      cnt++;
      std::cout << i + 1 << ",\n"[cnt - 1];
      if (cnt == 2) {
        cnt = 0;
      }
    }
  }
}