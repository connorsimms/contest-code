#include <iostream>

using namespace std;

void solve() {
  int n, h;
  cin >> n >> h;

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    if (a > h)
      ++ans;

    ++ans;
  }

  cout << ans << '\n';
}

int main() { solve(); }
