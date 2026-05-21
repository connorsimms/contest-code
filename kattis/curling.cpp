#include <bits/stdc++.h>

using namespace std;

int main()
{
    int score1 = 0;
    int score2 = 0;

    for(int r = 0; r < 10; r++) {
        int a_s; cin >> a_s;
        vector<long long> a(a_s);
        for(int i = 0; i< a_s; i++) {
            int x, y; cin >> x >> y;
            a[i] = (x-144)*(x-144) + (y-84)*(y-84);
        }

        sort(a.begin(), a.end());

        int b_s; cin >> b_s;
        vector<long long> b(b_s);
        for(int i = 0; i< b_s; i++) {
            int x, y; cin >> x >> y;
            b[i] = (x-144)*(x-144) + (y-84)*(y-84);
        }
        sort(b.begin(), b.end());
        
        //check this
        if((a_s == 0) && (b_s == 0))
            continue;
        else if((b_s == 0) || (a_s != 0 && b_s != 0 && a[0] < b[0])) { // a wins
            if(b_s == 0) {
                score1 += a_s;
                continue;
            }
            for(int i = 0; i < a_s; i++) {
                if(a[i] < b[0]) {
                    score1++;
                }
            }
        }
        else if((a_s == 0) || (a_s != 0 && b_s != 0 && b[0] < a[0])) { // b wins
            if(a_s == 0) {
                score2 += b_s;
                continue;
            }
            for(int i = 0; i < b_s; i++) {
                if(b[i] < a[0]) {
                    score2++;
                }
            }
        }

    }

    cout << score1 << " " << score2;
}
