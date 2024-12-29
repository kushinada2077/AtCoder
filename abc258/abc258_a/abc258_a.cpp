#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  const int M = 60 * 24;
  int k;
  cin >> k;
  k += 60 * 21;
  k %= M;
  cout << k / 60 << ":";
  if ((k % 60) < 10) cout << "0";
  cout << k % 60 << "\n";
}