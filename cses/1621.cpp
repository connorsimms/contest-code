#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  set<int> s;

  for (int i{}; i < N; ++i) {
    int x;
    cin >> x;
    s.insert(x);
  }

  cout << s.size() << '\n';
}
