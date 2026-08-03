#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<bool> isPrime(10000001, true);
vector<ull> p;
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (ull i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i])
            continue;

        for (ull j{i * i}; j < isPrime.size(); j += i) {
            isPrime[j] = false;
        }

        p.push_back(i);
    }
}

int main() {
    sieve();

    ull N;
    while (cin >> N) {
        if (N < 8) {
            cout << "Impossible.\n";
            continue;
        }

        bool poss = false;
        vector<ull> ans(4);

        if (N & 1) {
            ans[0] = 2, ans[1] = 3;
            N -= 5;
        } else {
            ans[0] = ans[1] = 2;
            N -= 4;
        }

        for (auto prime : p) {
            if (prime > N)
                break;

            if (isPrime[N - prime]) {
                ans[2] = prime;
                ans[3] = N - prime;
                poss = true;
                break;
            }
        }

        if (poss) {
            cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
        } else {
            cout << "Impossible.\n";
        }
    }
}
