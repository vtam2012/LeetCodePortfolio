/* Author:  Vincent Tam
 * CS5008 Summer 2022
 * LeetCode 674 Longest Continuous Increasing Subsequence
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/ 
 */


int findLengthOfLCIS(int* nums, int numsSize){
    /* sliding window with 2 pointers */ 
	int current_r = 0;
    int best_r = 0;
    int i;
    for(int i = 0; i < numsSize; i++){
        if( i == 0 || nums[i - 1] >= nums[i]){
            current_r = 1; // smallest subsequence is 1 element
        }
        else{
            current_r++;
        }
        if(current_r > best_r){
            best_r = current_r;
        }
    }
    return best_r;
}
