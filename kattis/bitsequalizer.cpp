#include <bits/stdc++.h>
using namespace std;

int main()
{
    int C; cin >> C; int i = 1;
    while(i <= C)
    {
	string S, T; cin >> S >> T;

	int s0 = 0, s1 = 0, sq = 0;
	for(auto c: S) {
	    if(c == '0') { ++s0; }
	    if(c == '1') { ++s1; }
	    if(c == '?') { ++sq; }
	}
	int t0 = 0, t1 = 0;
	for(auto c: T) {
	    if(c == '0') { ++t0; }
	    if(c == '1') { ++t1; }
	}

	if(t0 > s0 + sq) { cout << "Case " << i << ": " << -1 << '\n'; }
	else {
	    int m1 = 0, m2 = 0, m3 = 0;
	    for(int j = 0 ; j < S.size(); ++j) { 
		if(S[j] == '?' && T[j] == '0' && s0 < t0) {
		    S[j] = '0'; ++s0; --sq; ++m2;
		}
		if(S[j] == '?' && T[j] == '1' && s1 < t1) {
		    S[j] = '1'; ++s1; --sq; ++m2;
		}
	    }
	    for(int j = 0 ; j < S.size(); ++j) { 
		if(S[j] == '0' && T[j] == '1' && s1 < t1) {
		    S[j] = '1'; ++s1; --s0; ++m1; 
		}
	    }
	    for(int j = 0 ; j < S.size(); ++j) { 
		if(S[j] == '0' && s1 < t1) {
		    S[j] = '1'; ++s1; --s0; ++m1; 
		}
	    }
	    for(int j = 0 ; j < S.size(); ++j) { 
		if(S[j] == '?' && s0 < t0) {
		    S[j] = '0'; ++s0; --sq; ++m2;
		}
		if(S[j] == '?' && s1 < t1) {
		    S[j] = '1'; ++s1; --sq; ++m2;
		}
	    }
	    int diff = 0;
	    for(int j = 0 ; j < S.size(); ++j) {
		diff += (T[j] != S[j]); 
	    }
	    m3 = diff / 2;
	    int ans = m1 + m2 + m3;
	    cout << "Case " << i << ": " << ans << '\n';
	}

	++i;
    }
}
