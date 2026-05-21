#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n; cin >> n;
    while (n--) {
        string line; cin >> line;
        int s = sqrt(line.size());
        
        string result = "";
        for (int j = 0 ; j < s; ++j)
        {
            for (int i = s - 1 ; i >= 0; --i)
            {
                int idx = i * s + j; 
                result.push_back(line[idx]);
            }
        }
        reverse(result.begin(), result.end());

        cout << result << '\n';
    }
}
