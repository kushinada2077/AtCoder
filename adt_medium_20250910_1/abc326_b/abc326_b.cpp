#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  while (N < 1000) {
    std::string num = std::to_string(N++);
    int a = num[0] - '0', b = num[1] - '0', c = num[2] - '0';
    if (a * b == c) {
      std::cout << num << "\n";
      break;
    }
  }
}