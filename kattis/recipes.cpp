#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int T; cin >> T;
    for (int t = 1 ; t <= T ; ++t)
    {
        int R, P, D; cin >> R >> P >> D;

        double sw = 0.0;
        vector<pair<string, double>> ing;
        for (int i = 0 ; i < R ; ++i)
        {
            string name; cin >> name;
            double weight, perc; cin >> weight >> perc;

            ing.emplace_back(name, perc);

            if (abs(perc - 100.0) < 1e-6 ) {
                sw = weight * D / P;
            }
        }
        
        cout << "Recipe # " << t << '\n';
        cout << fixed << setprecision(1);
        for(auto p: ing)
        {
            cout << p.first << " " << (p.second / 100 * sw) << '\n';
        }
        for(int i = 0 ; i < 40; ++i) { cout << "-"; }
        cout << '\n';
    }
}
