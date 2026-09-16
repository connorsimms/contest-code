#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> hap(N, vector<int>(3, 0)), mem(N, vector<int>(3, 0));

  for (int i{}; i < N; ++i) {
    for (int j{}; j < 3; ++j) {
      cin >> hap[i][j];
    }
  }

  mem[0][0] = hap[0][0];
  mem[0][1] = hap[0][1];
  mem[0][2] = hap[0][2];

  for (int i{}; i < N - 1; ++i) {
    mem[i + 1][0] = max(mem[i + 1][0], mem[i][1] + hap[i + 1][0]);
    mem[i + 1][0] = max(mem[i + 1][0], mem[i][2] + hap[i + 1][0]);

    mem[i + 1][1] = max(mem[i + 1][1], mem[i][0] + hap[i + 1][1]);
    mem[i + 1][1] = max(mem[i + 1][1], mem[i][2] + hap[i + 1][1]);

    mem[i + 1][2] = max(mem[i + 1][2], mem[i][0] + hap[i + 1][2]);
    mem[i + 1][2] = max(mem[i + 1][2], mem[i][1] + hap[i + 1][2]);
  }

  cout << max(mem[N - 1][0], max(mem[N - 1][1], mem[N - 1][2])) << '\n';
}
