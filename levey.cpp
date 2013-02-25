//===========================Distinct Subsequences============================//
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
//============================Search a 2D Matrix===============================//
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height=matrix.size();
        int length=matrix[0].size();
        int i=0,j=height-1;
        while(i<=j){
            int tmp=matrix[(i+j)/2][0];
            if(tmp==target)
                return true;
            if(tmp<target)
                i=(i+j)/2+1;
            else
                j=(i+j)/2-1;
        }
        if(j<0)
            return false;
        int ii=0,jj=length-1;
        while(ii<=jj){
            int tmp=matrix[j][(ii+jj)/2];
            if(tmp==target)
                return true;
            if(tmp<target)
                ii=(ii+jj)/2+1;
            else
                jj=(ii+jj)/2-1;
        }
        return false;
    }
};
//============================Search for a Range===================================//
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0,j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(A[mid]<=target)
                i=mid+1;
            else
                j=mid-1;
        }
        int ii=0,jj=n-1;
        while(ii<=jj){
            int mid=(ii+jj)/2;
            if(A[mid]<target)
                ii=mid+1;
            else
                jj=mid-1;
        }
        vector<int> ans;
        if(i-jj>1){
            ans.push_back(jj+1);
            ans.push_back(i-1);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
//===========================Search in Rotated Sorted Array================================//
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0,j=n-1;
        while(i<j-1){
            int mid=(i+j)/2;
            if(A[mid]>=A[i])
                i=mid;
            else
                j=mid;
        }
        if(A[i]<=A[j]){
            i++;
            j++;
        }
        //i is the max, j is the min
        int ii,jj;
        if(A[0]>target){
            ii=j;
            jj=n-1;
        }
        else{
            ii=0;
            jj=i;
        }
        while(ii<=jj){
            int mid=(ii+jj)/2;
            if(A[mid]==target)
                return mid;
            if(A[mid]<target)
                ii=mid+1;
            else
                jj=mid-1;
        }
        return -1;
    }
};
