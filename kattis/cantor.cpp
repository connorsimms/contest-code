#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while(getline(cin, line))
    {
	if(line == "END") { break; }

	stringstream ss{ line };

	int num, denom;

	if(line.size() == 1)
	{
	    ss >> num;
	    denom = 1;
	} else {
	    char x, y;
	    ss >> x >> y;
	    ss >> num;
	    denom = pow(10, line.size() - 2);
	}

	unordered_set<int> seen;
	seen.insert(num);

	while(true)
	{
	    num *= 3;

	    if(num / denom == 1)
	    {
		cout << "NON-MEMBER\n";		
		break;
	    }

	    if(seen.count(num) == 0) { seen.insert(num); } 
	    else { 
		cout << "MEMBER\n"; 
		break;
	    }

	    num %= denom;
	}

    }
}
