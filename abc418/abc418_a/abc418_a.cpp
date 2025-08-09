#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::string S;
  std::cin >> S;
  if (N >= 3 && S[N - 1] == 'a' && S[N - 2] == 'e' && S[N - 3] == 't') {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}