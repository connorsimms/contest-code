#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;

    int ownR, ownG, ownB;
    cin >> ownR >> ownG >> ownB;

    int srg, sgb;
    cin >> srg >> sgb; 

    int needR = max(0, r - ownR);
    int needG = max(0, g - ownG);
    int needB = max(0, b - ownB);

    if(needR > 0) 
    {
	if(srg < needR) { cout << "-1\n"; return 0; }
	srg -= needR;
    }

    if(needB > 0) 
    {
	if(sgb < needB) { cout << "-1\n"; return 0; }
	sgb -= needB;
    }
    
    if(needG > 0) 
    {
	if(srg + sgb < needG) { cout << "-1\n"; return 0; }
	
    }

    cout << needR + needG + needB << '\n';
}
