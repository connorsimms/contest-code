#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> cards;
    string str; cin >> str;
    for(auto c: str) {
	++cards[c];
    }
    int mc = min(cards['T'], cards['C']);
    mc = min(mc, cards['G']);

    cout << cards['T'] * cards['T'] + cards['C'] * cards['C'] + cards['G'] * cards['G'] +
    7 * mc << '\n';
}
