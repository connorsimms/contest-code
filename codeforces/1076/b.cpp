#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = r > l ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = r < l ? r : l; }

int rnd(int a, int b) { return a + rand() % (b - a - 1); }

void gen(int seed) {
    srand(seed);

    cout << '\n';
}

void brute() {}

void solve() {
    int n;
    cin >> n;
    vec<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int mx = n;
    int l = 0, r = n;
    for (int i = 0; i < n; ++i) {
        if (v[i] == mx) {
            --mx;
            ++l;
            continue;
        }

        else {
            for (int j = i + 1; j < n; ++j) {
                if (v[j] == mx) {
                    r = j;
                    break;
                }
            }
            break;
        }
    }

    reverse(v.begin() + l, v.begin() + r + 1);

    for (auto x : v) cout << x << ' ';
    cout << '\n';
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc > 1) {
        string mode = argv[1];
        if (mode == "gen")
            gen(atoi(argv[2]));
        else if (mode == "brute")
            brute();
        return 0;
    }

    int TC;
    cin >> TC;
    while (TC--) solve();
}
