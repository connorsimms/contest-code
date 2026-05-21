#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    unordered_map<int, bool> used;

    vector<int> ans(n);

    for (int i = 1, j = 0; j < n && i <= 2 * n; ++i) {
      if (!used[i]) {
        ans[j] = i;
        used[i] = true;
        if (j > 0) {
          int adj = ans[j] + ans[j - 1];
          used[adj] = true;
        }
        ++j;
      }
    }

    cout << ans[0];
    for (int i = 1; i < n; ++i) {
      cout << ' ' << ans[i];
    }
    cout << '\n';
  }
}
