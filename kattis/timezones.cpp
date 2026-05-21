#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> utc;

    utc["UTC"] = 0;
    utc["GMT"] = 0; 
    utc["BST"] = 60; 
    utc["IST"] = 60;
    utc["WET"] = 0; 
    utc["WEST"]= 60;
    utc["CET"] = 60; 
    utc["CEST"]= 120; 
    utc["EET"] = 120; 
    utc["EEST"]= 180; 
    utc["MSK"] = 180; 
    utc["MSD"] = 240; 
    utc["AST"] = -240;
    utc["ADT"] = -180;
    utc["NST"] = -210;
    utc["NDT"] = -150;
    utc["EST"] = -300;
    utc["EDT"] = -240;
    utc["CST"] = -360;
    utc["CDT"] = -300;
    utc["MST"] = -420;
    utc["MDT"] = -360;
    utc["PST"] = -480;
    utc["PDT"] = -420;
    utc["HST"] = -600;
    utc["AKST"]= -540;
    utc["AKDT"]= -480;
    utc["AEST"]= 600;
    utc["AEDT"]= 660;
    utc["ACST"]= 570;
    utc["ACDT"]= 630;
    utc["AWST"]= 480;

    int t; cin >> t;
    while (t--)
    {
        int M = 0;
        string time; cin >> time;
        if (time == "noon")
        {
            M = 12 * 60; 
        }
        else if (time == "midnight")
        {
            
        }
        else
        {
            stringstream ss { time };
            int h, m; char d;
            ss >> h >> d >> m;
            M = h * 60 + m;

            string td; cin >> td;
            if (td[0] == 'a')
            {
                if (h == 12) { M -= h * 60; }
            } else
            {
                if (h != 12) { M += 60 * 12; }
            }
        }

        string tzi, tzf; cin >> tzi >> tzf;
        //cout << M << " " << utc[tzi] << " " << utc[tzf] << '\n';
        M -= utc[tzi];
        M += utc[tzf];
        M += 24 * 60;
        M %= 24 * 60;

        if (M == 0) { cout << "midnight\n"; }
        else if (M == 12 * 60) { cout << "noon\n"; }
        else {
            int H = M / 60;
            if ( H == 0 ) { H = 12; }
            else if (H > 12) { H -= 12; }

            string hour = to_string(H);
            string mn = to_string(M % 60);

            if ((int)mn.size() == 1)
            {
                mn.insert(0, "0");
            }

            if (hour == "0") { hour = "12"; }

            if (M >= 720)
            {
                cout << hour << ":" << mn << " p.m.\n";
            }
            else
            {
                cout << hour << ":" << mn << " a.m.\n";
            }
        }
    }
}
