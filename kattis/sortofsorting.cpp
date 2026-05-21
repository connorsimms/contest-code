#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n; bool first = true;
    while (cin >> n && n != 0)
    {
        vector<string> name(n);
        for (int i = 0 ; i < n ; ++i)
            cin >> name[i];

        stable_sort(name.begin(), name.end(), [](const auto& A, const auto& B) {
            if (A[0] != B[0]) return A[0] < B[0];
            if (A[1] != B[1]) return A[1] < B[1];
            return false;
        });

        if (!first) cout << '\n';
        first = false;

        for (auto n : name)
        {
            cout << n << '\n';
        }
    }
}
