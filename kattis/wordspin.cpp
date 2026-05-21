#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  vector<int> diff(s1.size());

  for (int i = 0; i < diff.size(); ++i) {
    diff[i] = s1[i] - s2[i];
  }

  long long ans = abs(diff[0]);

  for (int i = 1; i < diff.size(); ++i) {
    if (diff[i] > 0 && diff[i - 1] > 0 || diff[i] < 0 && diff[i - 1] < 0) {
      ans += max(abs(diff[i]) - abs(diff[i - 1]), 0);
    } else {
      ans += abs(diff[i]);
    }
  }

  cout << ans << '\n';
}
