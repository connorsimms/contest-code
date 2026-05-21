#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<string> rem;

    string line; getline(cin, line);

    int spaces = count(line.begin(), line.end(), ' ');
    int len = spaces + 1;

    int n; cin >> n;
    for (int i = 0 ; i < n; ++i)
    {
        string name; cin >> name; rem.push_back(name);
    }

    auto it = rem.begin();

    vector<string> t1, t2;

    bool team1 = true;

    while (!rem.empty())
    {
        for (int i = 0 ; i < len - 1; ++i)
        {
            if (it == rem.end())
            {
                it = rem.begin();
            }

            ++it;
        }

        if (it == rem.end())
        {
            it = rem.begin();
        }

        if (team1)
        {
            t1.push_back(*it); 
        }
        else
        {
            t2.push_back(*it); 
        }

        team1 = !team1;

        auto toRemove = it;
        ++it;

        rem.erase(toRemove);
    }

    cout << t1.size() << '\n';
    for (auto x: t1)
    {
        cout << x << '\n';
    }

    cout << t2.size() << '\n';
    for (auto x: t2)
    {
        cout << x << '\n';
    }
}
