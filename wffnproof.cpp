#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
  string line;
  while (getline(cin, line) && line != "0")
  {
    queue<char> o, O;
    int N = 0;

    string wff; wff.reserve(line.size());

    for (auto x : line)
    {
      if (x == 'p' || x == 'q' || x == 'r' || x == 's' || x == 't')
      {
        o.push(x);
      }
      if (x == 'K' || x == 'A' || x == 'C' || x == 'E')
      {
        O.push(x);
      }
      if (x == 'N')
      {
        ++N;
      }
    }

    if (o.empty())
    {
      cout << "no WFF possible\n";
      continue;
    }
    
    wff.push_back(o.front());
    wff.append(N, 'N');
    o.pop();

    while (!o.empty() && !O.empty())
    {
      wff.push_back(o.front());
      wff.push_back(O.front());
      O.pop(); o.pop();
    }

    reverse(wff.begin(), wff.end());
    cout << wff << '\n';
  }
  return 0;
}
