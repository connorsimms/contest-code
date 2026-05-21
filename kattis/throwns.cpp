#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    string cmds; getline(cin, cmds); getline(cin, cmds);
    istringstream ss{ cmds };

    stack<int> s; s.push(0);

    string cmd;
    while (ss >> cmd)
    {
        int curr = s.top();

        if (cmd == "undo")
        {
            string num; ss >> num;

            for (int i = 0 ; i < stoi(num); ++i) s.pop();

        }
        else
        {
            int p = stoi(cmd);

            curr += p;

            while (curr < 0) curr += n;

            curr %= n;

            s.push(curr);
        }
    }

    cout << s.top() << '\n';
}
