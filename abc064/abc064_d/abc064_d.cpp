#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, c = 0;
  std::string s, pre = "", suf = "";
  std::cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      c++;
    }
    if (s[i] == ')') {
      if (c == 0) {
        pre += '(';
      } else {
        c--;
      }
    }
  }

  if (c) {
    for (int i = 0; i < c; ++i) {
      suf += ')';
    }
  }

  std::cout << pre + s + suf << "\n";
}