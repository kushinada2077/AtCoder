#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  i64 cnt = 0;
  bool f = true;
  std::cin >> N;
  std::string a = "";
  for (int i = 0; i < N; ++i) {
    char c;
    i64 l;
    std::cin >> c >> l;
    cnt += l;
    if (cnt > 100) {
      f = false;
      break;
    }
    for (int j = 0; j < l; ++j) {
      a += c;
    }
  }

  if (f) {
    std::cout << a << "\n";
  } else {
    std::cout << "Too Long\n";
  }
}