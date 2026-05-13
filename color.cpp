#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int S, C, K;
  cin >> S >> C >> K;

  vector<int> sock(S);
  for (int i = 0; i < S; ++i)
    cin >> sock[i];

  sort(sock.begin(), sock.end());

  int l = sock[0];
  int c = 1;
  int ans = 1;

  for (int i = 1; i < S; ++i) {
    if (sock[i] - l <= K && c < C) {
      ++c;
      continue;
    } else {
      ++ans;
      l = sock[i];
      c = 1;
    }
  }

  cout << ans << '\n';
}
