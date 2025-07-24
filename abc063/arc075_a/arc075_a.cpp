#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> ten;
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    int s;
    std::cin >> s;
    if (s % 10 != 0) {
      ten.push_back(s);
    }
    sum += s;
  }
  sort(ten.begin(), ten.end());

  if (sum % 10 == 0) {
    if (ten.size() > 0) {
      sum -= ten.front();
    } else {
      sum = 0;
    }
  }

  std::cout << sum << "\n";
}