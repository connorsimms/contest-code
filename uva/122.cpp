#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<string, string>> nodes;
    set<string> seen;
    string node;
    bool valid = true;
    while (cin >> node) {
        if (node == "()") {
            sort(nodes.begin(), nodes.end(), [](const pair<string, string> &a, const pair<string, string> &b) {
                if (a.first.size() == b.first.size())
                    return a.first < b.first;
                return a.first.size() < b.first.size();
            });

            if (nodes.front().first != "")
                valid = false;

            for (int i = nodes.size() - 1; valid && i >= 1; --i) {
                bool found = false;
                for (int j = i - 1; !found && j >= 0; --j) {
                    if (nodes[j].first == nodes[i].first.substr(0, nodes[i].first.size() - 1)) {
                        found = true;
                    }
                }
                if (!found)
                    valid = false;
            }

            if (valid) {
                string del = "";
                for (auto n : nodes) {
                    cout << del << n.second;
                    del = " ";
                }
                cout << '\n';
            } else {
                cout << "not complete\n";
            }
            seen.clear();
            nodes.clear();
            valid = true;
            continue;
        }

        auto del = node.find(',');
        string val = node.substr(1, del - 1);
        string seq = node.substr(del + 1, node.size() - 2 - del);

        if (del == 1)
            valid = false;
        if (seen.count(seq))
            valid = false;

        seen.insert(seq);
        nodes.emplace_back(seq, val);
    }
}
