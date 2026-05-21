#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
    map<int, priority_queue<int>, greater<int>> quests;

    int n; cin >> n;
    for (int i = 0 ; i < n; ++i)
    {
        string cmd; cin >> cmd;
        if (cmd == "add")
        {
            int e, g;
            cin >> e >> g;

            quests[e].push(g);
        }
        if (cmd == "query")
        {
            int e; cin >> e;

            auto it = quests.lower_bound(e);

            long long gold = 0;

            while (it != quests.end() && !it->second.empty() && e > 0)
            {
                e -= it->first;
                gold += it->second.top();
                it->second.pop();

                if (it->second.empty())
                {
                    quests.erase(it);
                }

                it = quests.lower_bound(e);
            }
            
            cout << gold << '\n';
        }
    }
}
