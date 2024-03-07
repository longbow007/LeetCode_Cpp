//
//  LRUCache.hpp
//  LeetcodeCpp
//
//  Created by XiaojianDuan on 2024/2/28.
//

#ifndef LRUCache_hpp
#define LRUCache_hpp

#include <stdio.h>
#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);
private:
    int maxCount;
    std::list<std::pair<int, int>> list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
};

#endif /* LRUCache_hpp */
