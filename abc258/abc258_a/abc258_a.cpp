#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int k;
  cin >> k;
  cout << 21 + k / 60 << ":" << (k % 60) / 10 << k % 60 % 10 << "\n";
}