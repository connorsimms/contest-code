#include <bits/stdc++.h>
using namespace std;

std::mt19937 rnd{static_cast<std::mt19937::result_type>(
    std::chrono::steady_clock::now().time_since_epoch().count())};

using uid = uniform_int_distribution<long long>;

void gen() {
    uid N{1, 10};
    uid A{0, 3};
    auto n = N(rnd);
    cout << n << '\n';
    for (int i{}; i < n; ++i) {
        cout << A(rnd) << ' ';
    }
    cout << '\n';
}

void brute() {
    size_t n;
    cin >> n;
    vector<int> g(n), c(n);
    for (size_t i{}; i < n; ++i) {
        int x;
        cin >> x;
        if (x & 1) c[i] = 1;
        if (x & 2) g[i] = 1;
    }

    int ans{};
    for (int msk{}; msk < (1 << n); ++msk) {
        vector<int> dt(n);
        int days{};

        for (int i{}; i < n; ++i) {
            if ((msk & (1 << i)) && c[i]) {
                ++days;
                dt[i] = 1;
            }

            if (!(msk & (1 << i)) && g[i]) {
                ++days;
                dt[i] = 2;
            }
        }

        bool valid = true;
        for (int i{}; i < n - 1 && valid; ++i) {
            if (dt[i] && dt[i] == dt[i + 1])
                valid = false;
        }

        if (valid) ans = max(ans, days);
    }

    cout << n - ans << '\n';
}

void solve() {
    size_t n;
    cin >> n;
    vector<int> g(n), c(n);
    for (size_t i{}; i < n; ++i) {
        int x;
        cin >> x;
        if (x & 1) c[i] = 1;
        if (x & 2) g[i] = 1;
    }

    int ans{max(g[0], c[0])};

    for (size_t i{}; i < n - 1; ++i) {
        g[i + 1] = max(max(g[i], c[i]), c[i] + g[i + 1]);
        c[i + 1] = max(max(g[i], c[i]), g[i] + c[i + 1]);
        auto m = max(g[i + 1], c[i + 1]);
        ans = ans < m ? m : ans;
    }

    cout << n - ans << '\n';
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        string mode(argv[1]);
        if (mode == "gen") {
            gen();
        } else if (mode == "brute") {
            brute();
        }
    } else {
        solve();
    }
}
