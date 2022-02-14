#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;
int main()
{
    bool b = 0;
    ifstream input;
    string fil;
    while (b == 0)
    {
        cout << "Enter file name\n";
        cin >> fil;
        input.open(fil);
        if (input.fail())
        {
            cout << "Not a valid file, enter a valid file name\n";
        }
        else b = 1;
    }
    string a;
    int count = 0;
    static const regex r(".*\\b(([0-9A-Fa-f]){2}[:-]){5}(([0-9A-Fa-f]){2})$");
    while (getline(input, a))
    {
        count += regex_match(a, r);
    }
    cout << endl << count << " matches";
    return 0;
}
