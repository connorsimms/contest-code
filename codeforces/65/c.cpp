#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i{}; i < n; ++i) {
        cin >> k[i];
    }

    bool poss = false;

    for (int i{1}; i * 2 < n; ++i) {
        if (n % i != 0)
            continue;

        for (int j{}; j < i; ++j) {
            bool valid = true;
            auto l{j};
            do {
                if (!k[l]) {
                    valid = false;
                    break;
                }
                l += i;
                l %= n;
            } while (l != j);

            if (valid) {
                poss = true;
                break;
            }
        }
    }

    cout << (poss ? "YES\n" : "NO\n");
}
