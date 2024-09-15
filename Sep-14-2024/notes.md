After completing my code, I attemped to upload and submit my project to LeetCode and it failed to submtit because I would receive the "_Time Limit Exceeded_" error. This makes sense because my solution is basically just brute force, it works but not very effeciently.

After reading some of the other submissions I discovered something I noticed, but did not implement, to make their solutions more efficent:  
The max bitwiseAND will always be equal to the largest number in the array, therefore other solutions simply searched for the largest number in the array, then found the largest subarray where all elements are equal to the max bitwiseAND (aka. the largest number).

Below is an example of this and is one of my favorite examples to show how overly complicated I made my solution. 

    class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int maxi=*max_element(nums.begin(),nums.end());
            int temp_length=0;
            int ans=1;

            for(int i=0;i<nums.size();i++){
                if(nums[i]==maxi) temp_length++;
                else temp_length=0;
                ans=max(ans,temp_length);
            }
            return ans;
        }
    };

You can find this solution at [here](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/solutions/5784165/easy-beginner-friendly-o-n-c), submitted by [DEvilBackInGame](https://leetcode.com/u/DEvilBackInGame/)