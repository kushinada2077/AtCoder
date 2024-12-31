#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n;
map<int, multiset<int>> pe;
map<int, vector<pair<int, int>>> ipe;
set<pair<int, int>> ans;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int m, i = 0; i < n; ++i) {
    cin >> m;
    for (int p, e, j = 0; j < m; ++j) {
      cin >> p >> e;
      pe[p].insert(e);
      ipe[i].push_back({p, e});
    }
  }

  for (int i = 0; i < n; ++i) {
    auto solve = [&](int i) -> void {
      for (auto [p, e] : ipe[i]) {
        if (pe[p].size() == 1) {
          ans.insert({p, e});
          return;
        } else {
          auto back = --pe[p].end();
          auto back_pre = --(--pe[p].end());
          if (*back == e && *back_pre != *back) {
            ans.insert({p, e});
            return;
          }
        }
      }

      ans.insert({0, 0});
    };

    solve(i);
  }

  cout << ans.size() << "\n";
}