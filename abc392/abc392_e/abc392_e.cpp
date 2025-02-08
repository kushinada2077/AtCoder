#include <bits/stdc++.h>
using i64 = long long;

int find(int x, std::vector<int>& p) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x], p);
}
bool same(int a, int b, std::vector<int>& p) { return find(a, p) == find(b, p); }
void merge(int a, int b, std::vector<int>& p) {
  a = find(a, p), b = find(b, p);
  if (a == b) return;
  if (p[a] > p[b]) std::swap(a, b);
  p[a] += p[b];
  p[b] = a;
  return;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, cn = 0;
  std::cin >> n >> m;
  std::vector adj(n + 1, std::vector<std::pair<int, int>>());
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj[a].push_back({i + 1, b});
    adj[b].push_back({i + 1, a});
  }

  std::vector posse(n + 1, std::vector<std::pair<int, int>>());
  std::vector<int> p(n + 1, -1), r(n + 1);
  std::vector<bool> vis(n + 1, false), dupe(m + 1, false);
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    cn++;
    std::queue<int> q;
    q.push(i);
    vis[i] = true;
    r[cn] = i;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto [ne, v] : adj[u]) {
        if (dupe[ne]) continue;
        if (vis[v]) {
          posse[cn].push_back({ne, v});
          continue;
        }

        q.push(v);
        vis[v] = true;
        dupe[ne] = true;
      }
    }
  }

  std::vector<std::pair<int, int>> comp;
  for (int i = 1; i <= cn; ++i) {
    comp.push_back({posse[i].size(), i});
  }
  sort(comp.begin(), comp.end());

  int cur = comp.back().second, nxt = 1;
  std::vector<std::tuple<int, int, int>> ans;
  std::vector<bool> dup(m + 1);
  while (cn > 1) {
    if (nxt == cur) {
      nxt++;
      continue;
    }
    if (posse[cur].size() == 0) {
      comp.pop_back();
      cur = comp.back().second;
      continue;
    }
    if (dup[posse[cur].back().first]) {
      posse[cur].pop_back();
      continue;
    }
    ans.push_back({posse[cur].back().first, posse[cur].back().second, r[nxt]});
    dup[posse[cur].back().first] = true;
    nxt++;
    posse[cur].pop_back();
    cn--;
  }

  std::cout << ans.size() << "\n";
  for (auto [a, b, c] : ans) {
    std::cout << a << " " << b << " " << c << "\n";
  }
}