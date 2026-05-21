#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> val(3);
    for(int i = 0 ; i < 3; ++i) {
	cin >> val[i];
    }

    sort(val.begin(), val.end());

    int d1 = val[1] - val[0];
    int d2 = val[2] - val[1];

    if(d1 < d2) { cout << val[1] + d1 << '\n'; }
    else if (d2 < d1) { cout << val[0] + d2 << '\n'; }
    else { cout << val[2] + d1 << '\n'; }
}
