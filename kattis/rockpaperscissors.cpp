#include <vector>
#include <iomanip>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
    unordered_map<string, int> mtoi;
    mtoi["rock"] = 0;
    mtoi["paper"] = 1;
    mtoi["scissors"] = 2;
    int i = 0;
    int n, k; 
    while(cin >> n && n != 0) {
        if(i != 0) { cout << '\n'; }
        ++i;
        cin >> k;
        vector<int> wins(n);
        vector<int> loss(n);

        for (int i = 0 ; i < k * n * (n - 1) / 2; ++i)
        {
            int p1, p2;
            string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;
            --p1; --p2;
            int i1 = mtoi[m1];
            int i2 = mtoi[m2];

            if ( i1 == (i2 + 1) % 3 ) {
                wins[p1]++;
                loss[p2]++;
            } else if ( i2 == (i1 + 1) % 3 ) {
                wins[p2]++;
                loss[p1]++;
            }
        }

        for(int i = 0 ; i < n ; ++i)
        {
            if ( wins[i] + loss[i] != 0 ) {
                cout << fixed << setprecision(3) << (double)wins[i] / (wins[i] + loss[i]) << '\n';
            } else {
                cout << "-\n";
            }
        }
    }
}
