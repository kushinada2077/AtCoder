#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

const int IMP = -0x3f3f3f3f;
int N;
vector<vector<int>> dp(200005, vector<int>(3, IMP));  // dp[n][k] = 상태가 k인 n번째까지 했을 때 최대 승리 횟수
string s, a = "RPS";
unordered_map<char, char> w, l;
unordered_map<char, int> c2i;

int main() {
  fastio;
    c2i['R'] = 0;
  c2i['P'] = 1;
  c2i['S'] = 2;
  w['R'] = 'P';
  l['R'] = 'S';
  w['P'] = 'S';
  l['P'] = 'R';
  w['S'] = 'R';
  l['S'] = 'P';
  cin >> N >> s;
  dp[1][c2i[w[s[0]]]] = 1;
  dp[1][c2i[s[0]]] = 0;
  dp[1][c2i[l[s[0]]]] = IMP;

  for (int i = 2; i <= N; ++i) {
    for (int k = 0; k < 3; ++k) {
      if (a[k] == l[s[i - 1]]) continue;
      dp[i][k] = max(dp[i - 1][(k + 1) % 3], dp[i - 1][(k + 2) % 3]) + (w[s[i - 1]] == a[k]);
    }
  }

  cout << *max_element(all(dp[N]));
}