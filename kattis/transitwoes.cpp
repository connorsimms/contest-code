#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int s, t, n; cin >> s >> t >> n;

    vector<int> d(n + 1);
    for (int i = 0; i < n + 1; ++i) { cin >> d[i]; }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) { cin >> b[i]; }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) { cin >> c[i]; }

    int time = s;

    time += d[0];

    for (int i = 0 ; i < n ; ++i)
    {
        if ( time % c[i] != 0 ) 
        { 
            time += (c[i] - (time % c[i])); 
        }
        time += b[i];
        time += d[i + 1];
    }

    cout << (time <= t ? "yes\n": "no\n");
}
