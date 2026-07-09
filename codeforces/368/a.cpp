#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    bool bw = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c != 'W' && c != 'B' && c != 'G')
                bw = false;
        }
    }

    cout << (bw ? "#Black&White\n" : "#Color\n");
}
