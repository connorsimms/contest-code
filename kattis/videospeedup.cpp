#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, k; cin >> n >> p >> k;

    vector<int> t; t.push_back(0);
    for (int i = 0 ; i < n; ++i)
    {
        int ti; cin >> ti;
        t.push_back(ti);
    }
    t.push_back(k);

    double sum = 0.0;

    double mult = 1.0;

    for (int i = 1; i < t.size(); ++i)
    {
        sum += (t[i] - t[i - 1]) * mult;

        mult += (p / 100.0);
    }

    cout << fixed << setprecision(7) << sum << '\n';
}
