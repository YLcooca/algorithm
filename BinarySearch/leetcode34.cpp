// problem url: https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=binary-search
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Time :
        // Space:
        int len = nums.size();
        vector<int> ans(2, -1);
        if (len == 0) return ans;
        int left = 0, right = len - 1; // [left, right]
        int mid;
        // 两次二分查找
        // 第一次找左边界
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left == len || nums[left] != target)  return ans;
        ans[0] = left;
        left = 0, right = len - 1;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        ans[1] = right;

        return ans;
    }
};