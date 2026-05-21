#include <iostream>
using namespace std;

int main()
{
    string s1, s2; cin >> s1 >> s2;
    for (int i{1}; i < s1.size(); i += 2)
    {
        int offset = ((s1[i] - 'A') + (s2[i] - 'A')) % 26;
        s1[i] = 'A' + offset;
    }
    for (int i{}; i < s1.size(); i += 2)
    {
        int offset = (26 + (s1[i] - 'A') - (s2[i] - 'A')) % 26;
        s1[i] = 'A' + offset;
    }
    cout << s1 << '\n';
}
