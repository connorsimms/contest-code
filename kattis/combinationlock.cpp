#include <bits/stdc++.h>

using namespace std;

int clockwise(int start, int end) {
    return (start - end < 0) ? start - end + 40 : start - end;
}

int counter(int start, int end) {
    return (end - start < 0) ? end - start + 40 : end - start;
}

int main()
{
    int x0, a, b, c;
    while(cin >> x0 >> a >> b >> c) {
        if(x0 == 0 && a == 0 && b == 0 && c == 0) { break; }
        int dx;
        int totalDeg;
        
        totalDeg = 720;
	//cout << totalDeg << '\n';
        
        totalDeg += clockwise(x0, a) * 9;
	//cout << totalDeg << '\n';
        
        totalDeg += 360;
	//cout << totalDeg << '\n';
        
        totalDeg += counter(a, b) * 9;
	//cout << totalDeg << '\n';
        
        totalDeg += clockwise(b, c) * 9;
	//cout << totalDeg << '\n';
        
        cout << totalDeg << '\n';
    }
}
