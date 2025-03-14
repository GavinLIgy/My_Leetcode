/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() + nums2.size() <= 4){
            // case 1: nums1 got 2, nums2 got 2 
            // case 2: nums1 got 3/2, nums2 got 1 
            // case 3: nums1 got 1, nums2 got 3/2 
            // case 4: nums1 got 1, nums2 got 1 

            if (nums2.size() == 1){
                // ending point, comparing 2 elements

            }else{

            }
        }else{
            // divide-and-concor
            // median of nums1 & 2
            if (nums1[nums1.size()/2] < nums2[nums2.size()/2]){
                // depose lower half of nums1, and higher half of nums2
                nums1.erase(nums1.begin(), nums1.begin()+ nums1.size()/2);
                nums2.erase(nums2.begin()+ nums2.size()/2, nums2.end());
            } else {
                // depose higher half of nums1, and lower half of nums2
                nums1.erase(nums1.begin()+ nums1.size()/2, nums1.end());
                nums2.erase(nums2.begin(), nums2.begin()+ nums2.size()/2);
            }
            return findMedianSortedArrays(nums1, nums2);
        }
        
    }
};
// @lc code=end

