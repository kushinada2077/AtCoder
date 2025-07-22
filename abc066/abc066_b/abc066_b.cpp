#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int N = S.size();

  for (int i = 2; i < N - 1; i += 2) {
    std::string SS = S.substr(0, N - i);
    int mid = SS.size() / 2;
    bool ok = true;
    for (int j = 0; j < mid; ++j) {
      ok &= SS[j] == SS[mid + j];
    }
    if (ok == true) {
      std::cout << SS.size() << "\n";
      break;
    }
  }
}