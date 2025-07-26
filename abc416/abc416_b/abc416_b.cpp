#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int N = S.size();
  std::vector<int> seg;
  int l = -1;
  for (int i = 0; i < N; ++i) {
    if (S[i] != '#' && l == -1) {
      l = i;
    }
    if (S[i] == '#' && l != -1) {
      seg.push_back(l);
      l = -1;
    }
  }

  if (l != -1) {
    seg.push_back(l);
  }

  std::string T = S;
  for (auto l : seg) {
    T[l] = 'o';
  }
  std::cout << T << "\n";
}