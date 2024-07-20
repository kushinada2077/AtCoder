#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
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

bool is_pal(const string& s, int l, int r) {
  if (l >= r) return true;
  if (s[l] != s[r]) return false;
  return is_pal(s, l + 1, r - 1);
}
int main() {
  fastio;
    unordered_set<string> dup;
  int n, k, ans = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  sort(all(s));
  do {
    if (dup.find(s) != dup.end()) continue;
    dup.insert(s);
    bool f = true;
    for (int st = 0; st < n - k + 1; ++st) {
      if (is_pal(s, st, st + k - 1)) {
        f = false;
        break;
      }
    }
    if (f) ans++;
  } while (next_permutation(all(s)));
  cout << ans << "\n";
}