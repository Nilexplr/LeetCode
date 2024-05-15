#include <unordered_map>
#include <string>

int romanToInt(string s) {
    unordered_map<char, int> symbols = {{'I', 1},{'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    unordered_map<string, int> symbols_spec = {{"IX", 9}, {"IV", 4}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
    int result = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i == s.size() - 1) {
            result += symbols[s[i]];
            break;
        }
        if (symbols_spec.find(s.substr(i, 2)) != symbols_spec.end()) {
            result += symbols_spec[s.substr(i, 2)];
            i++;
            continue;
        }
        result += symbols[s[i]];

    }
    return result;
}