#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i{}; i < n; ++i)
        cin >> a[i];
    for (int i{}; i < n; ++i)
        cin >> b[i];
    int i{}, j{}, ans{};
    vector<bool> seen(n + 1);

    while (i < n && j < n) {
        if (seen[a[i]]) {
            ++i;
            continue;
        }

        if (seen[b[j]]) {
            ++j;
            continue;
        }

        if (a[i] == b[j]) {
            ++i, ++j;
            continue;
        }

        ++ans;
        seen[b[j]] = true;
        ++j;
    }

    cout << ans << '\n';
}
