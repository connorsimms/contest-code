#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> count;
    int maxcount = 0;
    for(int i = 0 ; i < 5; ++i)
    {
	string card; cin >> card;
	maxcount = max(maxcount, ++count[card[0]]);
    }

    cout << maxcount << '\n';
}
