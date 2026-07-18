#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e6 + 1;

std::mt19937 mt{static_cast<std::mt19937::result_type>(
    std::chrono::steady_clock::now().time_since_epoch().count())};

using uid = uniform_int_distribution<long long>;

using ll = long long;

void gen() {
    uid N{1, 10}, M{1, 10};
    auto n = N(mt);
    auto m = M(mt);
    uid X{1, m};
    auto x = X(mt);
    uid Y{x, m};
    auto y = Y(mt);

    // if (2 * x > m)
    y = m;

    cout << n << ' ' << m << ' ' << x << ' ' << y << '\n';

    uid C{0, 1};

    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            cout << (C(mt) ? '#' : '.');
        }
        cout << '\n';
    }
}

void brute() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int>> cnt(2, vector<int>(m + 1));

    for (int i{}; i < n; ++i) {
        for (int j{1}; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                ++cnt[0][j];
            } else {
                ++cnt[1][j];
            }
        }
    }

    int ans = INF;
    int bestMsk{};
    for (int msk{}; msk < (1 << m); ++msk) {
        int mnStr = m + 1, mxStr = 0;
        int str = 1;
        int amt{};

        if (msk & 1)
            amt += cnt[1][1];
        else
            amt += cnt[0][1];

        for (int i{1}; i < m; ++i) {
            if (msk & (1 << i))
                amt += cnt[1][i + 1];
            else
                amt += cnt[0][i + 1];

            if (bool(msk & (1 << i)) == bool(msk & (1 << (i - 1)))) {
                ++str;
            } else {
                mnStr = str < mnStr ? str : mnStr;
                mxStr = str > mxStr ? str : mxStr;
                str = 1;
            }
        }

        mnStr = str < mnStr ? str : mnStr;
        mxStr = str > mxStr ? str : mxStr;

        if (mnStr >= x && mxStr <= y && amt < ans) {
            ans = amt;
            bestMsk = msk;
        }
    }

    for (int i{}; i < m; ++i) {
        if (bestMsk & (1 << i))
            cerr << 1;
        else
            cerr << 0;
    }
    cerr << endl;

    cout << ans << '\n';
}

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int>> cnt(2, vector<int>(m + 1));

    for (int i{}; i < n; ++i) {
        string r;
        cin >> r;
        for (int j{}; j < m; ++j) {
            char c = r[j];
            if (c == '.') {
                ++cnt[0][j + 1];
            } else {
                ++cnt[1][j + 1];
            }
        }
    }

    vector<vector<int>> pfc(2, vector<int>(m + 1));

    for (int i{1}; i <= m; ++i) {
        for (auto c : {0, 1})
            pfc[c][i] = cnt[c][i] + pfc[c][i - 1];
    }

    // for (auto r : pfc) {
    //     for (auto c : r)
    //         cerr << c << ' ';
    //     cerr << endl;
    // }

    vector<vector<ll>> mem(2, vector<ll>(m + 1, INF));

    mem[0][0] = 0;
    mem[1][0] = 0;

    auto dp = [&](auto &&rec, int i, bool c) {
        if (mem[c][i] != INF)
            return mem[c][i];

        for (int l{x}; l <= min(y, i); ++l) {
            auto o = rec(rec, i - l, !c);
            // cerr << "best way to paint ending at " << i - l << " with " << c << " is " << o << endl;
            auto p = pfc[c][i] - pfc[c][i - l];
            // cerr << "painting " << i - l + 1 << " to " << i << " with " << !c << " takes " << p << endl;
            mem[c][i] = min(mem[c][i], o + p);
        }

        // cerr << "mem[" << c << "][" << i << "]: " << mem[c][i] << endl;

        if (mem[c][i] == INF)
            mem[c][i] = INF + 1;

        return mem[c][i];
    };

    cout << min(dp(dp, m, 0), dp(dp, m, 1)) << '\n';

    // for (auto r : mem) {
    //     for (auto c : r)
    //         cerr << c << ' ';
    //     cerr << endl;
    // }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        string mode(argv[1]);
        if (mode == "gen") { gen(); }
        if (mode == "brute") { brute(); }
    } else {
        solve();
    }
}
