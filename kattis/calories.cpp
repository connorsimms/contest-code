#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    //fat pro sug star alc
    vector<int> cpg = {9, 4, 4, 4, 7};
    string line;
    double cals = 0;
    double fat = 0;
    while(getline(cin, line))
    {
        //cout << cals << " " << fat << '\n';
        //cout << line << '\n';
        if (line == "-") { 
            if (abs(cals) > 1e-6) {
                cout << (int)(100 * fat / cals + 0.5) << "%\n";
                cals = 0;
                fat = 0;
            } else {
                return 0;
            }
        }

        stringstream ss{ line };
        int percent = 100;
        double calsKnown = 0;
        int fp = 0;

        for (int i = 0; i < 5 ; ++i)
        {
            //cout << calsKnown << " " << percent << "\n";
            int x; char y;
            ss >> x >> y;

            if (y == 'g') { 
                calsKnown += x * cpg[i]; 
                if (i == 0) { fat += x * cpg[i]; }
            }
            if (y == 'C') { 
                calsKnown += x; 
                if (i == 0) { fat += x; }
            }
            if (y == '%') { 
                percent -= x; 
                if (i == 0) { fp = x; }
            }
        }

        cals += calsKnown * 100 / percent;
        fat += calsKnown * fp / percent;
    }
}



