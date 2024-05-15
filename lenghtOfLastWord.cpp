#include <string>
#include <iostream>
#include <vector>

using namespace std;


int lengthOfLastWord(string s) {
    int lenght = 0;
    bool isWord = false;
    char letter;

    for (int i = s.size() - 1; i >= 0; --i) {
        if (isWord == false && s[i] == ' ')
            continue;
        if (isWord == true && s[i] == ' ')
            return lenght;
        if (s[i] != ' ') {
            letter = s[i];
            lenght++;
            isWord = true;
        }
    }

    return lenght;
}

int main()
{
    cout << lengthOfLastWord("Hello World") << endl;
}