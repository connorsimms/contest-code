#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T;
    int cntr = 0;
    while (cin >> T && T != 0)
    {
        if (cntr++ != 0) { cout << '\n'; }

        vector <int> times(T);

        for (int i = 0 ; i < T; ++i)
        {
            int h; char dlm; int m;
            cin >> h >> dlm >> m;

            string info; cin >> info;

            if (h == 12) { h -= 12; }

            if (info == "p.m.") { h += 12; }

            times[i] = h * 60 + m;    
        }

        sort(times.begin(), times.end());

        for (auto t: times)
        {
            string hour, min, info;
            
            hour = to_string((t / 60) % 12);
            min = to_string(t % 60);
            info = ((t >= 60 * 12) ? "p.m." : "a.m.");

            if (((t / 60) % 12) == 0) { hour = "12"; }

            if (min.size() == 1) { min.insert(0, "0"); }

            cout << hour << ":" << min << " " << info << '\n';
        }
    }
}
