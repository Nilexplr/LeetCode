#include <string>
#include <iostream>
#include <vector>

using namespace std;


bool isIsomorphic(string s, string t) {
    char mp[256] = {0};
    char mapped[256] = {0};
 
    for (int i = 0; i < s.size(); i++) {
        if (mp[s[i]] == 0) {
            if (mapped[t[i]] != 0)
                return false;
            mp[s[i]] = t[i];
            mapped[t[i]] = s[i];
        }
        else if (mp[s[i]] != t[i])
            return false; 
    }
    return true;
}


int main()
{
    vector<string> strs = {"babc","baba"};
    cout << isIsomorphic(strs[0], strs[1]) << endl;
}