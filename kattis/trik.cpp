#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<bool> cups(3);
    cups[0] = true;

    string moves; getline(cin, moves);
    for(auto move: moves)
    {
	if(move == 'A') { swap(cups[0], cups[1]); }
	if(move == 'B') { swap(cups[1], cups[2]); }
	if(move == 'C') { swap(cups[0], cups[2]); }
    }

    for(int i = 0 ; i < 3; ++i)
    {
	if(cups[i]) { cout << i + 1 << '\n'; break; }
    }
}
