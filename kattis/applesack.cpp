#include <iostream>
using namespace std;

int main()
{
  int n, k; cin >> n >> k;

  int ans = 0;

  if (n == 0)
  {
    cout << 1 << '\n';
    return 0;
  }

  if (k == 1) 
  {
    cout << 2 << '\n';
    return 0;
  }

  while (n > k)
  {
    int x = n / k;
    int y = n % k;

    n -= x + (y != 0);

    ++ans;
  }

  ans += n + 1;

  cout << ans << '\n';
}
