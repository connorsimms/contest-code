#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, v1, v2; cin >> s >> v1 >> v2;

    for(int i = s / v1; i >= 0; --i)
    {
	if((s - i * v1) % v2 == 0) { cout << i << " " << (s - i * v1) / v2 << '\n'; return 0; }
    }

    cout << "Impossible\n";
}
