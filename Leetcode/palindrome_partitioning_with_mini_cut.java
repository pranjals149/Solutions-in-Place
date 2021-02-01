class Solution {
    public int minCut(String s) {
        boolean [][]dp = new boolean[s.length()][s.length()];
        
        for(int diag=0; diag<dp.length; diag++){
            for(int i=0,j=diag; j<dp.length; i++,j++){
                
                if(diag==0)
                    dp[i][j] = true;
                else if(diag==1)
                    dp[i][j] = s.charAt(i)==s.charAt(j);
                else {
                    if(s.charAt(i)==s.charAt(j) && dp[i+1][j-1]==true)
                        dp[i][j] = true;
                    else 
                        dp[i][j] = false;
                }
            }
        }
        
    int[] arr= new int[s.length()];
        arr[0] =0;
        
        for(int j= 1; j<arr.length; j++){
            if(dp[0][j])
                arr[j] =0;
            else{
                int min = Integer.MAX_VALUE;
                
                for(int i=j; i>=1; i--){
                    if(dp[i][j]){
                        if(arr[i-1]<min)
                            min = arr[i-1];
                    }
                }
                arr[j] = min +1;
            }
        }
        return arr[arr.length-1];
    }
}