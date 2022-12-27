//
//  CorporateFlightBookings.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2022/12/27.
//

#include "CorporateFlightBookings.hpp"
#include <vector>

using namespace std;

class CorporateFlightBookingsSolution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> temp = vector<int>(n, 0);
        for (auto book : bookings) {
            int first = book[0];
            int last = book[1];
            int seats = book[2];
            temp[first-1] += seats;
            if (last < n) {
                temp[last] -= seats;
            }
        }
        vector<int> res = vector<int>(n, 0);
        int last = 0;
        for (int i = 0; i < n; i++) {
            res[i] += last + temp[i];
            last = res[i];
        }
        return res;
    }
};
