#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    
    while(getline(cin, line)) {
	if(line == "0") { cout << 2 << '\n'; continue; }
	if(line == "1") { cout << 1 << '\n'; continue; }

        if(line == "END") { break; }

	int prev = line.size();
	int i = 1;

	while(true) {
	    string currStr = to_string(prev);
	    int curr = currStr.size();
	    ++i;

	    //cout << prev << " " << curr << '\n';
	    if(curr == 0) { break; }
	    if(curr == prev) { break; }
	    prev = curr;
	}
	cout << i << '\n';
    }
}



