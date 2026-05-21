#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n; bool first = true;
    while (cin >> n && n != 0)
    {
        if (first)
            first = false;
        else
            cout << '\n';

        int s1 = 0, s2 = 0;

        for (int i = 0 ; i < n ; ++i)
        {
            string cmd; cin >> cmd;
            int x; cin >> x;
            
            if (cmd == "DROP")
            {
                cout << "DROP 2 " << x << '\n';
                s2 += x;
            }
            if (cmd == "TAKE")
            {
                while (x)
                {
                    int amt = min(x, s1);
                    if (amt)
                    {
                        cout << "TAKE 1 " << amt << '\n';
                        x -= amt;
                        s1 -= amt;
                    }
                    else
                    {
                        cout << "MOVE 2->1 " << s2 << '\n';
                        s1 = s2;
                        s2 = 0;
                    }
                }
            }
        }
    }
}
