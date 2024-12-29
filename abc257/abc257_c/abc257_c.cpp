#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, w;
string s;
vector<int> adult, children, all;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> w;
    if (s[i] == '0') children.push_back(w);
    else adult.push_back(w);
    all.push_back(w);
  }
  sort(children.begin(), children.end());
  sort(adult.begin(), adult.end());

  int ans = max(children.size(), adult.size());

  for (auto x : all) {
    int numChild = lower_bound(children.begin(), children.end(), x) - children.begin();
    int numAdult = (int)adult.size() - (lower_bound(adult.begin(), adult.end(), x) - adult.begin());
    ans = max(ans, numChild + numAdult);
  }

  cout << ans << "\n";
}