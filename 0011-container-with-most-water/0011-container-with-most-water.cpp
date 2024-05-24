class Solution {
public:
    int maxArea(vector<int>& height) {
        int lptr = 0, rptr = height.size() - 1, global_max = 0;

        while(lptr <= rptr)
        {
            global_max = max(global_max, 
                (min(height[lptr], height[rptr]) * (rptr - lptr)));

            if(height[lptr] <= height[rptr])
                lptr++;
            else
                rptr--;
        }

        return global_max;
    }
};