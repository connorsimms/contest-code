#include <bits/stdc++.h>

using namespace std;

int solve(int ds, int ys, int dm, int ym)
{
    unordered_set<int> sunYears;

    for(int i = ys - ds; i <= 5000; i += ys) { // 7, 17, 27, 37, ... (<= 5000)
        sunYears.insert(i);
    }    

    for(int i = ym - dm; i <= 5000; i += ym) { // 1, 3, 5, 7
        if(sunYears.count(i) != 0) { return i; }
    }
    return 0;
}

int main()
{
    int ds, ys; 
    cin >> ds >> ys;
    int dm, ym; 
    cin >> dm >> ym;

    cout << solve(ds, ys, dm, ym) << '\n';
    return 0; 
}


