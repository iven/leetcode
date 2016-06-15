#include <cassert>
#include <vector>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      auto m = nums1.size(), n = nums2.size();
      auto total = m + n;
      if (total % 2) {
        return findKthElementSortedArrays(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
      } else {
        return (findKthElementSortedArrays(nums1.begin(), m, nums2.begin(), n, total / 2)
            + findKthElementSortedArrays(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
      }
    }

    int findKthElementSortedArrays(vector<int>::const_iterator nums1, size_t m, vector<int>::const_iterator nums2, size_t n, size_t k) {
      if (m > n) return findKthElementSortedArrays(nums2, n, nums1, m, k);
      if (m == 0) return nums2[k - 1];
      if (k == 1) return min(nums1[0], nums2[0]);

      // divide k into two parts
      auto k1 = min(k / 2, m), k2 = k - k1;

      if (nums1[k1 - 1] == nums2[k2 - 1]) {
        return nums1[k1 - 1];
      } else if (nums1[k1 - 1] > nums2[k2 - 1]) {
        return findKthElementSortedArrays(nums1, m, nums2 + k2, n - k2, k - k2);
      } else {
        return findKthElementSortedArrays(nums1 + k1, m - k1, nums2, n, k - k1);
      }
    }
};

int main(void)
{
  Solution solution;

  vector<int> nums1 = {4, 5, 6, 7};
  vector<int> nums2 = {4, 6, 7, 8};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 6);

  nums1 = {};
  nums2 = {4};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 4);

  nums1 = {2};
  nums2 = {4};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 3);

  nums1 = {1};
  nums2 = {2, 4, 5};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 3);

  nums1 = {2};
  nums2 = {1, 4, 5};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 3);

  nums1 = {2, 5};
  nums2 = {1, 4};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 3);

  nums1 = {1};
  nums2 = {2, 3, 5, 6, 7};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 4);

  return 0;
}
