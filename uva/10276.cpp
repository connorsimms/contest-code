#include <bits/stdc++.h>
using namespace std;

// 1
// 4 = 1 + 3
// 9 = 1 + 8, 2 + 7, 3 + 6, 4 + 5
// 16 =
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int t;
        cin >> t;

        vector<int> p(t);
        int used{};

        int i{1};
        for (;; ++i) {
            bool placed = false;
            for (auto &x : p) {
                if (!x)
                    continue;

                auto sum = x + i;
                bool square = int(sqrt(sum)) * int(sqrt(sum)) == sum;
                if (square) {
                    x = i;
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                if (used < t) {
                    p[used] = i;
                    ++used;
                } else {
                    break;
                }
            }
        }

        cout << i - 1 << '\n';
    }
}
