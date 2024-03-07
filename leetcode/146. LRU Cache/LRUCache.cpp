//
//  LRUCache.cpp
//  LeetcodeCpp
//
//  Created by XiaojianDuan on 2024/2/28.
//

#include "LRUCache.hpp"

using namespace std;

LRUCache::LRUCache(int capacity) {
    maxCount = capacity;
}

int LRUCache::get(int key) {
    if (map.find(key) == map.end()) {
        return -1;
    }
    auto node = *map[key];
    list.erase(map[key]);
    list.push_front(node);
    map[key] = list.begin();
    return node.second;
}

void LRUCache::put(int key, int value) {
    if (map.find(key) == map.end()) {
        if (list.size() == maxCount) {
            map.erase(list.back().first);
            list.pop_back();
        }
    }
    else {
        list.erase(map[key]);
    }
    list.push_front({key, value});
    map[key] = list.begin();
}
