#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_map<string, int> freq;
    unordered_map<string, unordered_set<string>> used; 
    unordered_set<string> people;

    int n; cin >> n;
    string line; getline(cin, line);

    for (int i = 0 ; i < n; ++i)
    {
        string name; cin >> name;

        getline(cin, line);
        stringstream ss{ line };

        string word;
        while (ss >> word)
        {
            ++freq[word];
            used[word].insert(name);
            people.insert(name);
        }
    }

    vector<string> ans;
    
    for (auto& [word, peoples]: used)
    {
        if (peoples.size() == people.size())
        {
            ans.push_back(word); 
        }
    }

    if (ans.empty())
    {
        cout << "ALL CLEAR\n";
        return 0;
    }

    sort(ans.begin(), ans.end(), [&](const auto& A, const auto& B) {
        if (freq[A] != freq[B]) return freq[A] > freq[B];

        return A < B;
    });

    for (auto& x: ans)
    {
        cout << x << '\n';
    }
}
