#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, A[11][11];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) A[i][j] = s[j] - '0';
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
          if (dy == 0 && dx == 0) continue;
          i64 val = 0;
          for (int y = i, x = j, k = 0; k < n; ++k) {
            y = (y + dy + n) % n;
            x = (x + dx + n) % n;
            val = 10 * val + A[y][x];
          }

          ans = max(ans, val);
        }
      }
    }
  }

  cout << ans << "\n";
}