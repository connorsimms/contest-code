#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> cards(n);
    for(int i= 0 ; i < n ; ++i)
    {
	cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    bool consec = false;
    int score = 0;

    for(int i = 0 ; i < cards.size() - 1; ++i)
    {
	if(!consec) { score += cards[i]; }

	if(cards[i] == cards[i + 1] - 1) {
	    consec = true;
	} else {
	    consec = false;
	}

    }
    if(!consec) { score += cards[n- 1]; }

    cout << score << '\n';
}
