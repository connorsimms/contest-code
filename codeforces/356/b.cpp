#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    --a;
    int ans{};

    for (int d = 0; d < n; ++d) {
        int city{}, crim{};

        if (a - d >= 0) {
            ++city;
            if (c[a - d]) ++crim;
        }

        if (a + d < n && a + d != a - d) {
            ++city;
            if (c[a + d]) ++crim;
        }

        if (city == 2 && crim == 1)
            continue;

        ans += crim;
    }
    cout << ans << '\n';
}
