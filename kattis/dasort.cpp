#include <bits/stdc++.h>
using namespace std;

int main() {
  int P;
  cin >> P;
  while (P--) {
    int K, N;
    cin >> K >> N;

    cout << K << " ";

    vector<int> v(N);

    for (int i = 0; i < N; ++i)
      cin >> v[i];

    auto s(v);

    sort(s.begin(), s.end());

    int c = 0;

    for (int i = 0, j = 0; i < N && j < N;) {
      if (s[i] == v[j]) {
        ++c;
        ++i;
        ++j;
      } else
        ++j;
    }

    cout << N - c << '\n';
  }
}
