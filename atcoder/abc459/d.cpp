#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;

    int maxFreq = 0;

    array<int, 26> freq{};

    for (auto c : s) {
      ++freq[c - 'a'];

      maxFreq = max(maxFreq, freq[c - 'a']);
    }

    if (maxFreq * 2 <= s.size() + 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
      continue;
    }

    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < freq.size(); ++i) {
      char c = 'a' + i;
      int f = freq[i];

      if (f)
        pq.emplace(f, c);
    }

    string ans;
    ans.reserve(s.size());

    while (!pq.empty()) {
      auto [f1, c1] = pq.top();
      pq.pop();
      --f1;
      ans.push_back(c1);

      if (!pq.empty()) {
        auto [f2, c2] = pq.top();
        pq.pop();
        --f2;
        ans.push_back(c2);
        if (f2 > 0) {
          pq.emplace(f2, c2);
        }
      }

      if (f1 > 0) {
        pq.emplace(f1, c1);
      }
    }

    cout << ans << '\n';
  }
}
