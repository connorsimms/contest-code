#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i{}; i < n; ++i)
        cin >> v[i];

    int ans{1};
    vector<int> f(100'001);
    f[v[0]] = 1;
    set<int> s;
    s.insert(v[0]);
    int l{0}, r{0};

    while (l < n && r < n) {
        while ((*(next(s.end(), -1)) - *(s.begin()) <= 1 && r < n)) {
            ans = max(ans, r - l + 1);

            ++r;

            if (r < n && ++f[v[r]] == 1) {
                s.insert(v[r]);
            }
        }
        while (*(next(s.end(), -1)) - *(s.begin()) > 1) {
            if (--f[v[l]] == 0) {
                s.erase(v[l]);
            }

            ++l;
        }
    }

    cout << ans << '\n';
}
