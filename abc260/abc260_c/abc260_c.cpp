#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// R(N) = 레벨 N인 빨간 구슬을 바꿨을 때 얻을 수 있는 레벨 1 파란 구슬의 최대 갯수
// B(N) = 레벨 N인 파란 구슬을 바꿨을 때 얻을 수 있는 레벨 1 파란 구슬의 최대 갯수

int n;
i64 x, y;

struct Cal {
  i64 x, y;
  Cal(i64 x, i64 y) : x(x), y(y) {}
  i64 R(int n) {
    if (n == 1) return 0;
    return R(n - 1) + x * B(n);
  }
  i64 B(int n) {
    if (n == 1) return 1;
    return R(n - 1) + y * B(n - 1);
  }
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> x >> y;
  Cal cal(x, y);
  cout << cal.R(n) << "\n";
}