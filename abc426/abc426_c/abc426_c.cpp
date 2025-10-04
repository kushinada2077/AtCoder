#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int findp(std::vector<int>& parent, int x) {
  if (parent[x] == x) return x;
  return parent[x] = findp(parent, parent[x]);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;

  std::vector<int> parent(N + 1);
  std::vector<int> cnt(N + 1, 0);

  for (int i = 0; i <= N; ++i) parent[i] = i;
  for (int i = 1; i <= N; ++i) cnt[i] = 1;

  while (Q--) {
    int X, Y;
    std::cin >> X >> Y;
    int upgraded = 0;
    int v = findp(parent, X);
    while (v > 0 && v <= X) {
      upgraded += cnt[v];
      cnt[Y] += cnt[v];
      cnt[v] = 0;
      parent[v] = findp(parent, v - 1);
      v = parent[v];
    }
    std::cout << upgraded << '\n';
  }
}