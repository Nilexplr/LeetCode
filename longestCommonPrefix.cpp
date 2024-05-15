#include <string>
#include <iostream>
#include <vector>

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int i = 0;
        char letter;

        while (i < strs[0].size()) {
            if (i < strs[0].size())
                letter = strs[0][i]; 
            for (auto word : strs) {
                cout << i << endl;
                cout << letter << endl;
                if (i >= word.size())
                    return result;
                if (letter != word[i])
                    return result;
            }
            result += letter;
            i++;
        }
        return result;
}


int main()
{
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << endl;
}