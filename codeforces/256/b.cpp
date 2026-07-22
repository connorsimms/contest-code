#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    auto subseq = [](const auto &str, const auto &sub) {
        size_t i{}, j{};
        while (i < str.size() && j < sub.size()) {
            if (str[i] == sub[j])
                ++j;
            ++i;
        }
        return j == sub.size();
    };

    auto perm = [](auto &a, auto &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    };

    if (subseq(s, t)) {
        cout << "automaton\n";
        return 0;
    }

    if (perm(s, t)) {
        cout << "array\n";
        return 0;
    }

    if (subseq(s, t)) {
        cout << "both\n";
        return 0;
    }

    cout << "need tree\n";
}
