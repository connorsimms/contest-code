#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i{}; i < n; ++i)
        cin >> v[i];

    if (is_sorted(v.begin(), v.end())) {
        cout << "yes\n";
        cout << "1 1\n";
        return 0;
    }

    int i{0};

    while (i < n - 1 && v[i] < v[i + 1]) { ++i; }

    auto x = i;

    while (i < n - 1 && v[i] > v[i + 1]) { ++i; }

    auto y = i;

    cerr << x << ' ' << y << endl;

    reverse(v.begin() + x, v.begin() + y + 1);

    for (auto a : v)
        cerr << a << ' ';
    cerr << endl;

    if (is_sorted(v.begin(), v.end())) {
        cout << "yes\n";
        cout << x + 1 << ' ' << y + 1 << '\n';
    } else {
        cout << "no\n";
    }
}
