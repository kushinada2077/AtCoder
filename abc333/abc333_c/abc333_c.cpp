#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<i64> repu = {1};
  for (int i = 0; i < 12; ++i) repu.push_back(repu.back() * 10 + 1);
  std::vector<i64> ans;
  for (int i = 0; i < 12; ++i) {
    for (int j = i; j < 12; ++j) {
      for (int k = j; k < 12; ++k) {
        ans.push_back(repu[i] + repu[j] + repu[k]);
      }
    }
  }

  std::ranges::sort(ans);
  ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
  std::cout << ans[n - 1] << "\n";
}