#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, A[11][11];
string s;
i64 my_plus(i64 a, i64 b) {
  i64 tmp = b;
  while (tmp) {
    a *= 10;
    tmp /= 10;
  }

  return a + b;
}
i64 solve(int y, int x, int k, int dy, int dx) {
  if (k == 0) return A[y][x];
  return my_plus(A[y][x], solve((y + dy) % n, (x + dx) % n, k - 1, dy, dx));
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < n; ++j) {
      A[i][j] = s[j] - '0';
      if (mx < A[i][j]) mx = A[i][j];
    }
  }

  vector<Pi> stList;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (A[i][j] == mx) stList.push_back({i, j});
    }
  }

  i64 ans = 0;
  vector<int> dy = {n - 1, n - 1, 0, 1, 1, 1, 0, n - 1};
  vector<int> dx = {0, 1, 1, 1, 0, n - 1, n - 1, n - 1};

  for (auto [y, x] : stList) {
    for (int dir = 0; dir < 8; ++dir) {
      ans = max(ans, solve(y, x, n - 1, dy[dir], dx[dir]));
    }
  }

  cout << ans << "\n";
}