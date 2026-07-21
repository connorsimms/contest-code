#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    vector<int> v(n);
    for (int i{}; i < n; ++i)
        fin >> v[i];

    sort(v.begin(), v.end());

    int ans{n + 1};

    for (int i{}; i < n; ++i) {
        int num = v.end() - upper_bound(v.begin(), v.end(), 2 * v[i]);

        ans = min(ans, num + i);
    }

    fout << ans << '\n';
}
