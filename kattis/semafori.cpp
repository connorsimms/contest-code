#include <iostream>
using namespace std;

int main()
{
    int N, L; cin >> N >> L;
    int t = 0;
    int l = 0;
    for (int i = 0 ; i < N ; ++i)
    {
        int D, R, G; cin >> D >> R >> G;
        
        t += (D - l);
        l = D;

        if (t % (R + G) <= R) { t += R - (t % (R + G)); }
    }

    t += (L - l);

    cout << t << '\n';
}
