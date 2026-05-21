#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<bool> ops;

    vector<bool> vals(26);

    int n; cin >> n;

    for (int i = 0 ; i < n; ++i)
    {
        char v; cin >> v;
        vals[i] = (v == 'T');
    }

    char x;
    while (cin >> x)
    {
        if (x >= 'A' && x <= 'Z')
        {
            ops.push(vals[x - 'A']); 
            continue;
        }

        switch (x)
        {
            case '*':
            {
                bool a = ops.top(); ops.pop();
                bool b = ops.top(); ops.pop();
                ops.push((a && b));
                break;
            }
            case '+':
            {
                bool a = ops.top(); ops.pop();
                bool b = ops.top(); ops.pop();
                ops.push((a || b));
                break;
            }
            case '-':
            {
                bool a = ops.top(); ops.pop();
                ops.push((!a));
                break;
            }
        }
    }

    cout << (ops.top() ? "T\n" : "F\n");
}
