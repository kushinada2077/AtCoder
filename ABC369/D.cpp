#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

// dp[n][k][p] = n번째 몬스터까지 최대 경험치, k가 0이면 짝수번째, 1이면
// 홀수번째, p가 0이면 안팸, 1이면 팸
ll dp[200005][2][2];
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  dp[1][1][1] = a[0];
  for (int i = 2; i <= n; ++i) {
    dp[i][0][0] = dp[i - 1][1][1];
    dp[i][0][1] = max(dp[i - 1][0][0], dp[i - 1][1][1]) + 2 * a[i - 1];
    dp[i][1][0] = dp[i - 1][0][1];
    dp[i][1][1] = max(dp[i - 1][0][1], dp[i - 1][1][0]) + a[i - 1];
  }

  cout << max({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]}) << "\n";
}