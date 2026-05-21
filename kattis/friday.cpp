#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int D, M; cin >> D >> M;
        vector<int> mDays(M);
        for (int i = 0 ; i < M ; ++i)
        {
            cin >> mDays[i];
        }

        int res = 0;
        int day = 0; // sunday
        for (int i = 0 ; i < M; ++i)
        {
            for ( int j = 0 ; j < mDays[i]; ++j)
            {
                day %= 7;
                if (j == 12 && day == 5)
                {
                    res++;
                }
                day++;
            }
        }
        cout << res << '\n';
    }
}
