#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> ans;
    for (int i{}; i < k; ++i) {
        int mxi{}, mni{};
        for (int j{}; j < n; ++j) {
            if (a[j] > a[mxi])
                mxi = j;
            if (a[j] < a[mni])
                mni = j;
        }
        if (a[mxi] <= a[mni] + 1)
            break;

        --a[mxi];
        ++a[mni];
        ans.emplace_back(mxi, mni);
    }

    int mxi{}, mni{};
    for (int j{}; j < n; ++j) {
        if (a[j] > a[mxi])
            mxi = j;
        if (a[j] < a[mni])
            mni = j;
    }
    auto ins = a[mxi] - a[mni];

    cout << ins << ' ' << ans.size() << '\n';
    for (auto [i, j] : ans)
        cout << i + 1 << ' ' << j + 1 << '\n';
}
