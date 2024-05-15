#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int findMaxLength(vector<int>& nums) {
    replace(nums.begin(), nums.end(), 0, -1);
    int result = 0;
    int actual_size;

    for (int i = 0; i < nums.size(); i++) {
        actual_size = 0;
        for (int j = i+1; j <nums.size(); j++) {
            if (std::reduce(nums.begin()+i, nums.begin()+j) == 0)
                actual_size = j-i;
        }
        if (actual_size > result)
            result = actual_size;
    }
    return result;
};

int main()
{
    // vector<int> v;
    std::vector<int> ints;
    // v.push_back(0);
    // v.push_back(1);

//    cout << findMaxLength(v) << endl;
}