#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  char res = 'A' + ((x + n - 1) / n) - 1;
  cout << res << "\n";
}