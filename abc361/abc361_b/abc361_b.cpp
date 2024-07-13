#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

bool f(const vector<vector<int>>& a) {
    for (int k = 0; k < 2; ++k) {
        if (a[k][0] <= a[!k][0] && a[k][1] <= a[!k][1] && a[k][2] <= a[!k][2] && 
            a[!k][3] <= a[k][3] && a[!k][4] <= a[k][4] && a[!k][5] <= a[k][5]) return true;
        if (a[k][0] < a[!k][3] && a[k][1] < a[!k][4] && a[k][2] < a[!k][5] && 
            a[!k][0] < a[k][3] && a[!k][1] < a[k][4] && a[!k][2] < a[k][5]) return true;
    }
    return false;
}

int main() {
    fastio;
    vector<vector<int>> a(2, vector<int>(6));
    for (auto& i : a)
        for (auto& j : i) cin >> j;
    if (f(a)) cout << "Yes\n";
    else cout << "No\n";
}