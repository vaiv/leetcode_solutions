class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) 
    {
        if(en.size() == 0)
            return 0;
        sort(en.begin(), en.end(), [](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
        
        vector<int> dp(en.size(), 1);
        
        
        int res = 0;
        for(int i=0; i<en.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if((en[i][0] > en[j][0]) && (en[i][1] > en[j][1]))
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};