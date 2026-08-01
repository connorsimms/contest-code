#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k1, k2;
    cin >> n >> k1;
    queue<int> p1, p2;
    for (int i{}; i < k1; ++i) {
        int x;
        cin >> x;
        p1.push(x);
    }
    cin >> k2;
    for (int i{}; i < k2; ++i) {
        int x;
        cin >> x;
        p2.push(x);
    }

    int fights{};

    while (fights < 100'000'000 && !p1.empty() && !p2.empty()) {
        auto c1 = p1.front();
        p1.pop();
        auto c2 = p2.front();
        p2.pop();

        ++fights;

        if (c1 > c2) {
            p1.push(c2);
            p1.push(c1);
        } else {
            p2.push(c1);
            p2.push(c2);
        }
    }

    if (p1.empty()) {
        cout << fights << " 2\n";
    } else if (p2.empty()) {
        cout << fights << " 1\n";
    } else {
        cout << -1 << '\n';
    }
}
