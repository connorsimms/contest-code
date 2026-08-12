#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(int n, int k, string s) {
    ll left{}, right{}, sum{}, numPairs{};
    ll totalPairs = ll(n) * ll(n);

    for (; right < min(n, k + 1); ++right) {
        if (s[right] == '1') {
            ++sum;
        }
    }

    numPairs += sum * sum;

    for (; right < n; ++left, ++right) {
        if (s[left] == '1')
            --sum;

        if (s[right] == '1') {
            numPairs += 2 * sum + 1;
            ++sum;
        }
    }

    ll numer = numPairs / gcd(numPairs, totalPairs);
    ll denom = totalPairs / gcd(numPairs, totalPairs);

    return to_string(numer) + "/" + to_string(denom);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        cout << solve(n, k, s) << '\n';
    }
}
