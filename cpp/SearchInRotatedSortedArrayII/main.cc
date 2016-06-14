#include <iostream>
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
          return true;
        } else if (nums[start] < nums[mid]) {
          if (nums[start] <= target && target < nums[mid]) {
            end = mid - 1;
          } else {
            start = mid + 1;
          }
        } else if (nums[start] > nums[mid]){
          if (nums[mid] < target && target <= nums[end]) {
            start = mid + 1;
          } else {
            end = mid - 1;
          }
        } else {
          ++start;
        }
      }
      return false;
    }
};

int main(void)
{
  Solution solution;
  vector<int> nums = {2, 4, 5, 6, 7, 0, 1, 2, 2};

  for (auto target : nums) {
    cout << solution.search(nums, target) << endl;
  }
  cout << solution.search(nums, -1) << endl;

  nums = {1};
  cout << solution.search(nums, 2) << endl;

  nums = {1, 2};
  cout << solution.search(nums, 2) << endl;

  nums = {3, 1, 2};
  cout << solution.search(nums, 2) << endl;

  return 0;
}
