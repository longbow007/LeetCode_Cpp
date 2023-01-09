//
//  24Game.cpp
//  Algorithm-Cpp
//
//  Created by Xiaojian Duan on 2023/1/9.
//

#include "24Game.hpp"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class TwentyFourGameSolution {
public:
    static constexpr double EPSILON = 1e-6;
    bool dfs(vector<double>& cards) {
        if (cards.empty()) {
            return false;
        }
        if (cards.size() == 1) {
            return fabs(cards[0] - 24) < EPSILON;
        }
        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                if (i == j) {
                    continue;
                }
                auto newCards = vector<double>();
                for (int k = 0; k < cards.size(); k++) {
                    if (k != i && k != j) {
                        newCards.push_back(cards[k]);
                    }
                }
                // 0 - add; 1 - multiply; 2 - subtrack; 3 - divide;
                for (int op = 0; op < 4; op++) {
                    if (op < 2 && i > j) {
                        continue;
                    }
                    double a = cards[i];
                    double b = cards[j];
                    if (op == 0) {
                        newCards.push_back(a + b);
                    } else if (op == 1) {
                        newCards.push_back(a * b);
                    } else if (op == 2) {
                        newCards.push_back(a - b);
                    } else {
                        if (b < EPSILON) {
                            continue;
                        }
                        newCards.push_back(a / b);
                    }
                    if (dfs(newCards)) {
                        return true;
                    }
                    newCards.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        auto vec = vector<double>();
        for (int x : cards) {
            vec.push_back(static_cast<double>(x));
        }
        return dfs(vec);
    }
};

void test_24game() {
    vector<int> v = vector<int>(4, 0);
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    vector<double> v2 = vector<double>(4, 0.0);
    for (int i = 0; i < 4; i++) {
        v2[i] = static_cast<double>(v[i]);
    }
    auto solution = TwentyFourGameSolution();
    string res = solution.dfs(v2) ? "true" : "false";
    cout<<res<<endl;
}
