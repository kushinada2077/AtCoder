#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, x;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> x;
  x--;
  cout << (char)('A' + (x / n));
}