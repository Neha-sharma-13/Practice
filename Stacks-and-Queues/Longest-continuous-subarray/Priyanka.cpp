class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque <int> minq;
        deque <int> maxq;
        int ans = 0;
        int s = 0,e = 0;
        while(e<nums.size()){
            int x = nums[e];
            while(!minq.empty() && nums[minq.back()]>=x)
                minq.pop_back();
            minq.push_back(e);
            while(!maxq.empty() && nums[maxq.back()]<=x)
                maxq.pop_back();
            maxq.push_back(e);
            int mini = nums[minq.front()];
            int maxi = nums[maxq.front()];
            if(maxi-mini > limit){
                s++;
                if(s>minq.front()) minq.pop_front();
                if(s>maxq.front()) maxq.pop_front();
            }
            else{
                ans = max(ans,e-s+1);
                e++;
            }
        }
        return ans;
    }
};
