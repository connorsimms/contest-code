#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> nu(26), nl(26), hu(26), hl(26);

    for (auto c : a) {
        if (c >= 'a' && c <= 'z')
            ++nl[c - 'a'];
        else
            ++nu[c - 'A'];
    }

    for (auto c : b) {
        if (c >= 'a' && c <= 'z')
            ++hl[c - 'a'];
        else
            ++hu[c - 'A'];
    }

    int y{}, w{};

    for (char c{'a'}; c <= 'z'; ++c) {
        auto amt = min(nl[c - 'a'], hl[c - 'a']);
        y += amt;
        nl[c - 'a'] -= amt;
        hl[c - 'a'] -= amt;
    }

    for (char c{'A'}; c <= 'Z'; ++c) {
        auto amt = min(nu[c - 'A'], hu[c - 'A']);
        y += amt;
        nu[c - 'A'] -= amt;
        hu[c - 'A'] -= amt;
    }

    for (char c{'a'}; c <= 'z'; ++c) {
        auto amt = min(nl[c - 'a'], hu[c - 'a']);
        w += amt;
        nl[c - 'a'] -= amt;
        hu[c - 'a'] -= amt;
    }

    for (char c{'A'}; c <= 'Z'; ++c) {
        auto amt = min(nu[c - 'A'], hl[c - 'A']);
        w += amt;
        nu[c - 'A'] -= amt;
        hl[c - 'A'] -= amt;
    }

    cout << y << ' ' << w << '\n';
}
