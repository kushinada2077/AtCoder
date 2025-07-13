#include <bits/stdc++.h>
using i64 = long long;

bool isPal(i64 n, i64 a) {
  std::vector<i64> digit;
  while (n > 0) {
    digit.push_back(n % a);
    n /= a;
  }

  int len = digit.size();
  for (int i = 0; i < len / 2; ++i) {
    if (digit[i] != digit[len - 1 - i]) {
      return false;
    }
  }

  return true;
}
i64 rev_attach(i64 n, i64 x) {
  i64 ret = n;
  while (x > 0) {
    ret *= 10;
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int A;
  i64 N;
  std::cin >> A >> N;
  std::vector<i64> pal(9);
  std::iota(pal.begin(), pal.end(), 1);
  for (int len = 2; len <= 12; ++len) {
    int min = 1;
    for (int i = 0; i < len / 2 - 1; ++i) {
      min *= 10;
    }
    int max = min * 10;
    for (int i = min; i < max; ++i) {
      if (len % 2 == 1) {
        for (int mid = 0; mid < 10; ++mid) {
          i64 res = i * 10 + mid;
          pal.push_back(rev_attach(res, i));
        }
      } else {
        pal.push_back(rev_attach(i, i));
      }
    }
  }

  i64 ans = 0;
  for (int i = 0; i < pal.size(); ++i) {
    if (pal[i] > N) {
      break;
    }

    if (isPal(pal[i], A)) {
      ans += pal[i];
    }
  }

  std::cout << ans << "\n";
}