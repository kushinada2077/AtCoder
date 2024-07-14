#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

const int mod = 998244353;
ll dp[85][85][85];
int main() {
  fastio;
    int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) dp[i][j][2] += 1;
  }
  for (int i = n; i >= 1; --i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int l = 3; l <= n - i + 1; ++l) {
        for (int k = j + 1; k <= n; ++k) {
          if (a[k] - a[j] == a[j] - a[i]) dp[i][j][l] = (dp[i][j][l] + dp[j][k][l - 1]) % mod;
        }
      }
    }
  }
  cout << n << " ";
  for (int l = 2; l <= n; ++l) {
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) sum = (sum + dp[i][j][l]) % mod;
    }
    cout << sum << " ";
  }
}