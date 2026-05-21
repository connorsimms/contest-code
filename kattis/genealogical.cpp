#include <iostream>
#include <functional>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    string input;
    
    unordered_map<string, set<string>> par;
    unordered_map<string, set<string>> chi;
    unordered_map<string, string> bir;
    unordered_map<string, string> dea;

    bool first = true;

    while (cin >> input && input != "QUIT")
    {
        string info; getline(cin, info);

        if (input == "BIRTH")
        {
            size_t idx1 = 0;
            size_t idx2 = info.find(':', idx1);

            string child = info.substr(idx1 + 1, idx2 - idx1 - 2);

            idx1 = idx2 + 1;
            idx2 = info.find(':', idx1);

            string date = info.substr(idx1 + 1, idx2 - idx1 - 2);

            idx1 = idx2 + 1;
            idx2 = info.find(':', idx1);

            string moth = info.substr(idx1 + 1, idx2 - idx1 - 2);

            idx1 = idx2 + 1;
            idx2 = info.size();

            string fath = info.substr(idx1 + 1, idx2 - idx1 - 1);

            par[child].insert(fath); par[child].insert(moth);
            chi[fath].insert(child); chi[moth].insert(child);
            bir[child] = date;
        }
        if (input == "DEATH")
        {
            size_t idx1 = 0;
            size_t idx2 = info.find(':', idx1);

            string person = info.substr(idx1 + 1, idx2 - idx1 - 2);

            idx1 = idx2 + 1;
            idx2 = info.size();

            string date = info.substr(idx1 + 1, idx2 - idx1 - 1);

            dea[person] = date;

        }
        if (input == "ANCESTORS")
        {
            if (!first) { cout << '\n'; }
            else { first = false; }

            string person = info.substr(1);
            string ind = "  ";
            cout << "ANCESTORS of " << person << '\n';

            std::function<void(string)> dfs = [&](string person) {
                cout << ind << person;
                if (bir.count(person))
                {
                    cout << " " << bir[person] << " -";
                    if (dea.count(person)) { cout << " " << dea[person]; }
                }
                cout << '\n';

                for (auto parent : par[person])
                {
                    ind += "  ";
                    dfs(parent);
                    ind = ind.substr(0, ind.size() - 2);
                }
            };

            for (auto parent: par[person])
            {
                dfs(parent);
            }
        }
        if (input == "DESCENDANTS")
        {
            if (!first) { cout << '\n'; }
            else { first = false; }

            string person = info.substr(1);
            string ind = "  ";
            cout << "DESCENDANTS of " << person << '\n';

            std::function<void(string)> dfs = [&](string person) {
                cout << ind << person;
                if (bir.count(person))
                {
                    cout << " " << bir[person] << " -";
                    if (dea.count(person)) { cout << " " << dea[person]; }
                }
                cout << '\n';

                for (auto child : chi[person])
                {
                    ind += "  ";
                    dfs(child);
                    ind = ind.substr(0, ind.size() - 2);
                }
            };

            for (auto child: chi[person])
            {
                dfs(child);
            }
        }
    }
}
