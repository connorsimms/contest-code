#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, t; cin >> N >> t;
    vector<int> A(N);
    for(int i = 0 ; i < N ; ++i)
    {
	cin >> A[i];
    }

    switch(t) {
	case 1: {
	    cout << 7 << '\n';
	    break;
	}
	case 2: {
	    if(A[0] > A[1]) { cout << "Bigger\n"; }
	    if(A[0] == A[1]) { cout << "Equal\n"; }
	    if(A[0] < A[1]) { cout << "Smaller\n"; }
	    break;
	}
	case 3: {
	    vector<int> temp = {A[0], A[1], A[2]};
	    sort(temp.begin(), temp.end());
	    cout << temp[1] << '\n';
	    break;
	}
	case 4: {
	    long long sum = 0; for(auto x: A) { sum += x; } 
	    cout << sum << '\n';
	    break;
	}
	case 5: {
	    long long sum = 0; for(auto x: A) { sum += ((x % 2 == 0) ? x : 0); }
	    cout << sum << '\n';
	    break;
	}
	case 6: {
	    for(auto& x: A) { x %= 26; }
	    for(auto x: A) { cout << (char)('a' + x); }
	    cout << '\n';
	    break;
	}
	case 7: {
	    int i = 0;
	    unordered_map<int, bool> seen;
	    seen[i] = true;
	    while(true) {
		i = A[i];
		if(i == N - 1) { cout << "Done\n"; break; }
		if(i < 0 || i > N - 1) { cout << "Out\n"; break; }
		if(seen[i]) { cout << "Cyclic\n"; break; }

		seen[i] = true;
	    }
	    break;
	}
	default: {
	    break;
	}
    }
}


