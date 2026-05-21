#include <bits/stdc++.h>
using namespace std;

int main()
{
    string born = "20000101";

    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int t; cin >> t;
    while (t--)
    {
        string x, y, z; cin >> x >> y >> z;

        string date = x + y + z;
        sort(date.begin(), date.end());

        int count = 0;
        string earliest = "";

        do
        {
            if (date < born) continue;

            int y = stoi(date.substr(0, 4));
            int m = stoi(date.substr(4, 2));
            int d = stoi(date.substr(6, 2));

            if (m < 1 || m > 12) continue;

            bool leap;

            if (y % 400 == 0) leap = true;
            else if ((y % 100 == 0) && (y % 400 != 0)) leap = false;
            else if ((y % 4 == 0) && (y % 100 != 0)) leap = true;
            else if (y % 4 != 0) leap = false;

            if (leap) days[1]++;

            if (d < 1 || d > days[m - 1]) 
            {
                if (leap) --days[1];
                continue;
            }

            if (earliest == "") earliest = date;
            ++count;

            if (leap) --days[1];

        } while (next_permutation(date.begin(), date.end()));

        cout << count;
        if (count ) cout << " " << earliest.substr(6, 2) << " " << earliest.substr(4, 2) << " " << earliest.substr(0, 4);
        cout << '\n';
    }
}
