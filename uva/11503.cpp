#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &p, int a) {
    if (p[a] == a)
        return a;
    return p[a] = find(p, p[a]);
}

void join(vector<int> &p, vector<int> &s, int a, int b) {
    int A = find(p, a);
    int B = find(p, b);
    if (A != B) {
        p[A] = B;
        s[B] += s[A];
    }
}

void solve() {
    int N;
    cin >> N;

    map<string, int> id;
    int cid{0};
    vector<int> p(2 * N + 1), s(2 * N + 1, 1);
    iota(p.begin(), p.end(), 0);

    for (int i{}; i < N; ++i) {
        string a, b;
        cin >> a >> b;
        if (!id[a]) {
            id[a] = ++cid;
        }
        if (!id[b]) {
            id[b] = ++cid;
        }

        join(p, s, id[a], id[b]);
        auto A = find(p, id[a]);
        auto B = find(p, id[b]);

        cout << s[A] << '\n';
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) solve();
}
