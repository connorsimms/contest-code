#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  int N;
  cin >> N;
  string del = "";
  for (int i = N; i >= 1; --i)
    cout << del << i, del = ",";
}
