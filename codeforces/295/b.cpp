#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dist(20001, -1);
    dist[n] = 0;
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        if (f - 1 >= 0 && dist[f - 1] == -1) {
            dist[f - 1] = dist[f] + 1;
            q.push(f - 1);
        }

        if (f * 2 <= 20000 && dist[f * 2] == -1) {
            dist[f * 2] = dist[f] + 1;
            q.push(f * 2);
        }
    }

    cout << dist[m] << '\n';
}
