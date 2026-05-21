#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, char> counter;
    counter['R'] = 'S';
    counter['B'] = 'K';
    counter['L'] = 'H';
    char m1 = '0', m2 = '0', m3 = '0';
    string moves; getline(cin, moves);
    int i = 0;
    while(i < moves.size())
    {
	char nextMove = moves[i++];
	//cout << m1 << m2 << m3 << ' ';
	if(m1 == '0') { m1 = nextMove; continue; }
	else if (m2 == '0') { m2 = nextMove; continue; }
	else if (m3 == '0') { m3 = nextMove; }

	if (m1 != m2 && m1 != m3 && m2 != m3) { 
	    cout << 'C'; 
	    m1 = '0'; m2 = '0'; m3 = '0';
	} else {
	    cout << counter[m1];
	    m1 = m2; m2 = m3; m3 = '0';
	}

	//cout << m1 << m2 << m3 << '\n';
    }
    if(m1!='0') { cout << counter[m1]; }
    if(m2!='0') { cout << counter[m2]; }
    cout << '\n';
}
