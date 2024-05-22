class Solution {
public:
    /** Brute-Force Solution
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int p1 = 0; p1 < nums.size(); p1++)
            for(int p2 = p1 + 1; p2 < nums.size(); p2++)
                if(nums[p1] + nums[p2] == target)
                    return {p1, p2};
            
        return vector<int>();
    }
    **/

    /** Two-Pass Hash Table
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;

        for(int i = 0; i < nums.size(); i++)
            hash_table.insert({nums[i], i});

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if(hash_table.find(complement) != hash_table.end() &&
               hash_table[complement] != i)
                return {i, hash_table[complement]};
        }

        return vector<int>();
    }
    **/

    /** Two-Pass Hash Table **/
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if(hash_table.find(complement) != hash_table.end())
                return {i, hash_table[complement]};
            
            hash_table.insert({nums[i], i});
        }

        return vector<int>();
    }
};