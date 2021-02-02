class Solution {
public:
    vector<vector<string>> partition(string s) {
  
        
        
        
        
        
        int n=s.size();
  vector<vector<string>>ans;
   vector< vector<vector<int> > >v[n+5];
   for(int i=1;i<=n;i++)
   {
       for(auto it:v[i-1])
       {
         vector<vector<int> >tp=it;
         tp.push_back(vector<int>{i,i});
           v[i].push_back(tp);
       }
       if(i-1==0)
         v[i].push_back(vector< vector<int> > {vector<int>{i,i} });
       //j represent length
       for(int j=2;j<=i;j++)
       {
           int k=i-j+1;
           string tp=s.substr(k-1,j);
           string kp=tp;
           reverse(kp.begin(),kp.end());
           //if tp is palindrome
           if(tp==kp)
           {
             for(auto it:v[k-1])
             {
               vector<vector<int> >dk=it;
                dk.push_back(vector<int>{k,i});
               v[i].push_back(dk);
               }
               if(k-1==0)
               {
                    v[i].push_back(vector< vector<int> > {vector<int>{k,i} });
               }
           }
       }
   }


     for(auto it:v[n])
     {
       vector<string>temp;
       for(auto jt:it)
       {
         temp.push_back(s.substr(jt[0]-1,jt[1]-jt[0]+1));
       }
       ans.push_back(temp);
     }
        
        return ans;
        
        
    }
};