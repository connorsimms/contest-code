#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int N; cin >> N;
    int ans = 0;
    unordered_map<int, int> arrows;
    for (int i = 0 ; i < N; ++i)
    {
        int H; cin >> H;

        if (arrows[H])
        {
            --arrows[H];
            ++arrows[H-1];
        }
         else
        {
            ++arrows[H-1];
            ++ans;
        }
    }
    cout << ans << '\n';
}
