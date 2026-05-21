#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    double c; cin >> c;

    cout << setprecision(10) << min((double)s.size(), c) << '\n';
}
