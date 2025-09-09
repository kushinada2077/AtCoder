#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K;
  std::string S;
  std::cin >> N >> K >> S;
  std::string T(N, 'x');
  for (int i = 0; i < N; ++i) {
    if (K > 0 && S[i] == 'o') {
      K--;
      T[i] = 'o';
    }
  }
  std::cout << T << "\n";
}