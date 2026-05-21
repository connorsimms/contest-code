#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    vector<string> t = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> o = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    unordered_map<string, int> tens;
    unordered_map<string, int> ones;

    for (int i = 1 ; i < 10; ++i) { tens[t[i-1]] = i; ones[o[i-1]] = i; }

    string input; cin >> input;
    string best = input;

    sort(input.begin(), input.end());

    int lowest = 101;

    do {
        for (int i = 0 ; i < input.size(); ++i)
        {
            string tn = input.substr(0, i);
            string on = input.substr(i);

            if ((tens.count(tn) != 0 || tn.size() == 0) && (ones.count(on) != 0 || on.size() == 0))
            {
                if (tens[tn] * 10 + ones[on] < lowest)
                {
                    lowest = tens[tn] * 10 + ones[on];
                    best = input;
                }
            }
        }
    } while (next_permutation(input.begin(), input.end()));

    cout << best;
}

