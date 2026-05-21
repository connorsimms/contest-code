#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n; cin >> n;
    queue<int> q;
    for (int i = 0 ; i < n ; ++i)
    {
        int x; cin >> x;
        if (q.empty() || x > q.back())
        {
            q.push(x);
        }
    }
    cout << q.size() << '\n';
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
}
