#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S, T;
  std::cin >> S >> T;
  std::set<char> TT(T.begin(), T.end());
  int N = (int)S.size();
  auto ans = [&]() -> bool {
    for (int i = 1; i < N; ++i) {
      if ('A' <= S[i] && S[i] <= 'Z' && TT.contains(S[i - 1]) == false) return false;
    }
    return true;
  }();

  if (ans == true) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}