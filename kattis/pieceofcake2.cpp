#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h, v; cin >> n >> h >> v;

    int x1 = max(n - h, h);
    int y1 = max(n - v, v);

    cout << 4* x1 * y1 << '\n';
}
