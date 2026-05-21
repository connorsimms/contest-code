#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int N, t; cin >> N >> t;

    vector<int> v(N);

    for (int i = 0 ; i < N; ++i)
    {
        cin >> v[i];
    }

    switch (t)
    {
    case 1:
    {
        unordered_set<int> seen;
        for (auto x: v)
        {
            if (seen.count(7'777 - x))
            {
                cout << "Yes\n";
                return 0;
            }

            seen.insert(x);
        }
        cout << "No\n";
        break;
    }
    case 2:
    {
        unordered_set<int> seen;
        for (auto x: v)
        {
            if (seen.count(x))
            {
                cout << "Contains duplicate\n";
                return 0;
            }

            seen.insert(x);
        }
        cout << "Unique\n";
        break;
    }
    case 3:
    {
        unordered_map<int, int> freq;
        for (auto x : v)
        {
            if (++freq[x] > N / 2)
            {
                cout << x << '\n';
                return 0;
            }
        }
        cout << -1 << '\n';
        break;
    }
    case 4:
    {
        sort(v.begin(), v.end());
        if (N % 2)
        {
            cout << v[N / 2] << '\n';
        }
        else
        {
            cout << v[N / 2 - 1] << ' ';
            cout << v[N / 2] << '\n';
        }
        break;
    }
    case 5:
    {
        sort(v.begin(), v.end());
        auto it1 = lower_bound(v.begin(), v.end(), 100);
        auto it2 = upper_bound(v.begin(), v.end(), 999);
        while (it1 != it2)
        {
            cout << *it1 << ' ';
            ++it1;
        }
        cout << '\n';
        break;
    }
    default: { break; }
    }
}
