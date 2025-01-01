#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, k;
// 맨 위 번호
set<int> card;
// (사이즈, 맨 위 번호)
set<pair<int, int>> siz_list;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  vector<int> P(n), ans(n, -1), nxt(n, -1), siz(n);
  for (int i = 0; i < n; ++i) cin >> P[i];
  for (int i = 0; i < n; ++i) {
    int x = P[i] - 1;
    auto it = card.lower_bound(x);
    if (it != card.end()) {
      int v = *it;
      card.insert(x);
      card.erase(v);
      nxt[x] = v;
      siz_list.erase({siz[v], v});
      siz[x] = siz[v] + 1;
      siz_list.insert({siz[x], x});
    } else {
      card.insert(x);
      siz_list.insert({1, x});
      siz[x] = 1;
    }

    auto itt = prev(siz_list.end());
    while ((*itt).first >= k) {
      auto [sz, st] = *itt;
      int v = st;
      while (v != -1) {
        ans[v] = i + 1;
        v = nxt[v];
      }
      card.erase(st);
      itt = siz_list.erase(itt);
      if (itt == siz_list.end()) break;
      itt = prev(itt);
    }
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << "\n";
}