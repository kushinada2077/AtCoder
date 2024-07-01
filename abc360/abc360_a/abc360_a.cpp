#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
  fastio;
  string s;
  cin >> s;
  int a = s.find('R');
  int b = s.find('M');
  cout << ((a < b) ? "Yes" : "No");
}