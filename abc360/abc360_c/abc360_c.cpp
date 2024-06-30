#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
  fastio;
  priority_queue<int, vector<int>, greater<int>> box[100005];
  int n;
  ll ans = 0;
  cin >> n;
  int a[100005], w[100005];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> w[i];
  for (int i = 0; i < n; ++i) {
    int num = a[i] - 1;
    box[num].push(w[i]);
  }
  for (int i = 0; i < n; ++i) {
    auto pq = box[i];
    while (pq.size() > 1) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans;
}