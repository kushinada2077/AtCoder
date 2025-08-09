#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::string T;
  std::cin >> N >> T;
  // zero[i] = 끝 인덱스가 i인 부분 문자열에서 0으로 변하는 문자열의 갯수
  // one[i] = 끝 인덱스가 i인 부분 문자열에서 1으로 변하는 문자의 갯수
  std::vector<i64> zero(N), one(N);
  zero[0] = T[0] == '0';
  one[0] = T[0] == '1';
  for (int i = 1; i < N; ++i) {
    if (T[i] == '0') {
      zero[i] += one[i - 1] + 1;
      one[i] += zero[i - 1];
    } else if (T[i] == '1') {
      zero[i] += zero[i - 1];
      one[i] += one[i - 1] + 1;
    }
  }
  std::cout << std::accumulate(one.begin(), one.end(), 0LL) << "\n";
}