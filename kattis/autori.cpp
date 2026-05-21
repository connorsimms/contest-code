#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string line; getline(cin, line);
    auto curr = begin(line);
    cout << *curr;
    curr = find(curr + 1, end(line), '-');
    while (curr != end(line)) {
        cout << *(curr + 1);
        curr = find(curr + 1, end(line), '-');
    }
    cout << '\n';
}

