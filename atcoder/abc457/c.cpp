#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  unsigned long long K;
  cin >> N >> K;
  --K;

  vector<vector<long long>> v(N);

  for (int i = 0; i < N; ++i) {
    int L;
    cin >> L;
    v[i].resize(L);
    for (int j = 0; j < L; ++j)
      cin >> v[i][j];
  }

  for (int i = 0; i < N; ++i) {
    unsigned long long C;
    cin >> C;

    unsigned long long L = v[i].size();

    if (K < C * L) {
      unsigned long long idx = K % L;
      cout << v[i][idx] << '\n';
      for (int j = i + 1; j < N; ++j) {
        int c;
        cin >> c;
      }
      break;
    } else {
      K -= C * L;
    }
  }
}
