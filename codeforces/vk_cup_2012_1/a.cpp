#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (size_t i{}; i < v.size(); ++i)
        cin >> v[i];

    sort(v.rbegin(), v.rend());

    vector<int> w;

    for (size_t i{}; i < v.size(); ++i) {
        if (v[i] > 0 && w.size() < k) {
            w.push_back(v[i]);

            if (w.size() == k) {
                for (size_t j{i + 1}; j < v.size(); ++j) {
                    if (v[j] == w.back())
                        w.push_back(v[j]);
                }
                break;
            }
        }
    }

    cout << w.size() << '\n';
}
