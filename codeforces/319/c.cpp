#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> isPrime(1001, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> p;
    for (int i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i]) continue;
        p.push_back(i);
        for (int j{i * i}; j < isPrime.size(); j += i) {
            isPrime[j] = false;
        }
    }

    vector<int> ans;

    for (auto prime : p) {
        auto pow = prime;
        while (pow <= n) {
            ans.push_back(pow);
            pow *= prime;
        }
    }

    cout << ans.size() << '\n';
    for (auto a : ans)
        cout << a << ' ';
    cout << '\n';
}
