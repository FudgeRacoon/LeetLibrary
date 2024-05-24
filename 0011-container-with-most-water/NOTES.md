# Approach 1: Brute Force

## Intuition
The brute force approach involves examining all possible pairs of lines to determine which pair forms the container with the maximum amount of water. This can be achieved by calculating the area for every possible pair and keeping track of the maximum area found.

## Algorithm
1. Initialize a variable `global_max` to store the maximum area found.
2. Iterate through each line using two nested loops:
   - Outer loop iterates from the first line to the last line.
   - Inner loop iterates from the line next to the outer loop's current line to the last line.
3. For each pair of lines, calculate the area formed between them.
4. Update `global_max` if the current area is greater than the previously recorded maximum area.
5. Return `global_max` as the result.

## Implementation

``` C++
int MaxArea(vector<int>& height) {
  int global_max = 0;

  for(int i = 0; i < height.size(); i++)
    for(int j = i + 1; j < height.size(); j++)
      global_max(max(global_max,
        (min(height[j], height[i])) * (j - i));

    return global_max;
}
```

## Complexity Analysis
- **Time Complexity:** ${O(n^2)}, where $O{(n)} is the number of lines. This is because we are checking all possible pairs of lines.
- **Space Complexity:** ${O(1)}, since we are using only a constant amount of extra space.

# Approach 2: Shifting Pointers

## Intuition
The shifting pointers approach optimizes the brute force solution by leveraging the fact that the height of the container is limited by the shorter line. Therefore, we can start with the widest possible container and gradually narrow it down by moving the pointers inward, always trying to find a taller line to maximize the area.

## Algorithm
1. Initialize two pointers, `lptr` at the beginning and `rptr` at the end of the array.
2. Initialize a variable `global_max` to store the maximum area found.
3. While `lptr` is less than `rptr`:
   - Calculate the width between the two pointers.
   - Determine the height as the minimum height between the lines at the `lptr` and `rptr` pointers.
   - Calculate the area and update `global_max` if the current area is greater.
   - Move the pointer pointing to the shorter line inward (i.e., increase `lptr` if the line at `lptr` is shorter, otherwise decrease `rptr`).
4. Return `global_max` as the result.

## Implementation

``` C++
int MaxArea(vector<int>& height) {
   int lptr = 0, rptr = height.size() - 1, global_max = 0;

        while(lptr <= rptr) {
            global_max = max(global_max, 
                (min(height[lptr], height[rptr]) * (rptr - lptr)));

            if(height[lptr] <= height[rptr]) lptr++;
            else rptr--;
        }

        return global_max;
}
```

## Complexity Analysis
- **Time Complexity:** $O{(n)}, where $O{(n)} is the number of lines. This is because each element is visited at most once by the two pointers.
- **Space Complexity:** $O{(1)}), since we are using only a constant amount of extra space.
"""​
