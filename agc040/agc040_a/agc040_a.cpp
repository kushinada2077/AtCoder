#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int N = S.size();
  std::vector<int> A(N + 1, 0);
  int c = 0;
  for (int i = 1; i < N + 1; ++i) {
    if (S[i - 1] == '<') {
      c++;
    } else {
      c = 0;
    }
    A[i] = std::max(A[i], c);
  }

  c = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (S[i] == '>') {
      c++;
    } else {
      c = 0;
    }
    A[i] = std::max(A[i], c);
  }

  std::cout << std::accumulate(A.begin(), A.end(), 0LL) << "\n";
}