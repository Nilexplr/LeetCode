#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

string makeGood(string s) {
    int i = 0;

    while (s.size() > 0 && i < s.size() - 1) {
        if ((s[i+1] >= 'A' && s[i] - 'a' == s[i+1] - 'A') ||
            (s[i] >= 'A' && s[i] - 'A' == s[i+1] - 'a')) {
            s.erase(i, 2);
            i > 0 ? i-- : 0;
            continue;
        }
        i++;
    }
    return s;
}

int main()
{
    cout << makeGood("abBAcC") << endl;
}