#include <algorithm>
#include <iostream>
#include <set>
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

int main() {
  fastio;
    vector<int> a(3);
  for (auto& i : a) cin >> i;
  string s;
  cin >> s;
  if (s == "Red") cout << min(a[1], a[2]);
  else if (s == "Green") cout << min(a[0], a[2]);
  else cout << min(a[0], a[1]);
}