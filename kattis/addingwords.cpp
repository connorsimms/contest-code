#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string cmd;
    unordered_map<string, int> valOf;
    unordered_map<int, string> varOf;

    while (cin >> cmd)
    {
        if (cmd == "clear")
        {
            valOf.clear();
            varOf.clear();
        }

        if (cmd == "def") 
        { 
            string var; int val;
            cin >> var >> val;

            if (valOf.count(var))
            {
                varOf.erase(valOf[var]); 
            }

            if (varOf.count(val))
            {
                valOf.erase(varOf[val]);
            }

            valOf[var] = val;
            varOf[val] = var;
        }

        if (cmd == "calc") 
        { 
            string info; getline(cin, info);
            stringstream ss{ info };

            string var; char op;

            ss >> var;
            cout << var << " ";

            int curr = 0;
            bool known = true;

            if (valOf.count(var))
            {
                curr += valOf[var];
            }
            else
            {
                known = false;
            }

            while (ss >> op)
            {
                cout << op << " ";

                if (op == '=') break;

                ss >> var;
                cout << var << " ";

                if (valOf.count(var))
                {
                    if (op == '+') curr += valOf[var];
                    if (op == '-') curr -= valOf[var];
                }
                else
                {
                    known = false;
                }
            }

            if (known && varOf.count(curr))
            {
                cout << varOf[curr] << '\n';
            }
            else
            {
                cout << "unknown\n";
            }
        }
    }
}
