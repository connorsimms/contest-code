#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exp(ll a, ll p) {
    ll res{1};
    ll cur{a};
    while (p) {
        if (p & 1)
            res *= cur;
        cur *= cur;
        p >>= 1;
    }
    return res;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> c;
        {
            stringstream ss{line};
            int x;
            while (ss >> x)
                c.push_back(x);
        }

        getline(cin, line);
        {
            stringstream ss{line};
            int x;
            bool first = true;
            while (ss >> x) {
                if (!first) cout << ' ';
                first = false;

                ll res{};
                for (int i{}; i < c.size(); ++i) {
                    res += c[i] * exp(x, c.size() - 1 - i);
                }
                cout << res;
            }
            cout << '\n';
        }
    }
}
