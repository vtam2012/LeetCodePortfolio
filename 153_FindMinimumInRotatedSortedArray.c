/* Author:  Vincent Tam
 * CS5008 Summer 2022
 * LeetCode 153 Find Minimum in Rotated Sorted Array
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 */

int findMin(int* nums, int numsSize){
	/* if first element in array is less than the end (maximum)
	 * no rotation happened, return first element which is the min
	 * in a sorted array
	 */
    if(nums[0] <= nums[numsSize - 1]){
        return nums[0];
    }
    /* use binary search */
    int l = 0;
    int r = numsSize;
        
    while(l < r) {
        int m = (l + r) / 2;
        /* find the first midpoint where val is greater than
		 * smallest element, this is the new starting index
		 * of the rotated array */
        if (nums[m] >= nums[0]){
            l = m + 1;
        }
        else {
            r = m;
        }    
    }
    return nums[l];
}
