#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, P;
  cin >> N >> P;

  int sum = 0;

  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    sum += x;
  }

  int x = N * P - sum;
  int y = 100 - P;

  if (y == 0) {
    cout << "impossible\n";
  } else {
    cout << x / y + (x % y != 0) << '\n';
  }
}
