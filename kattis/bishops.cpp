#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sz(x) (int)(x).size()

int main()
{
    int x;
    while(cin >> x)
    {
	if(x < 2) { cout << x << '\n'; }
	else {
	    cout << x + (x - 2) << '\n';
	}
    }
}
