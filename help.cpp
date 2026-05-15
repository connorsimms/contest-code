#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
      cin >> v[i];

    sort(v.begin(), v.end());

    long long a = 0, b = 0;

    cout << v[0] << "-A ";
    bool isA = false;

    for (int i = N - 1; i > 0; --i) {
      cout << v[i] << (isA ? "-A " : "-B ");
      isA = !isA;
    }

    cout << '\n';
  }
}
