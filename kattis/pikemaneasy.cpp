#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, T; cin >> N >> T;

  long long A, B, C, t; cin >> A >> B >> C >> t;

  int solved = 0;
  long long pen = 0;

  vector<long long> v(N); v[0] = t;

  for (int i = 1; i < N; ++i)
  {
    v[i] = (((A * v[i - 1]) % C) + B) % C + 1;
  }

  sort(v.begin(), v.end());

  long long tot = 0;
  for (int i = 0; i < N; ++i)
  {
    if (tot + v[i] <= T)
    {
      tot += v[i];
      ++solved;
      pen += tot;
      pen %= 1'000'000'007;
    }
    else
    {
      break;
    }
  }

  cout << solved << " " << pen << '\n';
}
