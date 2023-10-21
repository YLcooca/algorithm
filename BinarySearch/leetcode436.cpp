// https://leetcode.cn/problems/find-right-interval/description/
#include <algorithm>
#include <utility>
#include <vector>

using std::make_pair;
using std::max;
using std::pair;
using std::sort;
using std::vector;

// 查看题解解的题
class Solution {
  public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        int len = intervals.size();
        int maxStart = 0;
        vector<pair<int, int>> starts; // starti, i
        for (int i = 0; i < len; ++i) {
            starts.emplace_back(intervals[i][0], i);
            maxStart = max(intervals[i][0], maxStart);
        }
        sort(starts.begin(), starts.end());
        vector<int> ans(len, -1);
        auto notFound = starts.end();
        for (int i = 0; i < len; ++i) {
            if (intervals[i][0] > maxStart)
                continue;
            auto it = lower_bound(starts.begin(), starts.end(),
                                  make_pair(intervals[i][1], 0));
            if (it != notFound) {
                ans[i] = it->second;
            }
        }

        return ans;
    }
};