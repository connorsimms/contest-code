#include <bits/stdc++.h>
using namespace std;

int main() {
  string ln;

  getline(cin, ln);

  string sr(ln);

  int num_c = 0;
  int inv = 0;
  int odd = 0;
  int evn = 0;

  for (int i = ln.size() - 1; i >= 0; --i) {
    if (ln[i] == 'C') {
      ++num_c;
    } else {
      inv += num_c;
      if (i % 2 == 0)
        ++evn;
      else
        ++odd;
    }
  }

  sort(sr.begin(), sr.end());

  int srt_odd = 0;
  int srt_evn = 0;

  for (int i = sr.size() - 1; i >= 0; --i) {
    if (sr[i] != 'P')
      break;

    if (i % 2 == 0)
      ++srt_evn;
    else
      ++srt_odd;
  }

  int x = abs(srt_evn - evn);

  cout << x + (inv - x) / 2;
}
