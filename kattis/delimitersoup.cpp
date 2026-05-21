#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int n; cin >> n;

    string line; getline(cin, line); getline(cin, line);

    stack<char> s;

    for (int i = 0; i < n; ++i)
    {
        char x = line[i];

        if (x == ' ') 
        {
            continue; 
        }

        if (x == '(' || x == '[' || x == '{')
        {
            s.push(x);
            continue;
        }

        if (s.empty())
        {
            cout << x << " " << i << '\n'; 
            return 0;
        }

        if (x == ')' && s.top() == '(') { s.pop(); continue; } 
        if (x == ']' && s.top() == '[') { s.pop(); continue; } 
        if (x == '}' && s.top() == '{') { s.pop(); continue; } 

        if (x == ')' && s.top() != '(') { cout << x << " " << i << '\n'; return 0; } 
        if (x == ']' && s.top() != '[') { cout << x << " " << i << '\n'; return 0; } 
        if (x == '}' && s.top() != '{') { cout << x << " " << i << '\n'; return 0; } 
    }

    cout << "ok so far\n";
}
