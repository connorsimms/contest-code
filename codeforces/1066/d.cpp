#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T> using v = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = l < r ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = l > r ? r : l; }

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;

    deque<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = 0;

    int left = 0, right = 0;

    while (!a.empty() && a.front() <= l) {
        ans += l - a.front();
        ++left;
        a.pop_front();
    }

    while (!a.empty() && a.back() >= r) {
        ans += a.back() - r;
        ++right;
        a.pop_back();
    }

    ans += min(left, right) * (r - l);

    while (left != right && !a.empty()) {
        if (left > right) {
            ++right;
            ans += a.back() - l;
            a.pop_back();
        } else {
            ++left;
            ans += r - a.front();
            a.pop_front();
        }
    }

    while (a.size() >= 2) {
        ++left;
        ++right;
        ans += a.back() - a.front();
        a.pop_front();
        a.pop_back();
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
