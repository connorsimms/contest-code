#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<bool> food(366); 

    int n; cin >> n; 
    for (int i = 0 ; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        fill(food.begin() + a, food.begin() + 1 + b, true);
    }

    cout << count(food.begin() + 1, food.end(), true) << '\n';
}
