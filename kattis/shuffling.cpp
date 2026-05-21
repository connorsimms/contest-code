#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n; string type; cin >> type;
    vector<int> deck(n);
    vector<int> nextDeck(n);
    iota(deck.begin(), deck.end(), 0);
    int ans = 0;

    if(type == "in") {
	int idx = n / 2;
	while(true) {
	    if(is_sorted(deck.begin(), deck.end()) && ans != 0) { break; }
	    for(int i = 0 ; i < idx ; ++i)
	    {
		nextDeck[i*2 + 1] = deck[i];
	    }
	    for(int i = idx ; i < n ; ++i)
	    {
		nextDeck[(i - idx) * 2] = deck[i];
	    }
	    ++ans;
	    deck = nextDeck;
	}
    } else { // out
	int idx = n / 2 + n % 2;
	while(true) {
	    if(is_sorted(deck.begin(), deck.end()) && ans != 0) { break; }
	    for(int i = 0 ; i < idx ; ++i)
	    {
		nextDeck[i*2] = deck[i];
	    }
	    for(int i = idx ; i < n ; ++i)
	    {
		nextDeck[(i - idx) * 2 + 1] = deck[i];
	    }
	    ++ans;
	    deck = nextDeck;
	}
    }
    cout << ans << '\n';
}
