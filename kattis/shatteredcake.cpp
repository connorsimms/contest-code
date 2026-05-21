#include <bits/stdc++.h>
using namespace std;

int main()
{
    int W; cin >> W;
    int N; cin >> N;
    int area = 0;
    for(int i = 0 ; i < N; ++i)
    {
	int w, l; cin >> w >> l;
	area += w * l;
    }
    cout << area / W << '\n';
}
