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

  std::sort(S.begin(), S.end(), [&](std::string& a, std::string& b) { return a.size() < b.size(); });

  for (auto& s : S) {
    std::cout << s;
  }
}