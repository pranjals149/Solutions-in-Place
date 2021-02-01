class Solution {
    public int lengthOfLIS(int[] nums) {
        
        
        
         int []dp = new int[nums.length];
        
        
        int overAllMax = 0;
        
        for(int i=0; i<dp.length; i++){
            
            int max = 0;
            
            for(int j=0; j<i; j++){
                
                if(nums[j]<nums[i]){
                    
                        if(dp[j]>max){
                            max= dp[j];
                        }
                    
                }
            }
            
            dp[i] = max + 1;
            
            if(dp[i]>overAllMax){
                
                overAllMax=dp[i];
                
            }
            
        }
        
       return overAllMax;
        
    
        
        
    
    }
}