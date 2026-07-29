#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    int l{};
    while (k && l < s.size()) {
        int bestIdx = l;

        for (int i{l}; i < s.size(); ++i) {
            if (i - l <= k && s[i] > s[bestIdx]) {
                bestIdx = i;
            }
        }

        k -= bestIdx - l;

        for (int i{bestIdx}; i > l; --i) {
            swap(s[i], s[i - 1]);
        }

        ++l;
    }

    cout << s << '\n';
}
