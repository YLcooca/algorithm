// https://leetcode.cn/problems/maximal-score-after-applying-k-operations/?envType=daily-question&envId=2023-10-18
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class Solution {
  public:
    long long maxKelements(vector<int> &nums, int k) {
        // 使用priority_queue来实现最大堆
        // 每次从最大堆中取出最大值，然后对其进行ceil(x/3)的运算后放入堆中
        // 如此循环 k 次
        priority_queue<int> q(nums.begin(), nums.end());
        long long ans = 0;
        for (int _ = 0; _ < k; ++_) {
            int x = q.top();
            q.pop();
            ans += x;
            q.push((x + 2) / 3);
        }

        return ans;
    }
};