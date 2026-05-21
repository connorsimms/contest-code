#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> mtoi;
    mtoi["th"] = 0;     mtoi["thou"] = 0;
    mtoi["in"] = 1;     mtoi["inch"] = 1;
    mtoi["ft"] = 2;     mtoi["foot"] = 2;
    mtoi["yd"] = 3;     mtoi["yard"] = 3;
    mtoi["ch"] = 4;     mtoi["chain"] = 4;
    mtoi["fur"] = 5;    mtoi["furlong"] = 5;
    mtoi["mi"] = 6;     mtoi["mile"] = 6;
    mtoi["lea"] = 7;    mtoi["league"] = 7;

    vector<int> conv = {1, 1000, 12, 3, 22, 10, 8, 3};

    double v; cin >> v; 
    string u1, in, u2; cin >> u1 >> in >> u2;

    int u1idx = mtoi[u1];
    int u2idx = mtoi[u2];

    if ( u1idx < u2idx ) {
        for (int i = u1idx + 1; i <= u2idx ; ++i)
        {
            v /= conv[i];
        }
    } else if ( u1idx > u2idx ) {
        for (int i = u2idx + 1; i <= u1idx ; ++i)
        {
            v *= conv[i];
        }
    } 
    cout << setprecision(10) << v << '\n';
}
