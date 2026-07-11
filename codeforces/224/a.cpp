#include <bits/stdc++.h>
using namespace std;

int main() {
    string l, r;

    string w, u;
    cin >> w >> u;
    bool left = true;
    for (int i = 0; i < w.size(); ++i) {
        if (w[i] == '|') {
            left = false;
            continue;
        }

        if (left)
            l.push_back(w[i]);
        else
            r.push_back(w[i]);
    }

    auto diff = abs(int(r.size()) - int(l.size()));
    if (diff <= u.size() && ((diff & 1) == (u.size() & 1))) {
        for (auto c : u) {
            if (l.size() <= r.size())
                l.push_back(c);
            else
                r.push_back(c);
        }

        cout << l << '|' << r << '\n';
    } else {
        cout << "Impossible\n";
    }
}
