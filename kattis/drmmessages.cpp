#include <iostream>
using namespace std;

int main()
{
    string input; cin >> input;
    int sum1{}, sum2{};
    for (int i{}; i < input.size() / 2; ++i) { sum1 += (input[i] - 'A'); }
    for (int i{input.size() / 2}; i < input.size(); ++i) { sum2 += (input[i] - 'A'); }

    for (int i{}; i < input.size() / 2; ++i) { 
        int offset = input[i] - 'A';
        offset += sum1;
        offset %= 26;
        input[i] = 'A' + offset;
    }

    for (int i{input.size() / 2}; i < input.size(); ++i) {
        int offset = input[i] - 'A';
        offset += sum2;
        offset %= 26;
        input[i] = 'A' + offset;
    }

    for (int i{}; i < input.size() / 2; ++i) { 
        int offset = input[i] - 'A';
        offset += input[i + input.size() / 2] - 'A';
        offset %= 26;
        input[i] = 'A' + offset;
        cout << input[i];
    }
    cout << '\n';
}
