class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int val = (m+n)/2;
        int j=0,k=0,p=0;
        vector<int> res(2,0);
        for(int i=0;i<=val;i++){
            if(p>1)
                p=0;
            if(j<m){
                if(k<n){
                    if(nums1[j]<=nums2[k]){
                        res[p] = nums1[j];
                        j++;
                    }
                    else{
                        res[p] = nums2[k];
                        k++;
                    }
                }
                else{
                    res[p] = nums1[j];
                    j++;
                }
            }
            else{
                if(k<n){
                    res[p] = nums2[k];
                    k++;
                }
            }
            p++;
        }
        if((m+n)%2==0){
            return (double)(res[0]+res[1])/2;
        }
        else{
            if(val%2==0)
                return (double)(res[0]);
            else
                return (double)(res[1]);
        }
    }
};