#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  auto a = {"Ocelot", "Serval", "Lynx"};
  std::string x, y;
  std::cin >> x >> y;

  auto xx = std::ranges::find(a, x) - a.begin();
  auto yy = std::ranges::find(a, y) - a.begin();

  if (xx >= yy) std::cout << "Yes\n";
  else std::cout << "No\n";
}