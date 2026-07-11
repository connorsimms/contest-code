#include <bits/stdc++.h>
using namespace std;

int main() {
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    vector<int> v{r1, c1, d1, d2, c2, r2};

    bool poss = false;

    for (int bs{}; bs < (1 << 9) && !poss; ++bs) {
        if (__builtin_popcount(bs) != 4)
            continue;

        vector<int> gems;

        for (int i = 0; i < 9; ++i) {
            if (bs & (1 << i)) {
                gems.push_back(i + 1);
            }
        }

        do {
            bool val = true;

            int k{};
            for (int i = 0; i < 4 && val; ++i) {
                for (int j = i + 1; j < 4 && val; ++j) {
                    if (gems[i] + gems[j] != v[k])
                        val = false;
                    else
                        ++k;
                }
            }

            if (val) {
                cout << gems[0] << ' ' << gems[1] << '\n'
                     << gems[2] << ' ' << gems[3] << '\n';
                poss = true;
                break;
            }
        } while (next_permutation(gems.begin(), gems.end()));
    }

    if (!poss)
        cout << "-1\n";
}
