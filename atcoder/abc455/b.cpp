#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<bool>> g(h, vector<bool>(w));

  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;

    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '#')
        g[i][j] = true;
    }
  }

  long long ans = 0;

  for (int h1 = 0; h1 < h; ++h1) {
    for (int h2 = h1; h2 < h; ++h2) {
      for (int w1 = 0; w1 < w; ++w1) {
        for (int w2 = w1; w2 < w; ++w2) {
          bool valid = true;
          for (int i = h1; i <= h2 && valid; ++i) {
            for (int j = w1; j <= w2 && valid; ++j) {
              if (g[i][j] != g[h1 + h2 - i][w1 + w2 - j])
                valid = false;
            }
          }
          if (valid)
            ++ans;
        }
      }
    }
  }
  cout << ans << '\n';
}
