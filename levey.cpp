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
//===========================Longest Palindromic Substring============================//
class Solution {
public:
    string preProcess(string s) {
        int len = (int)s.length();
        if(len == 0)
            return "^$";
        string ret = "^";
        for(int i = 0; i < len; i++) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
    
    string longestPalindrome(string s) {
        string str = preProcess(s);
        int len = (int)str.length();
        int max_pos = 0;
        int max_pos_right = 0;
        int* radius = new int[len];
        memset(radius, 0, len);
        
        for(int i = 1; i < len - 1; i++) {
            int i_mirror = 2 * max_pos - i;
            radius[i] = (max_pos_right > i) ? min(max_pos_right - i, radius[i_mirror]) : 0;
            
            while (str[i + 1 + radius[i]] == str[i - 1 - radius[i]]) {
                radius[i]++;
            }
            
            if(i + radius[i] > max_pos_right) {
                max_pos_right = i + radius[i];
                max_pos = i;
            }
        }
        
        int ans_pos = 0;
        int ans_radius = 0;
        for(int i = 0; i < len - 1; i++) {
            if(radius[i] > ans_radius) {
                ans_pos = i;
                ans_radius = radius[i];
            }
        }
        
        delete[] radius;
        
        return s.substr((ans_pos - 1 - ans_radius) / 2, ans_radius);
    }
};
//===========================Median of Two Sorted Arrays============================//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = (int) nums1.size();
        int len2 = (int) nums2.size();
        if(len1 < len2)
            return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = len2 * 2;
        while(lo <= hi) {
            int mid2 = (lo + hi) / 2;
            int mid1 = len1 + len2 - mid2;
            
            int l1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            int r1 = (mid1 == len1 * 2) ? INT_MAX : nums1[mid1 / 2];
            int r2 = (mid2 == len2 * 2) ? INT_MAX : nums2[mid2 / 2];
            
            if(l1 > r2) {
                lo = mid2 + 1;
            } else if(l2 > r1) {
                hi = mid2 - 1;
            } else {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
        return -1;
    }
};
//===========================Kth Largest Element in an Array============================//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size())
            return -1;
        return findKthMin(nums, 0, (int)nums.size() - 1, (int)nums.size() - k);
    }
    
    int findKthMin(vector<int>& nums, int start, int end, int k) {
        if(start > end)
            return 0;
        
        int i = start + 1, j = end;
        while(i <= j) {
            while(i <= j && nums[i] <= nums[start])
                i++;
            while (i <= j && nums[j] >= nums[start])
                j--;
            if(i < j)
                swap(nums[i++], nums[j--]);
        }
        swap(nums[start], nums[j]);
        
        if(j > k)
            return findKthMin(nums, start, j - 1, k);
        else if(j < k)
            return findKthMin(nums, j + 1, end, k);
        else
            return nums[j];
        
        return 0;
    }
};
//===========================79. Word Search============================//
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if(idx == word.length())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx])
            return false;
        board[i][j] = '*';
        bool ret = dfs(board, word, i, j + 1, idx + 1)
                    || dfs(board, word, i, j - 1, idx + 1)
                    || dfs(board, word, i - 1, j, idx + 1)
                    || dfs(board, word, i + 1, j, idx + 1);
        board[i][j] = word[idx];
        return ret;
    }
};
//===========================8. String to Integer (atoi)============================//
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        int idx = 0, sign = 1;
        long long ret = 0;
        while(idx < str.length() && str[idx] == ' ')
            idx++;
        if(str[idx] == '-' || str[idx] == '+') {
            sign = (str[idx] == '-') ? -1 : 1;
            idx++;
        }
        while(idx < str.length() && str[idx] >= '0' && str[idx] <= '9') {
            ret = ret * 10 + str[idx] - '0';
            if(ret * sign >= INT_MAX) {
                return INT_MAX;
            } else if (ret * sign <= INT_MIN) {
                return INT_MIN;
            }
            idx++;
        }
        return (int)ret * sign;
    }
};
//===========================8. String to Integer (atoi)============================//
