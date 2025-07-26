#include <bits/stdc++.h>
using i64 = long long;

int N, K, X;
std::string S[10];
std::vector<int> seq;
std::vector<std::string> ans;
void dfs(int k) {
  if (k == K) {
    std::string res = "";
    for (auto i : seq) {
      res += S[i];
    }
    ans.push_back(res);
    return;
  }

  for (int i = 0; i < N; ++i) {
    seq.push_back(i);
    dfs(k + 1);
    seq.pop_back();
  }
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> N >> K >> X;
  for (int i = 0; i < N; ++i) {
    std::cin >> S[i];
  }

  dfs(0);
  sort(ans.begin(), ans.end());
  std::cout << ans[X - 1] << "\n";
}