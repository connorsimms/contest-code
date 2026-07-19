#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum{};
    for (int i{}; i < n; ++i) {
        int x;
        cin >> x;
        pq.push(x);
        sum += x;
    }

    for (int i{}; i < k; ++i) {
        auto t = pq.top();
        sum -= 2 * t;
        pq.pop();
        pq.push(-1 * t);
    }

    cout << sum << '\n';
}
