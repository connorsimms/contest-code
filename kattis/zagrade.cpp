#include <bits/stdc++.h>
using namespace std;

int main()
{
    string expr; getline(cin, expr);

    vector<int> id(expr.size(), -1);

    stack<int> s;

    int num = 0;

    for (int i = 0; i < expr.size(); ++i)
    {
        if (expr[i] == '(')
        {
            id[i] = num++;

            s.push(id[i]);
        }

        if (expr[i] == ')')
        {
            id[i] = s.top();
            
            s.pop();
        }
    }

    set<string> ans;

    for (int i = 0 ; i < (1 << num) - 1; ++i)
    {
        string w;
        for (int j = 0 ; j < expr.size(); ++j)
        {
            if (expr[j] != '(' && expr[j] != ')')
            {
                w.push_back(expr[j]);
                continue;
            }

            if ((1 << id[j]) & i)
            {
                w.push_back(expr[j]);
            }
        }
        if (!w.empty()) ans.insert(w);
    }

    for (auto& x: ans)
    {
        cout << x << '\n';
    }
}
