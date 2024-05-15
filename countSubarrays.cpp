#include <string>
#include <iostream>
#include <vector>

using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        int maximum = 0;

        while (i < nums.size())
        {
            if (maximum < nums[i]) {
                maximum = nums[i];
                count = 1;
            }
            while (j < nums.size() && count < k)
            {
                j++;
            }
            if (count == k) {
                i = j;
                
            }
            
        }
        

        return result;
    }