#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        
        // The problem constraints guarantee n >= 3, but this is a good practice.
        if (n < 3) {
            return 0; 
        }

        // Sort the array to use the two-pointer technique.
        std::sort(nums.begin(), nums.end());

        // Initialize the closest sum with the sum of the first three elements.
        int closestSum = nums[0] + nums[1] + nums[2];

        // Iterate through the array, fixing the first element.
        for (int i = 0; i < n - 2; ++i) {
            // Use two pointers for the rest of the array.
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // If the current sum is closer to the target, update closestSum.
                if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // Adjust pointers based on the comparison with the target.
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // If the sum is exactly the target, it's the closest possible, so we can return immediately.
                    return currentSum;
                }
            }
        }
        
        return closestSum;
    }
};