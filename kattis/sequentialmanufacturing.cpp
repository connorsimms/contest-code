#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, P;
    cin >> N >> P;
    
    vector<int> times(N);
    
    int maxTime = 0;
    int maxIdx = 0;
    
    for(int i = 0 ; i < N; ++i) {
        cin >> times[i];
        if(maxTime < times[i]) {
            maxTime = times[i];
            maxIdx = i;
        }
    }

    int minSpace = 1e9 + 1;
    int minIdx = 0;
    for(int i = 1 ; i <= N - 1; ++i) {
	int x;
	cin >> x;
	if(x < minSpace && i < maxIdx) {
	    minIdx = i;
	    minSpace = x;
	}
    }
    
    long long preload = 0;
    for(int i = 0 ; i < maxIdx; ++i) {
        preload += times[i];
    }

    long long reload = 0;
    for(int i = 0 ; i < minIdx; ++i) {
	reload += times[i];
    }

    long long sum = preload;

    sum += maxTime * P;

    sum += (P / minSpace) * reload;

    cout << sum << '\n';
}
