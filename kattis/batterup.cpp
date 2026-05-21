#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    double sum = 0;
    int count = 0;

    for(int i  = 0 ; i < n ; ++i)
    {
	int x; cin >> x;
	if(x != -1) { sum += x; ++count; }
    }

    cout << fixed << setprecision(6) << sum / count << '\n';
}
