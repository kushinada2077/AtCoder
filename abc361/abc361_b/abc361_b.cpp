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

bool f(int l1, int l2, int r1, int r2) { return !(r1 <= l2 || r2 <= l1); }
int main() {
  fastio;
  vector<int> a(6), b(6);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  if (f(a[0], b[0], a[3], b[3]) && f(a[1], b[1], a[4], b[4]) && f(a[2], b[2], a[5], b[5])) cout << "Yes\n";
  else cout << "No\n";
}