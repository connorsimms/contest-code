#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    bool hl = false, al = false;
    int hs = 0, as = 0;
    int ht = 0, at = 0;
    int pt = 0;

    for (int i = 0 ; i < n ; ++i)
    {
        char team; cin >> team;
        int pnt; cin >> pnt;

        int min; cin >> min;
        char dl; cin >> dl;
        string secs; cin >> secs;

        int sec = (secs[0] - '0') * 10 + (secs[1] - '0');

        int time = 60 * min + sec;
        int addTime = time - pt;

        if (hl) { ht += addTime; }
        if (al) { at += addTime; }

        if (team == 'H') { hs += pnt; }
        if (team == 'A') { as += pnt; }

        hl = hs > as;
        al = as > hs;

        pt = time;
    }

    if (hl) { ht += 32 * 60 - pt; }
    if (al) { at += 32 * 60 - pt; }

    cout << (as > hs ? "A " : "H ");
    cout << ht / 60 << ":";
    if (ht % 60 < 10) { cout << "0" << ht % 60 << " "; }
    else { cout << ht % 60 << " "; }

    cout << at / 60 << ":";
    if (at % 60 < 10) { cout << "0" << at % 60 << " "; }
    else { cout << at % 60 << " "; }
}
