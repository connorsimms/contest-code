#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n; cin >> n;

    stack<int> a, s;
    for (int i = 0 ; i < 2 * n ; ++i)
    {
        int x; cin >> x;
        a.push(x);
    }

    for (int i = 0 ; i < 2 * n ; ++i)
    {
        s.push(a.top());
        a.pop();
    }

    int moves = 0;
    while (!s.empty())
    {
        ++moves;

        if (!a.empty() && (a.top() == s.top()))
        {
            s.pop(); a.pop(); 
            continue;
        }

        a.push(s.top());
        s.pop();
    }

    if (!a.empty())
    {
        cout << "impossible\n";
    }
    else
    {
        cout << moves << '\n';
    }
}
