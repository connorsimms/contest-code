#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cout << "Case #" << i << ": ";

    int P, K, L;
    cin >> P >> K >> L;

    vector<int> f(L);

    for (int i = 0; i < L; ++i) {
      cin >> f[i];
    }

    sort(f.rbegin(), f.rend());

    int c = 0;
    long long m = 1;
    long long ans = 0;

    for (auto x : f) {
      ans += m * x;
      ++c;

      if (c == K) {
        c = 0;
        ++m;
      }
    }

    cout << ans << '\n';
  }
}
