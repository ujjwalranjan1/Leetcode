//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;


// } Driver Code Ends
//User function Template for Java

class Solution{
    
    //Function to return sum of count of set bits in the integers from 1 to n.
    public static int countSetBits(int n){
    
        // Your code here
        n+=1;
        int cnt=0;
       for(int i=0;i<30;i++)
       {
          int toggle_length=(1<<i);
          int toggle_size=2*toggle_length;
        //   System.out.println(toggle_size);
          cnt+=(n/toggle_size)*toggle_length;
          cnt+=Math.max((n%toggle_size)-toggle_length,0);
            //  System.out.println(cnt);
       }
    return cnt;
    }
}

/*
0000
0001
0010
0011
0100


0101
0110
0111
1000

*/

//{ Driver Code Starts.

// Driver code
class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();//testcases
		int x, n;
		while(t-->0) {
	        n = sc.nextInt();//input n

		    Solution obj = new Solution();

		    System.out.println(obj.countSetBits(n));//calling countSetBits() method
		}
	}
}

// } Driver Code Ends