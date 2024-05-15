#include <string>
#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
    bool negative = false;
    long dividendlg = dividend;
    long divisorlg = divisor;

    if (divisor == 0)
        return 0;

    cout << dividendlg << endl;
    cout << divisorlg << endl;
    if (dividendlg < 0 && divisorlg < 0) {
        dividendlg = -dividendlg;
        divisorlg = -divisorlg;
    }
    cout << dividendlg << endl;
    cout << divisorlg << endl;

    if (dividendlg > 0 && divisorlg < 0) {
        negative = true;
        divisorlg = -divisorlg;
    }

    if (dividendlg < 0 && divisorlg > 0) {
        dividendlg = -dividendlg;
        negative = true;
    }
    cout << dividendlg << endl;
    if (dividendlg < divisorlg)
        return 0;
    if (divisorlg == 0)
        return 0;
    if (divisorlg == dividendlg)
        return (negative ? -1 : 1);
    cout << 1 << endl;
    string result = "";
    long counter = 0;
    string dividendStr = to_string(dividendlg);
    string divisorStr = to_string(divisorlg);

    long number_dividend = strtol(dividendStr.substr(0, divisorStr.size()).c_str(), NULL, 10);

    for (int i = divisorStr.size()-1; i < dividendStr.size(); i++) {
        counter = 0;
        while (number_dividend - divisorlg >= 0)
        {
            number_dividend -= divisorlg;
            counter++;
        }
        result += '0' + counter;
        if (i + 1 != dividendStr.size())
            number_dividend = strtol((to_string(number_dividend) + dividendStr[i+1]).c_str(), NULL, 10);
    }
    long final_result = strtol(result.c_str(), NULL, 10);
    cout << final_result << endl;
    if (final_result > INT_MAX)
        return negative ? INT_MIN : INT_MAX;
    return negative ? -atoi(result.c_str()) : atoi(result.c_str());
}

int main()
{
    cout << divide(-21, -1) << endl;
}