#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int numA = 0, numB = 0, numQ = 0;

    for (int i = 0; i < n; ++i) {
      switch (s[i]) {
      case 'a':
        ++numA;
        break;
      case 'b':
        ++numB;
        break;
      case '?':
        ++numQ;
        break;
      }
    }

    bool poss = true;

    int i = 0;

    if (n % 2 == 1) {
      if (s[0] == 'b') {
        poss = false;
      } else if (s[0] == '?') {
        s[0] = 'a';
        ++numA;
        --numQ;
      }
      ++i;
    }

    for (; i < n && poss; i += 2) {
      if (s[i] == 'a') {
        if (s[i + 1] == 'a')
          poss = false;
        else if (s[i + 1] == '?') {
          s[i + 1] = 'b';
          ++numB;
          --numQ;
        }
      }
      if (s[i] == 'b') {
        if (s[i + 1] == 'b')
          poss = false;
        else if (s[i + 1] == '?') {
          s[i + 1] = 'a';
          ++numA;
          --numQ;
        }
      }
      if (s[i] == '?') {
        if (s[i + 1] == 'a') {
          s[i] = 'b';
          ++numB;
          --numQ;
        }
        if (s[i + 1] == 'b') {
          s[i] = 'a';
          ++numA;
          --numQ;
        }
      }
    }

    int aLeft = n / 2 + n % 2 - numA;
    int bLeft = n / 2 - numB;

    if (aLeft < 0 || bLeft < 0 || aLeft != bLeft || aLeft + bLeft != numQ)
      poss = false;

    if (poss)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
