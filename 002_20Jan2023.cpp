class Solution {
public:
    void solve(int idx, vector<int>&temp, set<vector<int>>&ans, vector<int>& nums){
        // if we reach at last idx we will return and push the temp if it has 2 or more elements
        if(idx==nums.size()){
            if(temp.size()>1){
                ans.insert(temp);
            }
            return ;
        }
        
        // if temp vector is empty or next element in nums is greater than last element pushed 
        // in temp then we can add the current element 
        if(temp.empty() || nums[idx]>=temp.back()){
            temp.push_back(nums[idx]);
            solve(idx+1, temp, ans, nums);       // calling fun for next idx
            temp.pop_back();                     // removing element because we are passing vector by reference
        }
        
        // if above if cond is not true then we will call fun for next idx
        solve(idx+1, temp, ans, nums);
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // we are using set<vector> as we can have same vectors multiple times
        set<vector<int>> ans;
        vector<int>temp;
        
        solve(0, temp, ans, nums);
        return vector(ans.begin(), ans.end());
    }
};
