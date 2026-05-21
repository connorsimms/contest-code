#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        map<string, long long> bill;
        unordered_map<string, string> car;

        unordered_map<string, int> price;
        unordered_map<string, int> pickup;
        unordered_map<string, int> cpk;

        int n, m; cin >> n >> m;

        for (int i = 0; i < n; ++i)
        {
            string name; cin >> name;

            cin >> price[name];
            cin >> pickup[name];
            cin >> cpk[name];
        }

        for (int i = 0; i < m; ++i)
        {
            int t; string s; char e;
            cin >> t >> s >> e;

            switch (e)
            {
                case 'p':
                {
                    string c; cin >> c;

                    if (!price.count(c)) bill[s] = -1;

                    if (car.count(s)) bill[s] = -1;

                    if (bill[s] == -1) break;

                    bill[s] += pickup[c];

                    car[s] = c;

                    break;
                }
                case 'r':
                {
                    int d; cin >> d;

                    if (!car.count(s)) bill[s] = -1;

                    if (bill[s] == -1) break;

                    bill[s] += cpk[car[s]] * d;

                    car.erase(s);

                    break;
                }
                case 'a':
                {
                    int sev; cin >> sev;

                    if (!car.count(s)) bill[s] = -1;

                    if (bill[s] == -1) break;

                    bill[s] += (int)(ceil(price[car[s]] / 100.0 * sev - 0.001) + 0.001);
                    break;
                }
            }
        }
        for (auto [spy, amt] : bill)
        {
            cout << spy << " ";
            if (car.count(spy) || bill[spy] == -1)
            {
                cout << "INCONSISTENT\n";
            }
            else
            {
                cout << bill[spy] << '\n';
            }
        }
    }
}
