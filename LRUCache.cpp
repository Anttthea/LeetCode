/* 
 * File:   main.cpp
 * Author: liqihui
 *
 * Created on January 9, 2015, 10:21 PM
 */

#include <cstdlib>
#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
 * 
 */
class LRUCache{
public:
    int capacity;
    int size;
    list<int> cache;
    unordered_map<int,int> cacheMap;
    unordered_map<int,list<int>::iterator> cachePointers;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
       // this->cacheMap = new unordered_map<int,int>;
       // this->cachePointers = new unordered_map<int,list<int>::iterator>; 
    }
    
    int get(int key) {
        if(cacheMap.count(key) > 0){
            cache.erase(cachePointers.find(key)->second);
            list<int>::iterator iter = cache.insert(cache.end(), key);
            
            cachePointers.erase(key);
            cachePointers.insert(pair<int,list<int>::iterator> (key,iter));
 
            return cacheMap.find(key)->second;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        if(cacheMap.count(key) <= 0){
            cacheMap.insert(pair<int,int> (key,value));
            
            if(size < capacity){
                size++;
            }else{
                int del = cache.front();
                cache.pop_front();
                cacheMap.erase(del);
            }
             
            list<int>::iterator iter = cache.insert(cache.end(), key);
           
            cachePointers.insert(pair<int,list<int>::iterator> (key,iter));
            //cachePointers.insert(pair<int,list<int>::iterator> (key,cache.end()));
            // cache.push_back(key);      
        }else{
            cacheMap.erase(key);
            cacheMap.insert(pair<int,int> (key,value));
            
            cache.erase(cachePointers.find(key)->second);
            
             list<int>::iterator iter = cache.insert(cache.end(), key);
          
            cachePointers.erase(key);
            cachePointers.insert(pair<int,list<int>::iterator> (key,iter));
            
        }
    }
};

int main(int argc, char** argv) {
    LRUCache c(2);
    c.set(2,1);
    c.set(2,2);
    cout<<c.get(2)<<"\n";
    c.set(1,1);
    c.set(4,1);
    cout<<c.get(2)<<"\n";
    return 0;
}

