#include <algorithm>
#include <deque>
#include <iostream>
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

int main() {
  fastio;
    int n;
  cin >> n;
  vector<string> a(n);
  for (auto& s : a) cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    string s = a[i];
    if (s == "sweet") cnt++;
    else cnt = 0;
    if (cnt == 2 && i != n - 1) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}