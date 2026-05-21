#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s; cin >> s;
    int n; cin >> n;

    int time = 0;
    bool blew = false;

    for(int i = 0 ; i < n ; ++i)
    {
	int dt; cin >> dt;
	char q; cin >> q;

	time += dt;

	if(time >= 210 && !blew) { cout << s << '\n'; blew = true; }

	if(q == 'T') { s = (s % 8) + 1; }
    }
}
