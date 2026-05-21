#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> moIdx;
    moIdx["JAN"] = 0; moIdx["FEB"] = 1;
    moIdx["MAR"] = 2; moIdx["APR"] = 3;
    moIdx["MAY"] = 4; moIdx["JUN"] = 5;
    moIdx["JUL"] = 6; moIdx["AUG"] = 7;
    moIdx["SEP"] = 8; moIdx["OCT"] = 9;
    moIdx["NOV"] = 10; moIdx["DEC"] = 11;
    unordered_map<string, int> dayIdx;
    dayIdx["MON"] = 0; dayIdx["TUE"] = 1;
    dayIdx["WED"] = 2; dayIdx["THU"] = 3;
    dayIdx["FRI"] = 4; dayIdx["SAT"] = 5;
    dayIdx["SUN"] = 6;

    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int d; string mo; cin >> d >> mo; --d;
    string jan1; cin >> jan1;
    

    int tot = accumulate(days.begin(), days.begin() + moIdx[mo], 0); 
    int ltot = accumulate(leap.begin(), leap.begin() + moIdx[mo], 0); 
    tot += d;
    ltot += d;

    if (tot == 0 && jan1 != "FRI") { cout << ":(\n"; return 0; }

   // cout << tot + dayIdx[jan1] << '\n';
   // cout << (tot + dayIdx[jan1]) % 7 << '\n';

    if ((((tot + dayIdx[jan1]) % 7) == 4) && (((ltot + dayIdx[jan1]) % 7) == 4)) { cout << "TGIF\n"; }
    else if ((((tot + dayIdx[jan1]) % 7) == 4) || (((ltot + dayIdx[jan1]) % 7) == 4)) { cout << "not sure\n"; }
    else { cout << ":(\n"; }
}
