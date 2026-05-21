#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    priority_queue<int> books{};
    int totalCost = 0;

    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        totalCost += x;
        books.push(x);
    }

    int numSaved = n / 3;
    
    for(int i = 0 ; i < numSaved ; ++i)
    {
        books.pop();
        books.pop();
        totalCost -= books.top();
        books.pop();
    }

    cout << totalCost;

    return 0;
}

