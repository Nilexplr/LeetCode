double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int size = 0;
        double median = 0.0;

        while (!nums1.empty() && !nums2.empty()) {
            merged.push_back(min(nums1[0], nums2[0]));
            if (nums1[0] < nums2[0])
                nums1.erase(nums1.begin());
            else
                nums2.erase(nums2.begin());
        }
        if (!nums1.empty())
            merged.insert(merged.end(), nums1.begin(), nums1.end());
        if (!nums2.empty())
            merged.insert(merged.end(), nums2.begin(), nums2.end());

        if (merged.size() % 2 == 1)
            median = (double)merged[(int)(merged.size() / 2)];
        else
            median = (double)(merged[merged.size() / 2 -1] + merged[merged.size() / 2]) / 2;
        return median;
    }
};