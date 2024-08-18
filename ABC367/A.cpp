#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int main() {
  fastio;
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = b; i != c; i = (i + 1) % 24) {
    if (i == a) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}