#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

// 각 시작점에 대해 모든 간격으로 시도하기
// 각 시도는 O(N / K)고 K번 시도하므로 각 시작점마다 O(N)을 N번, 즉 최종적으로 O(N^2)
int n, ans = 1, H[3001];
int main() {
  fastio;
    cin >> n;
  for (int i = 0; i < n; ++i) cin >> H[i];

  for (int st = 0; st < n; ++st) {
    for (int k = 1; k < n; ++k) {
      int cnt = 1, val = H[st];
      for (int i = 1; st + k * i < n; ++i) {
        if (H[st + k * i] != val) {
          cnt = 1;
          val = H[st + k * i];
        } else cnt++;
        ans = max(ans, cnt);
      }
    }
  }

  cout << ans << "\n";
}