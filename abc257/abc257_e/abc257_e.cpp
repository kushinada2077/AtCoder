#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, C[10];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= 9; ++i) cin >> C[i];
  int mn = *min_element(C + 1, C + 10);
  int length = n / mn;
  string ans = "";

  for (int i = 0; i < length; ++i) {
    for (int j = 9; j >= 1; --j) {
      if ((i64)mn * (length - i - 1) + C[j] <= n) {
        ans.push_back((char)j + '0');
        n -= C[j];
        break;
      }
    }
  }

  cout << ans << "\n";
}