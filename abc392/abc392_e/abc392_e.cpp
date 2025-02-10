#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
  std::vector<int> f, siz;

  DSU() {}
  DSU(int n) {
    init(n);
  }

  void init(int n) {
    f.resize(n);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) {
      std::swap(x, y);
    }
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }

  int size(int x) {
    return siz[find(x)];
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(M), B(M);
  for (int i = 0; i < M; ++i) {
    std::cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }
  DSU dsu(N);
  std::vector<bool> vis(M);
  int ans = N - 1;
  for (int i = 0; i < M; ++i) {
    if (dsu.merge(A[i], B[i])) {
      vis[i] = true;
      ans--;
    }
  }

  std::cout << ans << "\n";
  for (int i = 0, j = 0; i < M && j < N && ans; ++i) {
    if (!vis[i]) {
      while (dsu.same(A[i], j)) {
        j++;
      }
      std::cout << i + 1 << " " << B[i] + 1 << " " << j + 1 << "\n";
      dsu.merge(A[i], j);
      ans--;
    }
  }
}