#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    while (N--)
    {
        char dir; cin >> dir;
        int dm, H, M; cin >> dm >> H >> M;

        int tot = H * 60 + M;

        if (dir == 'F') { tot += dm; }
        if (dir == 'B') { tot -= dm; }

        tot += 60 * 24;
        tot %= 60 * 24;
        
        cout << tot / 60 << " " << tot % 60 << '\n';
    }
}
