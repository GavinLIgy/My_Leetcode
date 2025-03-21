/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // two pointers
        /*
        int size1 = nums1.size();
        int size2 = nums2.size();
        int ptr1 = 0, ptr2 = 0;

        int m1 = 0, m2 = 0;
        
        for (int count = 0; count <= (size1 + size2)/2; count++){
            m2 = m1;
            if (ptr1 != size1 && ptr2 != size2){
                if (nums1[ptr1] >= nums2[ptr2]){
                    m1 = nums2[ptr2++];
                } else {
                    m1 = nums1[ptr1++];
                }
            } else if (ptr1 < size1){
                m1 = nums1[ptr1++];
            } else {
                m1 = nums2[ptr2++];
            }
        }

        if ((size1 + size2) % 2 == 1) {
            return static_cast<double>(m1);
        } else {
            double ans = static_cast<double>(m1) + static_cast<double>(m2);
            return ans / 2.0;
        }
        */
        // binary search
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // Calculate the left partition size
        int low = 0, high = n1;

        while (low <= high) {
            int mid1 = (low + high) >> 1; // Calculate mid index for nums1
            int mid2 = left - mid1; // Calculate mid index for nums2

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                // The partition is correct, we found the median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                // Move towards the left side of nums1
                high = mid1 - 1;
            }else {
                // Move towards the right side of nums1
                low = mid1 + 1;
            }
        }

        return 0;

    }
};
// @lc code=end

