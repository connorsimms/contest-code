#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

int rnd(int a, int b) { return (rand() % (b - a + 1)) + a; }

void gen(int seed) {
    srand(seed);
    int tc = 100;
    cout << tc << '\n';
    while (tc--) {
        int n = rnd(1, 100);
        int m = rnd(1, 100);
        int a = rnd(1, 100);
        int b = rnd(1, 100);
        cout << n << ' ' << m << ' ' << a << ' ' << b << '\n';
    }
}

void brute() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> seen(n, vector<int>(m));

    bool down = true;
    int r = 0, c = 0;
    int cnt = 0;
    bool poss = false;

    while (true) {
        if (seen[r][c] & (1 << down)) {
            break;
        } else {
            if (seen[r][c] == 0) ++cnt;
            seen[r][c] |= (1 << down);
        }

        if (down) {
            r += a;
            r %= n;
        } else {
            c += b;
            c %= m;
        }

        down = !down;
    }

    if (cnt == n * m) poss = true;

    if (poss) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if (gcd(n, a) != 1) {
        cout << "NO\n";
        return;
    }

    if (gcd(m, b) != 1) {
        cout << "NO\n";
        return;
    }

    auto l = lcm(n, m) * 2;

    if (l < n * m - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        string mode(argv[1]);
        if (mode == "gen") {
            int seed = atoi(argv[2]);
            gen(seed);
        }
        if (mode == "brute") {
            int t;
            cin >> t;
            while (t--) brute();
        }
        return 0;
    }
    int t;
    cin >> t;
    while (t--) solve();
}
