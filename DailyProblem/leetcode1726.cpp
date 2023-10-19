// https://leetcode.cn/problems/tuple-with-same-product/description/
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
  public:
    int tupleSameProduct(vector<int> &nums) {
        unordered_map<int, int> m;
        int len = nums.size();
        // 由于数组中元素均不相同，故其积也具有唯一性
        for (int i = 0; i < len - 1; ++i) {
            for (int j = i + 1; j < len; ++j) {
                m[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        // 判断同积的数量，再累加可构造的元组数量
        for (auto &it : m) {
            if (it.second >= 2) {
                ans += 8 * (it.second * (it.second - 1) / 2);
            }
        }

        return ans;
    }
};