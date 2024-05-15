#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int quotien;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            quotien = 1;
            for (int j = i; j < nums.size(); j++) {
                quotien = quotien * j;
                if (quotien > k)
                    break;
                result++;
            }
         return result;
       }
}