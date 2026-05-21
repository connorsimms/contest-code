#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<string> cards;
    vector<int> count(4, 13); // p, k , h, t
    unordered_map<char, int> stoi; 
    stoi['P'] = 0;
    stoi['K'] = 1;
    stoi['H'] = 2;
    stoi['T'] = 3;
    string line;
    getline(cin, line);
    for(int i = 0 ; i < line.size() - 2; i += 3)
    {
	string card = line.substr(i, 3);
	if(cards.count(card)) {
	    cout << "GRESKA\n";
	    return 0;
	} else {
	    cards.insert(card);
	    //cout << card << " " << card[0] << " " << stoi[card[0]] << '\n';
	    --count[stoi[card[0]]];
	}
    }
    for(auto x: count)
    {
	cout << x << " ";
    }
    cout << '\n';
}
