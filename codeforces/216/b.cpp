#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, L, R, SA, SK;
    cin >> N >> K >> L >> R >> SA >> SK;

    vector<int> v(N, L);
    int sa = N * L;
    int sk = K * L;

    while (sk < SK) {
        for (int i{0}; i < K && sk < SK; ++i) {
            ++sk;
            ++sa;
            ++v[i];
        }
    }

    while (sa < SA) {
        for (int i{K}; i < N && sa < SA; ++i) {
            ++sa;
            ++v[i];
        }
    }

    for (auto x : v)
        cout << x << ' ';
    cout << '\n';
}
