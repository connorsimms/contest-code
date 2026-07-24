#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main() {
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    string del = "";
    for (int i{}; i < n; ++i) {
        ll x;
        cin >> x;
        auto rem = ((x % b) * (a % b)) % b;
        auto save = rem / a;
        cout << del << save;
        del = " ";
    }
    cout << '\n';
}
