//
//  MedianOfTwoSortedArrays.cpp
//  LeetcodeCpp
//
//  Created by XiaojianDuan on 2024/3/18.
//

#include "MedianOfTwoSortedArrays.hpp"
#include <vector>

using namespace std;

//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        long m = nums1.size(), n = nums2.size();
//        if (m == 0 && n == 0) {
//            return 0;
//        }
//        // 总个数是否为奇数
//        bool isOdd = ((m + n) % 2 != 0);
//        long j = 0.5 * (m + n);
//        long i = j - 1;
//        if (nums1[m - 1] <= nums2[0]) {
//            if (m == n) {
//                return 0.5 * (nums1[m - 1] + nums2[0]);
//            }
//            if (m > n) {
//                if (isOdd) {
//                    return nums1[j];
//                } else {
//                    return 0.5 * (nums1[i] + nums1[j]);
//                }
//            }
//            if (m < n) {
//                if (isOdd) {
//                    return nums2[j];
//                } else {
//                    return 0.5 * (nums1[i] + nums1[j]);
//                }
//            }
//        }
//        else if (nums1[0] <= nums2[0] && nums1[m - 1] > nums2[0] && nums1[m - 1] < nums2[n - 1]) {
//            
//        }
//    }
//};
