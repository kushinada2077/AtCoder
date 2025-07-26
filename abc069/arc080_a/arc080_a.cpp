#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
    int cnt = 0;
    while (a[i] > 0 && a[i] % 2 == 0) {
      a[i] /= 2;
      cnt++;
    }
    a[i] = cnt;
  }
  std::vector<int> b(3);
  for (int i = 0; i < N; ++i) {
    if (a[i] < 2) {
      b[a[i]]++;
    }
  }

  b[2] = N - b[0] - b[1];

  if (b[0] > b[2] + 1) {
    std::cout << "No\n";
  } else {
    if (b[0] == b[2] + 1 && b[1] > 0) std::cout << "No\n";
    else std::cout << "Yes\n";
  }
}