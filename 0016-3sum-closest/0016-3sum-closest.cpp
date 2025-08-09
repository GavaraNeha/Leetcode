#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        // 1. Sort the array
        std::sort(nums.begin(), nums.end());

        // 2. Initialize variables
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = std::abs(closestSum - target);

        // 3. Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            // 4. Two-pointer approach
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDiff = std::abs(currentSum - target);

                // 5. Compare and update the closest sum
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                }

                // 6. Adjust the pointers
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // We found the exact target, no need to search further
                    return target;
                }
            }
        }
        
        // 7. Return the result
        return closestSum;
    }
};