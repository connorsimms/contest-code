#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main()
{
    int n; cin >> n;

    string last; cin >> last;

    int turn = 2;
    int lost = 0;

    unordered_set<string> said;
    said.insert(last);

    for (int i =  0 ; i < n - 1; ++i)
    {
        string next; cin >> next;

        if (last.back() != next.front())
        {
            if (!lost) lost = turn; 
        }

        if (said.count(next))
        {
            if (!lost) lost = turn; 
        }

        said.insert(next);
        last = next;
        turn = 3 - turn;
    }

    if (lost)
    {
        cout << "Player " << lost << " lost\n";
    }
    else
    {
        cout << "Fair Game\n";
    }
}
