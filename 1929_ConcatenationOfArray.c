/* Author:  Vincent Tam
 * CS5008 Summer 2022
 * LeetCode 1929 Concatenation of Array
 * https://leetcode.com/problems/concatenation-of-array/
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int) * 2 * numsSize);
    *returnSize = 2 * numsSize;
    int i;
    for(i = 0; i < numsSize; i++){
        ans[i] = nums[i];
    }
    i = 0;
    for(int j = numsSize; j < 2*numsSize; j++){
        ans[j] = nums[i];
        i++;
    }
    return ans;
}
