#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  int X;
  std::cin >> X;
  bool ans = false;
  for (int i = 0; i < N; ++i) {
    ans |= A[i] == X;
  }
  if (ans) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}