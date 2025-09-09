#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N;
  std::cin >> N;
  std::vector<char> ans;

  while (N > 0) {
    if (N % 2 == 0) {
      ans.push_back('B');
      N /= 2;
    } else {
      ans.push_back('A');
      N--;
    }
  }

  for (int i = (int)ans.size() - 1; i >= 0; --i) {
    std::cout << ans[i];
  }
}