#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, W[200005];
string s;
vector<int> child, adult, all;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> W[i];
    all.push_back(W[i]);
    if (s[i] == '0') child.push_back(W[i]);
    else adult.push_back(W[i]);
  }

  sort(child.begin(), child.end());
  sort(adult.begin(), adult.end());

  int ans = max(child.size(), adult.size());
  for (auto w : all) {
    int cn = lower_bound(child.begin(), child.end(), w) - child.begin();
    int an = adult.end() - lower_bound(adult.begin(), adult.end(), w);
    ans = max(ans, an + cn);
  }

  cout << ans << "\n";
}