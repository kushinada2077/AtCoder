#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using P = std::pair<int, int>;

std::pair<std::map<i64, i64>, std::map<i64, i64>> solve_half(const std::vector<int>& arr, i64 m) {
  std::map<i64, i64> map_no, map_with;

  map_no[0] = 1;

  for (int x : arr) {
    std::map<i64, i64> next_map_no;
    std::map<i64, i64> next_map_with;

    for (auto const& [rem, count] : map_no) {
      next_map_with[(rem + x) % m] += count;
    }

    next_map_no = map_no;
    for (auto const& [rem, count] : map_with) {
      next_map_no[rem] += count;
    }

    map_no = next_map_no;
    map_with = next_map_with;
  }

  return {map_no, map_with};
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  i64 m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int mid = n / 2;
  std::vector<int> first_half(a.begin(), a.begin() + mid);
  std::vector<int> second_half(a.begin() + mid, a.end());

  std::reverse(second_half.begin(), second_half.end());

  auto [map1_no_last, f1] = solve_half(first_half, m);
  auto [map2_no_first, f2] = solve_half(second_half, m);

  std::map<i64, i64> tot1 = map1_no_last;
  for (auto const& [rem, cnt] : f1) tot1[rem] += cnt;

  std::map<i64, i64> tot2 = map2_no_first;
  for (auto const& [rem, cnt] : f2) tot2[rem] += cnt;

  i64 ans = 0;

  for (auto const& [rem1, cnt1] : tot1) {
    for (auto const& [rem2, cnt2] : tot2) {
      if ((rem1 + rem2) % m == 0) {
        ans += cnt1 * cnt2;
      }
    }
  }

  i64 invalid_cnt = 0;
  for (auto const& [rem1, cnt1] : f1) {
    for (auto const& [rem2, cnt2] : f2) {
      if ((rem1 + rem2) % m == 0) {
        invalid_cnt += cnt1 * cnt2;
      }
    }
  }

  i64 tot_ans = 0;
  auto combine = [&](const std::map<i64, i64>& mapA, const std::map<i64, i64>& mapB) {
    i64 res = 0;
    for (auto const& [rem, count] : mapA) {
      i64 needed = (m - rem + m) % m;
      if (mapB.count(needed)) res += count * mapB.at(needed);
    }
    return res;
  };

  tot_ans = combine(tot1, tot2);
  i64 invalid = combine(f1, f2);

  std::cout << tot_ans - invalid << "\n";
}