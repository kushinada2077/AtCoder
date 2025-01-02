#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

map<int, vector<int>> table;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> P(n), ans(n + 1, -1);
  for (auto& i : P) cin >> i;
  for (int i = 0; i < n; ++i) {
    auto it = table.lower_bound(P[i]);
    if (it == table.end()) {
      table[P[i]].push_back(P[i]);
    } else {
      table[P[i]] = std::move(it->second);
      table[P[i]].push_back(P[i]);
      table.erase(it);
    }

    if (table[P[i]].size() == k) {
      for (auto v : table[P[i]]) ans[v] = i + 1;
      table.erase(P[i]);
    }
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << "\n";
}