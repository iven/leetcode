#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() < 2) {
        return nums.size();
      }

      auto index = 1u;
      for (auto i = 2u; i < nums.size(); ++i) {
        if (nums[index] == nums[i] && nums[index - 1] == nums[i]) {
          continue;
        } else {
          nums[++index] = nums[i];
        }
      }
      return index + 1;
    }
};

int main(void)
{
  Solution solution;
  vector<int> nums = {1, 1, 2, 3, 3, 3, 5, 6};
  int length = solution.removeDuplicates(nums);

  for (auto num : nums) {
    cout << num << endl;
  }
  cout << "Length: " << length << endl;
  return 0;
}
