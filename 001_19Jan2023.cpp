int subarraysDivByK(vector<int>& nums, int k) {
        // agr koi rem fir s repeat ho rha hai to un 2no repeated rem k beech ka subarray k se divisible hoga, arr ham rem ko map m find krnge, agr present h to uski freq add kr 
        // denge count m
        
        int currSum=0, count=0;
        unordered_map<int,int>mp;
        mp[0]++;                     // starting m currSum 0 rhega to isse wo case b handle ho jayenge jb hamara currSum k se divisible hoga //
        
        for(int i=0; i<nums.size(); i++){
            currSum+= nums[i];
            int rem = currSum%k;
            if(rem<0) rem+= k;                 // agr rem -ve h to use +ve bnane k liye simply k add krdo //
                                 
            if(mp.count(rem)){
                count+= mp[rem];
            }
            mp[rem]++;
        }
        
        return count;
        
}
