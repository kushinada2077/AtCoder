#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  if (S == "red") {
    std::cout << "SSS";
  } else if (S == "blue") {
    std::cout << "FFF";
  } else if (S == "green") {
    std::cout << "MMM";
  } else {
    std::cout << "Unknown";
  }
}