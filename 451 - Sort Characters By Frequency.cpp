class Solution {
public:
    string frequencySort(string s)
    {
        string res;
        unordered_map<char, int> m;
        for(int i=0; i<s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
                m[s[i]]++;
            else
                m[s[i]] = 1;
        }
        
        map<int, vector<char>, greater<int> > current;
        for(auto it=m.begin(); it != m.end(); it++)
            current[it->second].push_back(it->first);
        
        for(auto it=current.begin(); it != current.end(); it++)
        {
            vector<char> c = it->second;
            sort(c.begin(), c.end());
            
            for(int i=0; i<c.size(); i++)
            {
                for(int j=0; j<it->first; j++)
                    res.push_back(c[i]);
            }
        }
        
        return res;
    }
};