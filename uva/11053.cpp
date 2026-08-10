#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ull N, a, b;
    while (cin >> N && N) {
        cin >> a >> b;
        ull fast{}, slow{};

        for (;;) {
            fast = (((fast * fast) % N * a) % N + b) % N;
            fast = (((fast * fast) % N * a) % N + b) % N;
            slow = (((slow * slow) % N * a) % N + b) % N;

            if (slow == fast)
                break;
        }

        ull len{};
        for (;;) {
            fast = (((fast * fast) % N * a) % N + b) % N;
            ++len;

            if (slow == fast)
                break;
        }

        cout << N - len << '\n';
    }
}
