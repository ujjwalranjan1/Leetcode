class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        //method-1 iterative
        //odd length
        int n=s.size();
        int maxl=0,pos1=-1,pos2=-1;
        for(int i=0;i<n;i++)
        {
            //centre is i
            int len=1;
            int k=1;
            while(i-k>=0 && i+k<n && s[i-k]==s[i+k])
            {
                len+=2;
                k++;
            }
            if(len>maxl)
            {
                maxl=len;
                pos1=i;
            }
        }
        
        //even  length
         for(int i=0;i<n;i++)
        {
            //centre is i
            int len=0;
            int k=0;
            while(i-k>=0 && i+k+1<n && s[i-k]==s[i+k+1])
            {
                len+=2;
                k++;
            }
            if(len>maxl)
            {
                maxl=len;
                pos1=i;
                pos2=i+1;
            }
        }
        if(pos2==-1)
        {
            int start=pos1-maxl/2;
            for(int j=start;j<start+maxl;j++)
                ans+=s[j];
        }
        else 
        {
            int start=pos1-maxl/2+1;
            for(int j=start;j<start+maxl;j++)
                ans+=s[j];
            
        }
        return ans;
        
    }
};