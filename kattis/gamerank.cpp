#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> stor(500);
    for(int i = 0 ; i < 15; ++i) { stor[i] = 25 - i/3; }
    for(int i = 15 ; i < 35; ++i) { stor[i] = 20 - (i-15)/4; }
    for(int i = 35 ; i < 60; ++i) { stor[i] = 15 - (i-35)/5; }
    for(int i = 60 ; i < 120; ++i) { stor[i] = 10 - (i-60)/6; }

    int streak = 0;
    int stars = 0;
    string line; getline(cin, line);
    for(int i = 0 ; i < line.size(); ++i)
    {
	if(stor[stars] == 0) { break; }
	//cout << stars << " " << stor[stars] << '\n';
	char game = line[i];
	if(game == 'W')
	{
	    ++streak;
	    if(streak >= 3 && stor[stars] <= 25 && stor[stars] >= 6) { 
		if(stor[stars + 2] < stor[stars]) { stars += 3; }
		else { stars += 2; }
	    } else { 
		if(stor[stars + 1] < stor[stars]) { stars += 2; }
		else { ++stars;  }
	    }
	}
	else 
	{
	    streak = 0;
	    if(stor[stars] <= 20) { 
		if(stor[stars-1] == 21) { continue; }
		if(stor[stars-1] > stor[stars] && stor[stars]) { stars -= 2; }
		else { --stars; }
	    }
	}
    }

    if(stor[stars] == 0) { cout << "Legend\n"; }
    else { cout << stor[stars] << '\n'; }
}
