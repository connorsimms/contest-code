#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        stringstream ss{ line };

        vector<int> v;

        int largest = 0;

        int x;
        while (ss >> x)
        {
            v.push_back(x);

            if (v.back() > largest) largest = v.back();
        }

        sort(v.rbegin(), v.rend());

        unordered_set<int> seen;

        bool valid = true;

        for (int i = 0 ; i < v.size() && valid; ++i)
        {
            for (int j = i + 1; j < v.size() && valid; ++j)
            {
                int diff = v[i] - v[j];

                if (seen.count(diff))
                {
                    valid = false;
                    cout << "not a ruler\n";
                    break;
                }

                seen.insert(diff);
            }
        }

        if (!valid) continue;

        for (int i = 1 ; i <= largest; ++i)
        {
            if (!seen.count(i))
            {
                valid = false;
            }
        }

        if (!valid) cout << "missing ";

        for (int i = 1 ; i <= largest; ++i)
        {
            if (!seen.count(i))
            {
                cout << i << ' ';
            }
        }

        if (valid) cout << "perfect";

        cout << '\n';
    }
}
