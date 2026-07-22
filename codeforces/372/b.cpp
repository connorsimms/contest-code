#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.size() < 26) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> f(26);
    int numq{};
    int lmsk = (1 << 26) - 1;
    int lset = 0;
    int l{}, r{25};

    for (int i{l}; i <= r; ++i) {
        if (s[i] == '?') {
            ++numq;
        } else {
            lset |= 1 << (s[i] - 'A');
            f[s[i] - 'A']++;
        }
    }

    bool poss = false;
    do {
        if (numq == 26 - __builtin_popcount(lset)) {
            poss = true;
            int i{l};
            int j{0};
            while (i <= r && j < 26) {
                if (lset & (1 << j)) {
                    ++j;
                    continue;
                }

                if (s[i] != '?') {
                    ++i;
                    continue;
                }

                s[i] = char('A' + j);
                ++i;
                ++j;
            }
        }

        if (s[l] == '?')
            --numq;
        else if (--f[s[l] - 'A'] == 0)
            lset ^= 1 << (s[l] - 'A');
        ++l;

        if (++r < s.size()) {
            if (s[r] == '?')
                ++numq;
            else if (++f[s[r] - 'A'] == 1)
                lset ^= 1 << (s[r] - 'A');
        }
    } while (!poss && r < s.size());

    if (poss) {
        for (auto &c : s) {
            if (c == '?')
                c = 'A';
        }
        cout << s << '\n';
    } else {
        cout << -1 << '\n';
    }
}
