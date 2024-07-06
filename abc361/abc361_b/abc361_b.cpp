#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;

int main() {
  fastio;
    vector<vector<int>> a(2, vector<int>(6));
  for_in(6) cin >> a[0][i];
  for_in(6) cin >> a[1][i];
  int cnt = 0;
  for_in(2) {
    for_in(j, 0, 3) if (a[i][j] <= a[!i][j] && a[!i][j] < a[i][j + 3]) cnt++;
    if (cnt == 3) {
      cout << "Yes";
      return 0;
    }
  }
  cnt = 0;
  for_in(2) {
    for_in(j, 0, 3) if (a[i][j] < a[!i][j + 3] && a[!i][j + 3] <= a[i][j + 3]) cnt++;
    if (cnt == 3) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}