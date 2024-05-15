#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>

using namespace std;


int recursive_sum(TreeNode* root, unordered_map<int, int>& frequency) {
    if (!root)
        return 0;
    int sum = root->val;
    
    sum += recursive_sum(root->left, frequency);
    sum += recursive_sum(root->right, frequency);
    if (frequency.find(sum) != frequency.end())
        frequency[sum]++;
    else
        frequency[sum] = 1;
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> mp;
    vector<int> result;
    int maximum = INT_MIN;

    recursive_sum(root, mp);
    for (const auto& pair : mp) {
        if (pair.second > maximum) {
            result.clear();
            maximum = pair.second
        }
        if (pair.second == maximum)
            result.push_back(pair.first);
    }
    return result;
}