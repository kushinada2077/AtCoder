#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, A, B;
  std::string S;
  std::cin >> N >> A >> B >> S;
  std::cout << S.substr(A, N - A - B) << "\n";
}