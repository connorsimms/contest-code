#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int A, B, C; cin >> A >> B >> C;
    unordered_map<int,int> m;
    unordered_map<int,int> c;
    c[0] = 0; c[1] = A; c[2] = B; c[3] = C;
    for (int i = 0 ; i < 3 ; ++i)
    {
        int x, y; cin >> x >> y;
        m[x]++; m[y]--;
    }

    int cost = 0;
    int cnt = 0;
    for (int i = 0 ; i <= 100; ++i)
    {
        cnt += m[i];
        cost += cnt * c[cnt];
    }

    cout << cost << '\n';
}
