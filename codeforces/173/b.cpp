#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    ll as{};

    for (int i{}; i < n; ++i) {
        int a, g;
        cin >> a >> g;
        as += a;
    }

    if (as % 1000 <= 500) {
        int ng = as / 1000;
        int na = n - ng;
        cout << string(na, 'A');
        cout << string(ng, 'G');
        cout << '\n';
    } else {
        int ng = as / 1000 + 1;
        int na = n - ng;
        cout << string(na, 'A');
        cout << string(ng, 'G');
        cout << '\n';
    }
}
