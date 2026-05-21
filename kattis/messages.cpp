#include <unordered_set>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  string w;

  unordered_set<string> words;

  while (cin >> w && w != "#")
  {
    words.insert(w); 
  }
  
  string line;
  getline(cin, line);

  string x = "";

  while (getline(cin, line) && line != "#")
  {
    string_view sv(line);
    if (line.back() == '|') sv.remove_suffix(1);
    x.append(sv);

    if (line.back() == '|')
    {
      vector<pair<int, int>> y;

      for (int i = 0 ; i < x.size(); ++i)
      {
        for (int j = 1; (i + j <= x.size()) && (j <= 10); ++j)
        {
          string sub = x.substr(i, j);

          if (words.count(sub))
          {
            y.emplace_back(i, i + j - 1); 
          }
        }
      }

      sort(y.begin(), y.end(), [](const auto& A, const auto& B) {
        if (A.second == B.second) return A.first < B.first;
        return A.second < B.second;
      });

      int ans = 0;
      int pos = -1;

      for (auto& [a, b]: y)
      {
        if (a > pos)
        {
          ++ans;
          pos = b;
        }
      }

      cout << ans << '\n';

      x.clear();
    }
  }

  return 0;
}
