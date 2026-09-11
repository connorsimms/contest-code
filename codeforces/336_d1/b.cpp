#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string A, B;
    cin >> A >> B;
    vector<int> nz(B.size()), no(B.size());

    int zcnt{};
    int ocnt{};
    for (int i{}; i < B.size(); ++i) {
        if (B[i] == '0')
            ++zcnt;
        else
            ++ocnt;
        nz[i] = zcnt;
        no[i] = ocnt;
    }

    ll ans{};
    for (int i{}; i < A.size(); ++i) {
        if (A[i] == '1') {
            ans += nz[B.size() - A.size() + i];
            if (i) ans -= nz[i - 1];
        } else {
            ans += no[B.size() - A.size() + i];
            if (i) ans -= no[i - 1];
        }
    }

    cout << ans << '\n';
}
