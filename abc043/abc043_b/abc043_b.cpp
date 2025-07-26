#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  std::vector<int> ans;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      ans.push_back(0);
    } else if (s[i] == '1') {
      ans.push_back(1);
    } else if (s[i] == 'B' && ans.size() > 0) {
      ans.pop_back();
    }
  }

  for (auto i : ans) {
    std::cout << i;
  }
}