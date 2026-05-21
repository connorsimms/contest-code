#include <iostream>
#include <cmath>
#include <unordered_map>
#include <functional>

using namespace std;

int main()
{
    string digs = "0123456789ACDEFHJKLMNPRTVWX";
    unordered_map<char, int> val;

    for(int i = 0 ; i < digs.size() ; ++i)
    {
        val[digs[i]] = i;
    }

    auto check = [&](string num) {
        return ((   2 * val[num[0]] + 4 * val[num[1]] + 5 * val[num[2]] + 
                    7 * val[num[3]] + 8 * val[num[4]] + 10 * val[num[5]] + 
                    11 * val[num[6]] + 13 * val[num[7]] ) % 27 );
    };

    int t; cin >> t;
    while (t--)
    {
        int k; cin >> k; cout << k << " ";

        string dat; cin >> dat;

        string num = dat.substr(0,8);
        int c = check(num);

        if (val[dat[8]] != c) { cout << "Invalid\n"; continue; }
        
        long long v = 0;
        for (int i = 0 ; i < num.size(); ++i)
        {
            v += (powl(27, i) * val[num[num.size() - 1 - i]]);
        }

        cout << v << '\n';
    }
}
