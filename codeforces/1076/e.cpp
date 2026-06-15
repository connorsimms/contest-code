#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = r > l ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = r < l ? r : l; }
template <class T> T INF() { return numeric_limits<T>::max(); }

int rnd(int a, int b) { return a + rand() % (b - a - 1); }

void gen(int seed) { srand(seed); }

void brute() {}

void solve() {
    ll n;
    cin >> n;

    vec<int> dist(n + 1, INF<int>());
    unordered_map<ll, bool> seen;
    queue<ll> q;
    vec<ll> a;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        if (x == 1) {
            seen[x] = true;
            dist[x] = 1;
            continue;
        }

        if (!seen[x]) {
            seen[x] = true;
            a.push_back(x);
            q.push(x);
            dist[x] = 1;
        }
    }

    sort(a.begin(), a.end());

    while (!q.empty()) {
        ll f = q.front();
        q.pop();

        for (auto x : a) {
            if (x * f <= n) {
                if (dist[x * f] > dist[f] + 1) {
                    dist[x * f] = dist[f] + 1;
                    q.push(x * f);
                }
            } else
                break;
        }
    }

    for (int i = 1; i <= n; ++i) { cout << (dist[i] != INF<int>() ? dist[i] : -1) << ' '; }
    cout << '\n';
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc > 1) {
        string mode = argv[1];
        if (mode == "gen")
            gen(atoi(argv[2]));
        else if (mode == "brute") {
            int TC;
            cin >> TC;
            while (TC--) brute();
        }
        return 0;
    }

    int TC;
    cin >> TC;
    while (TC--) solve();
}
