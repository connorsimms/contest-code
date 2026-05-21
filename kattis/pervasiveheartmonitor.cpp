#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string line; string name = ""; string data{};
    while (getline(cin , line))
    {
        if (line[0] >= 'A' && line[0] <= 'z') {
            auto it = find_if(begin(line), end(line), [](char x) { return x >= '0' && x <= '9'; });
            name = string(begin(line), it); 
            data = string(it, end(line));
        } else {
            auto it = find_if(begin(line), end(line), [](char x) { return x >= 'A' && x <= 'z'; });
            data = string(begin(line), it); 
            name = string(it, end(line));
        }

        stringstream ss{ data };
        double hr = 0; int cnt = 0; double x;
        while (ss >> x) {
            hr += x; ++cnt;
        }
        
        cout << fixed << setprecision(7) << hr / cnt << " " << name;
        cout << '\n';
    }
}
