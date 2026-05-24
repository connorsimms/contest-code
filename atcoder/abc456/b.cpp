#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> d(3, vector<int>(6));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 6; ++j) {
      cin >> d[i][j];
    }
  }

  int ways = 0;
  for (int i = 0; i < 6; ++i) {
    int x = d[0][i];
    if (x != 4 && x != 5 && x != 6)
      continue;
    for (int j = 0; j < 6; ++j) {
      int y = d[1][j];
      if (y != 4 && y != 5 && y != 6)
        continue;
      if (y == x)
        continue;
      for (int k = 0; k < 6; ++k) {
        int z = d[2][k];
        if (z != 4 && z != 5 && z != 6)
          continue;
        if (z == y || z == x)
          continue;

        ++ways;
      }
    }
  }

  cout << static_cast<double>(ways) / 216 << '\n';
}
