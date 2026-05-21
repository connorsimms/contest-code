#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    int K; cin >> K;

    unordered_map<string, int> seenPos;
    unordered_set<string> seen;
    unordered_map<string, bool> found;

    int already = 0;
    for(int i = 0 ; i < K ; ++i)
    {
	int c1, c2; cin >> c1 >> c2;
	string p1, p2; cin >> p1 >> p2;
	seen.insert(p1); seen.insert(p2); // keeping track of all card types seen

	if(seenPos[p1] == 0) { seenPos[p1] = c1; }
	if(seenPos[p2] == 0) { seenPos[p2] = c2; }

	if(p1 == p2) { 
	    found[p1] = true; // already found, can't find ourselves
	}
	if(seenPos[p1] != 0 && seenPos[p1] != -1 && seenPos[p1] != c1) {
	    seenPos[p1] = -1;
	}
	if(seenPos[p2] != 0 && seenPos[p2] != -1 && seenPos[p2] != c2) {
	    seenPos[p2] = -1; // identifier for we know both positions
	}
    }

    int ans = 0;
    int alr = 0;
    for(auto s: seen)
    {
	if(found[s]) { ++alr; }
	else if(seenPos[s] == -1) { ++ans; }
    }

    if((seen.size() == N / 2 - 1) && (ans + alr == N / 2 - 1)) { ++ans; }
    if(seen.size() == N / 2) { ans = N / 2 - alr; }

    cout << ans << '\n';
}
