class Solution {
public:
    void rev(string& s, int start, int end)
    {
        while(start < end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return;
    }
    string reverseWords(string s) 
    {
        int start = 0;
        int end = 0;
        while(end <= s.length())
        {
            if(end == s.length())
            {
                rev(s, start, end - 1);
                break;
            }
            
            if(s[end] == ' ')
            {
                rev(s, start, end - 1);
                start = end + 1;
            }
            end++;
        }
        return s;
    }
};