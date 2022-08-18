/* Author:  Vincent Tam
 * CS5008 Summer 2022
 * LeetCode 42 Trapping Rain Water
 * https://leetcode.com/problems/trapping-rain-water/
 */

int trap(int* height, int heightSize){
    int* left_max_height = (int*)malloc(sizeof(int)* heightSize);
    int* right_max_height = (int*)malloc(sizeof(int)* heightSize);
    
    int current_max = 0;
    int i;
	/*iterate from the left find max height on left side*/
    for(i = 0; i < heightSize; i++){
        if(current_max < height[i]){
            current_max = height[i]; 
        }
        left_max_height[i] = current_max;
    }
	/* reset */
    current_max = 0;
	/* iterate from the right, find max height on right side */
    for(i = heightSize - 1; i >= 0; i--){
        if(current_max < height[i]){
            current_max = height[i]; 
        }
        right_max_height[i] = current_max;
    }
    
    int total = 0;
    int local;
	/* iterate through again, water at local index "i" is the minimum
	 * of left and right max subtracting the height at index "i"
	 * add local to total for each iteration
	 */
    for(i = 0; i < heightSize; i++){
        if(left_max_height[i] < right_max_height[i]){
            local = left_max_height[i] - height[i];
        }
        else{
            local = right_max_height[i] - height[i];
        }
        total += local;
    }
    return total;
}
