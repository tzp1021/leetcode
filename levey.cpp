//====================Distinct Subsequences======================//
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1=S.length();
        int len2=T.length();
        int **dp = new int*[len1+1];
        for(int i=0;i<=len1;i++)
            dp[i]= new int[len2+1];
        for(int j=len2;j>=0;j--){
            dp[len1][j]=0;
        }
        for(int i=len1;i>=0;i--){
            dp[i][len2]=1;
        }
        for(int i=len1-1;i>=0;i--){
            for(int j=len2-1;j>=0;j--){
                dp[i][j]=dp[i+1][j];
                if(S[i]==T[j])
                    dp[i][j]+=dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};
