#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, l; cin >> m >> l;
    int M, L; cin >> M >> L;
    int t_m, t_l; cin >> t_m >> t_l;

    bool ans = true;

    if(abs(m) + abs(M - m) + abs(l - M) + abs(L - l) <= min(t_m, t_l)) {
	cout << "possible\n"; return 0; }
    if(abs(l) + abs(L - l) + abs(m - L) + abs(M - m) <= min(t_m, t_l)) {
	cout << "possible\n"; return 0; }

    if(t_m < t_l) {
	int time = 0;
	if((0 <= l && l <= m && l < L) || (m <= l && l <= 0 && l > L)) {
	    l = m;
	} 
	time += abs(m) + abs(m - M);
	if(time > t_m) { ans = false; }
	time += abs(M - l) + abs(L - l);
	if(time > t_l) { ans = false; }
    } else if (t_l < t_m) {
	int time = 0;
	if((0 <= m && m <= l && m < M) || (l <= m && m <= 0 && m > M)) {
	    m = l; 
	} 
	time += abs(l) + abs(l - L);
	if(time > t_l) { ans = false; }
	time += abs(L - m) + abs(M - m);
	if(time > t_m) { ans = false; }
    } else { // move both before
	ans = false; 
    }

    cout << (ans ? "possible\n": "impossible\n");
}
