#include <cassert>
#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int start = 0u;
      int end = nums.size() - 1;
      while (start <= end) {
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
          return mid;
        } else if (nums[start] <= nums[mid]) {
          if (nums[start] <= target && target < nums[mid]) {
            end = mid - 1;
          } else {
            start = mid + 1;
          }
        } else {
          if (nums[mid] < target && target <= nums[end]) {
            start = mid + 1;
          } else {
            end = mid - 1;
          }
        }
      }
      return -1;
    }
};

int main(void)
{
  Solution solution;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

  for (int i = 0; i < nums.size(); ++i) {
    assert(solution.search(nums, nums[i]) == i);
  }

  assert(solution.search(nums, -1) == -1);

  nums = {1};
  assert(solution.search(nums, 2) == -1);

  nums = {1, 2};
  assert(solution.search(nums, 2) == 1);

  nums = {3, 1, 2};
  assert(solution.search(nums, 2) == 2);

  return 0;
}
