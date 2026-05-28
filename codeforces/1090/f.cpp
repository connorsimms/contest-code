#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;

    vector<int> p(x + y + 1, 1);

    queue<int> odd;
    for (int i = 2; i <= x + y; ++i)
      odd.push(i);

    int numOdd = odd.size() + ((x + y) % 2 != 0);
    int numEvn = x + y - numOdd;

    while (numOdd > y && odd.size() >= 2) {
      int a = odd.front();
      odd.pop();
      int b = odd.front();
      odd.pop();

      --numOdd;
      ++numEvn;

      p[b] = a;
    }

    if (numEvn != x || numOdd != y) {
      cout << "NO\n";
      continue;
    } else {
      cout << "YES\n";
      for (int i = 2; i <= x + y; ++i)
        cout << i << " " << p[i] << '\n';
    }
  }
}
