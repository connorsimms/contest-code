#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> peg(N + 1, 1);
    int moves{};

    // auto hanoi = [&](auto &&rec, int n, int from, int to, int temp) -> void {
    //     if (n) {
    //         rec(rec, n - 1, from, temp, to);
    //         ++moves;
    //         peg[n] = to;

    //         cerr << moves << ": ";
    //         for (int i{1}; i <= N; ++i)
    //             cerr << peg[i] << ' ';
    //         cerr << endl;

    //         rec(rec, n - 1, temp, to, from);
    //     }
    // };

    // hanoi(hanoi, N, 1, 2, 3);

    vector<int> d(N);
    for (int i{}; i < N; ++i) {
        cin >> d[i];
    }

    int ans{};
    int from{1}, to{2}, temp{3};
    for (int i{N - 1}; i >= 0; --i) {
        if (d[i] == from) {
            swap(to, temp);
        } else if (d[i] == to) {
            swap(temp, from);
            ans += 1 << i;
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
}
