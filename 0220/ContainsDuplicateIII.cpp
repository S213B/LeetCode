class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        k++;
        int n_idx = (nums.size() <= k) ? nums.size() : k;
        multiset<int> q(nums.begin(), nums.begin() + n_idx);
        
        for (auto i = q.begin(); i != q.end(); i++) {
            auto e = i;
            if (e == q.begin()) continue;
            int cur = *e;
            int pre = *(--e);
            if (abs((long)pre - (long)cur) <= t)
                return true;
        }
        
        for (; n_idx < nums.size(); n_idx++) {
            q.erase(q.find(nums[n_idx-k]));
            auto e = q.insert(nums[n_idx]);
            int cur = *e;
            
            if (e != q.begin()) {
                int pre = *(--e);
                if (abs((long)cur - (long)pre <= t))
                    return true;
                e++;
            }
            
            if ((++e) != q.end()) {
                int nex = *e;
                if (abs((long)cur - (long)nex) <= t)
                    return true;
            }
        }
        
        return false;
    }
};
