#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> C(N + 1), T(N + 1);

  for (int i = 2; i <= N; ++i)
    cin >> C[i];

  for (int i = 2; i <= N; ++i)
    C[i] += C[i - 1];

  for (int i = 1; i <= N; ++i)
    cin >> T[i];

  long long cost = 0;
  int time = 0;
  long long min_c = C[2] - C[1];

  for (int i = 2; i <= N; ++i) {
    cost += C[i] - C[i - 1];
    time += 1;

    if (C[i] - C[i - 1] < min_c) {
      min_c = C[i] - C[i - 1];
    }

    if (time < T[i]) {
      long long t = T[i] - time;
      long long num_b = t / 2 + t % 2;
      cost += num_b * (2 * min_c);
      time += num_b * 2;
    }
  }

  cout << cost << '\n';
}
