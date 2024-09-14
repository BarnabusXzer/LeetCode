using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        // GET LENGTH OF "nums"
        int length = nums.size();
        
        int largestBitwiseAnd = 0; // THIS IS THE VARIABLE THAT WILL STORE THE LARGEST BITWISE-AND

        for (int i = 0; i <= length; i = i++) { // START SUBARRAY OF "nums" AT INDEX "i"
            int bitwiseAnd = 0; // "bitwiseAnd" WILL STORE THE BITWISE-AND FOR THE CURRENT SUBARRAY
            bitwiseAnd = nums[i];
            for (int j = 0; j <= length; j = j++) { // ITERATE THROUGH AGAIN TO ADD TO THE CURRENT BITWISE-AND
                int tempBitwiseAnd = bitwiseAnd & nums[j+1];
                if (tempBitwiseAnd > bitwiseAnd) {
                    bitwiseAnd = tempBitwiseAnd;
                } else {
                    break;
                }
                cout << bitwiseAnd;

            }
        }
        return(0);
    }
};

void main() {
    Solution solution;
    vector<int> test {1,2,3,3,2,2};
    vector<int> nums {1,2,3,3,2,2};

    cout << solution.longestSubarray(nums);
};