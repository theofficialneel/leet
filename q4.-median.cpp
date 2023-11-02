#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int i = 0, j = 0;
    float median;
    while(i+j < (m+n)/2) {
        if (i >= m) {
            median = nums2[j];
            j++;
        } else if (j >= n) {
            median = nums1[i];
            i++;
        } else if (nums1[i] < nums2[j]) {
            median = nums1[i];
            i++;
        } else {
            median = nums2[j];
            j++;
        }
    }
    if ( (m+n) % 2 == 0) {
        if (i >= m) {
            median += nums2[j];
        } else if (j >= n) {
            median += nums1[i];
        } else if (nums1[i] < nums2[j]) {
            median += nums1[i];
        } else {
            median += nums2[j];
        }
        median = (float) median / 2.0;
    } else {
        if (i >= m) {
            median = nums2[j];
        } else if (j >= n) {
            median = nums1[i];
        } else if (nums1[i] < nums2[j]) {
            median = nums1[i];
        } else {
            median = nums2[j];
        }
    }
    return median;
}