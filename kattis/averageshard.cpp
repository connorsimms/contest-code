#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    int cases;
    cin >> cases;
    rep(c, 0, cases) {
	int ncs, ne;
	cin >> ncs >> ne;

	ll tcs = 0;
	ll tne = 0;

	vi cs;
	vi e;

	rep(i, 0, ncs) {
	    int x;
	    cin >> x;
	    cs.push_back(x);
	    tcs += x;
	}

	rep(i, 0, ne) {
	    int x;
	    cin >> x;
	    e.push_back(x);
	    tne += x;
	}

	int cnt = 0;

	for(auto p: cs) {
	    if(p < (double)tcs / ncs && p > (double)tne / ne) {
		++cnt; 
	    }
	}

	cout << cnt << '\n';
    }
}
