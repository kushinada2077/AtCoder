#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int K;
  std::string s;
  std::cin >> s >> K;
  K--;
  std::vector<std::string> a;
  for (int i = 0; i < s.size(); ++i) {
    std::string t = "";
    for (int j = i; j < s.size() && j < i + 5; ++j) {
      t += s[j];
      a.push_back(t);
    }
  }

  sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());
  std::cout << a[K] << "\n";
}