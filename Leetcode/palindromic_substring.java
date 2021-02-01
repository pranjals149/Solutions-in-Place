
class Solution {
    public int countSubstrings(String s) {
        
        boolean[][] dp = new boolean[s.length()][s.length()];
        int count =0; 
        
        for(int diag=0; diag<s.length(); diag++){
            
            for(int i=0, j=diag; j<s.length(); i++,j++){
                
                if(diag==0)
                    dp[i][j]=true;
                else{
                    if(diag==1){
                        if(s.charAt(i)==s.charAt(j))
                            dp[i][j]=true;
                        else
                            dp[i][j]=false;
                    }
                    else{
                        if(s.charAt(i)==s.charAt(j) && dp[i+1][j-1]==true)
                            dp[i][j]=true;
                        else 
                            dp[i][j] = false;
                    }
                }
                if(dp[i][j])
                    count++;
            }
        
        
    }
  return count;   
}
 
}