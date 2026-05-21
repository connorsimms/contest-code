#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int oct = accumulate(md.begin(), md.begin() + 9, 0);
    oct += 26;

    set<int> c;

    int t; cin >> t;
    while (t--)
    {
        string name; cin >> name;
        string date; cin >> date;
        stringstream ss{ date };

        char deli;
        int m, d; ss >> m >> deli >>  d;
        --m; --d;
        
        int td = accumulate(md.begin(), md.begin() + m, 0);
        td += d;

        c.insert(td);
    }

    if (c.size() == 1)
    {
        auto it = c.begin();

        int ans = ((*it - 1 + 365) % 365);
        int m = 0;
        int rem = ans;

        while (rem >= md[m])
        {
            rem -= md[m];
            ++m;
        }

        string mo = to_string(m + 1);
        string dy = to_string(rem + 1);

        if (mo.size() == 1) { mo.insert(0, "0"); }
        if (dy.size() == 1) { dy.insert(0, "0"); }

        cout << mo << '-' << dy << '\n';

        return 0;
    }

    int maxD = 0;
    int ans = 0;
    int sz = (int)c.size();
    for (int i = 0 ; i < sz; ++i)
    {
        int i1 = (i + 1) % sz;
        auto it1 = c.begin(); advance(it1, i1);
        auto it2 = c.begin(); advance(it2, i);
        int diff = *it1 - *it2; 
        diff += 365;
        diff %= 365;

        int cand = *it1 - 1;
        cand += 365;
        cand %= 365;

        if (diff == maxD)
        {
            int octD1 = cand - oct - 1; 
            int octD2 = ans - oct - 1; 
            octD1 += 365; octD1 %= 365;
            octD2 += 365; octD2 %= 365;

            if (octD1 < octD2)
            {
                ans = cand;
            }
        }
        if (diff > maxD)
        {
            maxD = diff;
            ans = cand;
        }
    }

    int m = 0;
    int rem = ans;

    while (rem >= md[m])
    {
        rem -= md[m];
        ++m;
    }

    string mo = to_string(m + 1);
    string dy = to_string(rem + 1);

    if (mo.size() == 1) { mo.insert(0, "0"); }
    if (dy.size() == 1) { dy.insert(0, "0"); }

    cout << mo << '-' << dy << '\n';
}
