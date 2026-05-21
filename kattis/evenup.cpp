#include <iostream>
using namespace std;

int main()
{
    stack<int> s;

    int n; cin >> n;

    for (int i = 0 ; i < n ; ++i)
    {
        int x; cin >> x;
        
        if (s.empty()) 
        {
            s.push(x);
            continue;
        }

        if ((x + s.top()) % 2 == 0)
        {
            s.pop();
        }
        else
        {
            s.push(x);
        }
    }

    cout << s.size() << '\n';
}
