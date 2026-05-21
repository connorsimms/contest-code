#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int N; cin >> N;

        vector<int> v(3 * N);
        for (int i = 0 ; i < 3 * N; ++i)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        deque<int> d;

        for (auto x : v)
        {
            d.push_back(x);
        }

        int S = 0;
        while (!d.empty())
        {
            d.pop_front(); d.pop_back(); 

            S += d.back();

            d.pop_back();
        }

        cout << S << '\n';
    }
}
