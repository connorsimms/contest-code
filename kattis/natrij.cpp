#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ch, cm, cs;
    int fh, fm, fs;
    char dlm;
    cin >> ch >> dlm >> cm >> dlm >> cs;
    cin >> fh >> dlm >> fm >> dlm >> fs;

    int tt1 = 60 * 60 * ch + 60 * cm + cs;
    int tt2 = 60 * 60 * fh + 60 * fm + fs;

    if (tt1 == tt2) { cout << "24:00:00\n"; return 0; }

    int diff = (tt2 - tt1 + 60 * 60 * 24) % (60 * 60 * 24);

    string h = to_string(diff / 60 / 60);
    diff %= 3600;
    string m = to_string(diff / 60);
    diff %= 60;
    string s = to_string(diff);

    if (h.size() == 1) { h.insert(0, "0"); }
    if (m.size() == 1) { m.insert(0, "0"); }
    if (s.size() == 1) { s.insert(0, "0"); }

    cout << h << ":" << m << ":" << s << '\n';
}
