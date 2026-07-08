#include <iostream>
using namespace std;

int main() {
  int k, r;

  cin >> k >> r;

  int tot = k;

  int ans{1};

  while (tot % 10 != 0 && tot % 10 != r) {
    tot += k;
    ++ans;
  }

  cout << ans << '\n';
}
