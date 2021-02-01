class Solution {
public:
    string longestPalindrome(string s) {
    string ans;
    int n=s.size();
    int dp[1005][1005];
    int len=1,pos=0;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i][i]=1;
        
    for(int i=0;i<n-1;i++)
    {
        dp[i][i+1]=(s[i]==s[i+1]);
        if(dp[i][i+1])
            len=2,pos=i;
    }
        
        
        
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<j-1;i++)
        {
            dp[i][j]=(dp[i+1][j-1]&&(s[i]==s[j]));
            if(dp[i][j])
            {
                int tl=j-i+1;
                if(tl>len)
                {
                    len=tl;
                    pos=i;
                }
            }
        }
        
    }
    for(int i=pos;i<pos+len;i++)
        ans+=s[i];
     return ans;  
    }
};