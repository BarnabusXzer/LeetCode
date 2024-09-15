#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {

        int length = nums.size(); // GET LENGTH OF "nums"
        int largestBitwiseAnd = 0; // THIS IS THE VARIABLE THAT WILL STORE THE LARGEST BITWISE-AND

        for (int i = 0; i < length; i = i++) {                       // START SUBARRAY OF "nums" AT INDEX "i"
            int bitwiseAnd = 0; // "bitwiseAnd" WILL STORE THE BITWISE-AND FOR THE CURRENT SUBARRAY, BECAUSE "i" IS A SUBARRY THE FIRST BITWISE AND IS EQUAL TO "i"
            bitwiseAnd = nums[i];
            
            for (int j = i + 1; j < length; j = j++) { // ITERATE THROUGH AGAIN TO ADD TO THE CURRENT BITWISE-AND
                int tempBitwiseAnd = bitwiseAnd & nums[j]; // PERFORM BITWISE-AND WITH THE NEXT VALUE IN THE ARRAY UNTIL THE BITWISE-AND RETURNS SMALLER THAN BEFORE  
                if (tempBitwiseAnd > bitwiseAnd) {
                    bitwiseAnd = tempBitwiseAnd;
                }
                else {
                    break;
                }
            }
            if (bitwiseAnd > largestBitwiseAnd) {
                largestBitwiseAnd = bitwiseAnd;                
            } 
        }
        
        int bitwiseAndLength = 0; // THIS EQUALS THE LENGTH OF THE LONGEST SUBARRAY WHERE EACH MEMBER IS EQUAL TO "largestBitwiseAnd"

        for (int i = 0; i < length; i = i++) { // ITTERATE THROUGH AGAIN TO FIND SUBARRAYS WHERE ALL ELEMENTS ARE EQUAL TO MAX-BITWISE-AND
            int tempBitwiseAndLength = 0;
            if (nums[i] == largestBitwiseAnd) {
                tempBitwiseAndLength++;

                for (int j = i + 1; j < length; j = j++) {
                    if (nums[j] == largestBitwiseAnd) {
                        tempBitwiseAndLength++;
                    } else {               
                        break;
                    }
                }
            }
            if (tempBitwiseAndLength > bitwiseAndLength) {
                bitwiseAndLength = tempBitwiseAndLength;
            }
        }
        return (bitwiseAndLength);
    }
};

void main() {
    Solution solution;

    vector<int> nums{1, 2, 3, 3, 2, 2};
    vector<int> nums2{1,2,3,4};
    
    cout << solution.longestSubarray(nums) << "\n";
    cout << solution.longestSubarray(nums2) << "\n";
};