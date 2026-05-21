#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> alph = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1",
        "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/",
        "}{", "`/", "2"};

    string inp; getline(cin, inp);
    for (auto& c: inp) {
        if (c >= 'A' && c <= 'Z')
            cout << alph[c - 'A'];
        else if (c >= 'a' && c <= 'z')
            cout << alph[c - 'a'];
        else
            cout << c;
    }
}
