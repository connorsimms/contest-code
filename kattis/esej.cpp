#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;

    string word("abcdefghi");

    int cnt = 0;

    cout << word;

    while (next_permutation(word.begin(), word.end()) && cnt < b - 1)
    {
        cout << " " << word;
        ++cnt;
    }
}
