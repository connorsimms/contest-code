#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string non = "";
    int tot{};
    bool anyZ{};

    for (int i{}; i < n; ++i) {
        string x;
        cin >> x;

        if (x == "0") anyZ = true;

        else if (x != "1") {
            if (x.front() != '1' || find_if(x.begin() + 1, x.end(), [](auto c) { return c != '0'; }) != x.end())
                non = x;
            else
                tot += x.size() - 1;
        }
    }

    if (anyZ) {
        cout << 0 << '\n';
        return 0;
    }

    if (non.empty())
        cout << "1";
    else
        cout << non;

    cout << string(tot, '0') << '\n';
}
