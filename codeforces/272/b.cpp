#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int targ{};
    for (auto c : a) {
        targ += (c == '+' ? 1 : -1);
    }

    int numQ{};
    for (auto c : b) {
        numQ += c == '?';
    }

    int tot = 1 << numQ;

    int num{};

    for (int msk = 0; msk < (1 << numQ); ++msk) {
        int pos{};
        int midx{};

        for (auto c : b) {
            switch (c) {
            case '+': pos += 1; break;
            case '-': pos -= 1; break;
            case '?': pos += ((msk & (1 << midx++)) != 0 ? 1 : -1); break;
            }
        }

        if (pos == targ)
            ++num;
    }

    cout << fixed << setprecision(9) << double(num) / tot << '\n';
}
