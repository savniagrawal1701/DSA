
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int n1 = nums1.size(), n2 = nums2.size();

    int n = n1 + n2;

    int ind2 = n / 2;
    int ind1 = ind2 - 1;

    int cnt = 0, i = 0, j = 0;
    int ind1el = -1, ind2el = -1;

    while (i < n1 && j < n2) {

    
        if (nums1[i] < nums2[j]) {
            if (cnt == ind1) ind1el = nums1[i];
            if (cnt == ind2) ind2el = nums1[i];
            i++;
        } else {
            if (cnt == ind1) ind1el = nums2[j];
            if (cnt == ind2) ind2el = nums2[j];
            j++;
        }
        cnt++;
    }

    while (i < n1) {
        if (cnt == ind1) ind1el = nums1[i];
        if (cnt == ind2) ind2el = nums1[i];
        cnt++;
        i++;
    }

    while (j < n2) {
        if (cnt == ind1) ind1el = nums2[j];
        if (cnt == ind2) ind2el = nums2[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1) return (double)ind2el;
    return (ind1el + ind2el) / 2.0;
  
    }
};
int main() {
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    Solution s1;
    double ans=s1.findMedianSortedArrays(a,b);
    cout<<"Medain of two Sorted array is"<<" "<<ans;
    return 0;
}
