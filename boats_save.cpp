#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int numBoats = 0;
    int j = 0;
    sort(people.begin(), people.end());

    for (int i = people.size() - 1; j <= i; i--) {
        numBoats++;
        if (people[j] <= limit - people[i])
            j++;
    }
    return numBoats;
}