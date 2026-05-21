#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <deque>
using namespace std;

int main()
{
    int n; cin >> n;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<map<int, string>> level(101);
    unordered_map<string, int> infec;
    unordered_map<string, int> time;

    for (int i = 0 ; i < n ; ++i)
    {
        int cmd; cin >> cmd;

        switch(cmd)
        {
            case 0:
            {
                string name; int lvl;
                cin >> name >> lvl;

                infec[name] = lvl;
                time[name] = i;
                level[lvl][i] = name;
                break;
            }
            case 1:
            {
                string name; int inc;
                cin >> name >> inc;
                
                level[infec[name]].erase(time[name]);

                infec[name] += inc;

                level[infec[name]][time[name]] = name;
                break;
            }
            case 2:
            {
                string name; cin >> name;

                level[infec[name]].erase(time[name]);

                break;
            }
            case 3:
            {
                bool empty = true;
                for (int i = 100; i >= 0; --i)
                {
                    if (level[i].empty()) continue; 

                    cout << level[i].begin()->second << '\n';
                    empty = false;

                    break;
                }
                if (empty) cout << "The clinic is empty\n";
                break;
            }
        }
    }
}
