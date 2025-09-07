#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K;
  std::cin >> N >> K;
  std::vector ans{K};
  for (int i = 0; i < N; ++i) {
    std::vector<int> nxt;
    for (auto x : ans) {
      nxt.push_back(x / 2);
      nxt.push_back(x - x / 2);
    }
    ans = nxt;
  }

  int X = *std::max_element(ans.begin(), ans.end()) - *std::min_element(ans.begin(), ans.end());
  std::cout << X << "\n";
  for (auto i : ans) {
    std::cout << i << " ";
  }
}