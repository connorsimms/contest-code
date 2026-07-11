#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string del = "";
    vector<int> h(2 * n + 1);
    for (int i = 0; i < 2 * n + 1; ++i)
        cin >> h[i];

    int num = 0;
    cout << h.front();
    for (int i = 1; i < 2 * n; ++i) {
        if ((i & 1) == 1 && num < k) {
            if (min(h[i] - h[i - 1], h[i] - h[i + 1]) > 1) {
                cout << ' ' << h[i] - 1;
                ++num;
                continue;
            }
        }
        cout << ' ' << h[i];
    }
    cout << ' ' << h.back() << '\n';
}
