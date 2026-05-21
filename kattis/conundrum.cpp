#include <iostream>
using namespace std;

int main()
{
    string input; cin >> input;
    int count = 0;
    for (int i = 0 ; i < input.size(); i += 3) { count += (input[i] != 'P'); }
    for (int i = 1 ; i < input.size(); i += 3) { count += (input[i] != 'E'); }
    for (int i = 2 ; i < input.size(); i += 3) { count += (input[i] != 'R'); }
    cout << count << '\n';
}
