#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int, bool> used;
      auto longest = 0u;

      for (auto i : nums) used[i] = false;

      for (auto i : nums) {
        if (used[i]) continue;

        auto length = 1u;
        used[i] = true;

        for (auto j = i + 1; used.find(j) != used.end(); ++j) {
          used[j] = true;
          ++length;
        }
        for (auto j = i - 1; used.find(j) != used.end(); --j) {
          used[j] = true;
          ++length;
        }
        longest = max(longest, length);
      }

      return longest;
    }
};

int main(void)
{
  Solution solution;

  vector<int> nums = {100, 4, 99, 5, 2, 6, 7};
  assert(solution.longestConsecutive(nums) == 4);

  return 0;
}
