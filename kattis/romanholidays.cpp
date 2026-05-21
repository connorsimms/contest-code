#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> TH = {"M", ""};
    vector<string> O = {"IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I", ""};
    vector<string> T = {"XC", "LXXX", "LXX", "LX", "L", "XL", "XXX", "XX", "X", ""};
    vector<string> H = {"CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C", ""};

    reverse(TH.begin(), TH.end()); 
    reverse(H.begin(), H.end()); 
    reverse(T.begin(), T.end()); 
    reverse(O.begin(), O.end()); 

    unordered_map<string, int> val;
    vector<string> list;
    vector<string> sortedList;

    for (int j = 0 ; j < H.size(); ++j)  
    {
        for (int k = 0 ; k < T.size(); ++k)  
        {
            for (int l = 0 ; l < O.size(); ++l)  
            {
                int v = 100 * j + 10 * k + l;
                string num = H[j] + T[k] + O[l];
                val[num] = v;
                list.push_back(num);
                sortedList.push_back(num);
            }
        }
    }

    list.push_back("M");
    sortedList.push_back("M");
    val["M"] = 1000;

    unordered_map<int, int> valToPos;
    sort(sortedList.begin(), sortedList.end());

    for (int i = 0 ; i < sortedList.size(); ++i)
    {
        valToPos[val[sortedList[i]]] = i;
    }


    int idxM = valToPos[1000];

    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;

        if (x == 1000) { cout << idxM << '\n'; continue; }

        int numM = x / 1000;

        if (x > 1000) {
            x %= 1000;
        }

        int pos = valToPos[x];

        if (pos > idxM) {
            int diff = 1000 - idxM;
            pos = pos - 1001;
            pos -= (diff * numM);
        } else {
            pos += idxM * numM;
        }

        cout << pos << '\n';
    }
}
