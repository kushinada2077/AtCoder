#include <bits/stdc++.h>
using i64 = long long;

bool dfs(int u, int dest, std::string& S, std::vector<int>& A, std::vector<bool>& vis) {
  if (vis[u] == true || (u > 0 && S[u - 1] == '1')) {
    return false;
  }
  if (u == dest) {
    return true;
  }
  vis[u] = true;
  bool ret = false;
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] == 0) {
      A[i] = 1;
      int v = u + (1 << i);
      ret |= dfs(v, dest, S, A, vis);
      A[i] = 0;
    }
  }
  return ret;
}
void solve() {
  int N;
  std::string S;
  std::cin >> N >> S;
  std::vector<bool> vis((1 << N) + 1);
  std::vector<int> A(N);
  bool ans = dfs(0, (1 << N) - 1, S, A, vis);
  std::string res[] = {"No", "Yes"};
  std::cout << res[ans] << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}