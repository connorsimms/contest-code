#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> dif;
    bool poss = true;
    for (int i{}; i < n; ++i) {
        int g{-1}, s{-1};
        for (int j{}; j < m; ++j) {
            char c;
            cin >> c;
            if (c == 'G')
                g = j;
            else if (c == 'S')
                s = j;
        }
        if (g > s)
            poss = false;
        else if (s > g)
            dif.insert(s - g);
    }

    if (poss)
        cout << dif.size();
    else
        cout << -1;
    cout << '\n';
}
