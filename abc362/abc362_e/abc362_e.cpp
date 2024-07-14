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
  for (int i = n; i >= 0; --i) {
    for (int j = i + 1; j <= n; ++j) {
      dp[i][j][2] += 1;
      int d = a[j] - a[i];
      for (int k = 2; k <= n - i; ++k) {
        for (int l = j + 1; l <= n; ++l) {
          if (a[l] - a[j] == d) dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[j][l][k]) % mod;
        }
      }
    }
  }
  cout << n << " ";
  for (int k = 2; k <= n; ++k) {
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        sum = (sum + dp[i][j][k]) % mod;
      }
    }
    cout << sum << " ";
  }
}