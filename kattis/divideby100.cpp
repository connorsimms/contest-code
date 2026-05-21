#include <iostream>
using namespace std;

int main()
{
    string n, m; cin >> n >> m;

    if (m.size() > n.size())
    {
        cout << "0.";
        for (int i = 0 ; i < m.size() - n.size() - 1; ++i)
        {
            cout << "0";
        }

        int rsz = n.size();
        for (int i = n.size() - 1; i >= 0 ; --i)
        {
            if (n[i] != '0' && n[i] != '.') break;

            --rsz; 
        }
        n.resize(rsz);
    }
    else
    {
        n.insert(n.end() - m.size() + 1, '.'); 

        int rsz = n.size();
        for (int i = n.size() - 1; i >= n.size() - m.size(); --i)
        {
            if (n[i] != '0' && n[i] != '.') break;

            --rsz;
        }
        n.resize(rsz);
    }


    cout << n << '\n';
}
