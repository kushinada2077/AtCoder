#include <bits/stdc++.h>
using i64 = long long;

bool isPal(std::vector<int>& a, int l, int r) {
  if (l >= r) {
    return true;
  }
  if (a[l] == a[r - 1]) {
    return isPal(a, l + 1, r - 1);
  }
  return false;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int A;
  i64 N;
  std::cin >> A >> N;
  std::vector<i64> pal;
  for (i64 i = 1; i < 10; ++i) {
    pal.push_back(i);
  }
  for (int i = 1; i <= 6; ++i) {
    int max = 1;
    for (int j = 0; j < i; ++j) {
      max *= 10;
    }
    int min = 1;
    for (int j = 0; j < i - 1; ++j) {
      min *= 10;
    }
    for (int j = min; j <= max; ++j) {
      std::vector<int> tmp;
      int copy = j;
      while (copy > 0) {
        tmp.push_back(copy % 10);
        copy /= 10;
      }
      int sz = tmp.size();
      i64 item = 0;
      for (int k = sz - 1; k >= 0; --k) {
        item *= 10;
        item += tmp[k];
      }
      i64 middle = item;
      for (int k = 0; k < sz; ++k) {
        item *= 10;
        item += tmp[k];
      }
      pal.push_back(item);
      for (int p = 0; p < 10; ++p) {
        i64 item_n = middle;
        item_n *= 10;
        item_n += p;
        for (int q = 0; q < sz; ++q) {
          item_n *= 10;
          item_n += tmp[q];
        }
        pal.push_back(item_n);
      }
    }
  }

  sort(pal.begin(), pal.end());

  i64 ans = 0;
  for (auto p : pal) {
    if (p > N) {
      break;
    }
    i64 copy = p;
    std::vector<int> trans;
    while (copy > 0) {
      trans.push_back(copy % A);
      copy /= A;
    }
    std::reverse(trans.begin(), trans.end());
    if (isPal(trans, 0, trans.size()) == true) {
      ans += p;
    }
  }

  std::cout << ans << "\n";
}