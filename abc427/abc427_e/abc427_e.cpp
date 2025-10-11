#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector board(h, std::vector<char>(w));
  std::vector<P> trash;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> board[i][j];
      if (board[i][j] == '#') trash.push_back({i, j});
    }
  }

  std::queue<std::pair<std::vector<P>, int>> q;
  std::set<std::vector<P>> vis;
  std::vector<int> dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};

  q.push({trash, 0});

  while (!q.empty()) {
    auto [cur_state, num] = q.front();
    q.pop();

    if ((int)cur_state.size() == 0) {
      std::cout << num << "\n";
      return 0;
    }

    for (int dir = 0; dir < 4; ++dir) {
      bool ok = true;
      std::vector<P> next_state;
      for (auto [y, x] : cur_state) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if (board[ny][nx] == 'T') {
          ok = false;
          break;
        }
        next_state.push_back({ny, nx});
      }

      if (ok && !vis.contains(next_state)) {
        q.push({next_state, num + 1});
        vis.insert(next_state);
      }
    }
  }

  std::cout << "-1\n";
}