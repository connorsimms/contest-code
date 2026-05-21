#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<int> p(N);
    iota(p.begin(), p.end(), 0);

    auto find_set = [&](int v, auto&& self) {
        if (v == p[v]) return v;
        return p[v] = self(p[v], self);
    };

    auto join_set = [&](int a, int b, auto&& self) {
        int A = find_set(a, find_set);
        int B = find_set(b, find_set);

        if (A == B) { return; }

        p[A] = B;
    };

    for (int i = 0 ; i < Q; ++i)
    {
        char cmd; cin >> cmd;
        int a, b; cin >> a >> b;
        if (cmd == '?')
        {
            if (find_set(a, find_set) == find_set(b, find_set)) { cout << "yes\n"; }
            else { cout << "no\n"; }
        }
        else
        {
            join_set(a, b, join_set);
        }
    }
}
