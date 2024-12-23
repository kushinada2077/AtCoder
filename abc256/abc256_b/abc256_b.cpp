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

int n, field[4], ans;
int main() {
  fastio;
    cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  for (auto d : A) {
    field[0] = 1;
    for (int cur = 3; cur >= 0; --cur) {
      int nxt = cur + d;
      if (field[cur] == 1) {
        if (nxt < 4) {
          field[nxt] = 1;
          field[cur] = 0;
        } else {
          ans++;
          field[cur] = 0;
        }
      }
    }
  }

  cout << ans << "\n";
}