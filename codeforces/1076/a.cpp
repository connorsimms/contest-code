#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = r > l ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = r < l ? r : l; }

int rnd(int a, int b) { return a + rand() % (b - a - 1); }

void gen(int seed) { srand(seed); }

void brute() {}

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }

    if ((s >= sum) && ((s - sum) % x == 0))
        cout << "YES\n";
    else
        cout << "NO\n";
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
