#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    int x = 0;
    int y = 0;

    bool ans = true;

    for(int i = 0 ; i < n ; ++i)
    {
	int b; cin >> b;
	x += b;

	if(x == w) { x = 0; ++y; }
	if(x >= w) { ans = false; }
    }

    if(y < h) { ans = false; }

    cout << (ans ? "YES\n" : "NO\n");
}
