#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool ans = false;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x != y) ans = true;
        v[i] = x;
    }

    bool sorted = std::is_sorted(v.rbegin(), v.rend());

    if (ans) {
        cout << "rated\n";
    } else {
        if (sorted)
            cout << "maybe\n";
        else
            cout << "unrated\n";
    }
}
