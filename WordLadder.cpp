/* 
 * File:   main.cpp
 * Author: liqihui
 *
 * Created on December 27, 2014, 8:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stdio.h>
#include <queue> 

using namespace std;

/*
 * 
 */

int ladderLength(string start, string end, unordered_set<string> &dict) {
         unordered_map<string,int> dis;
       string word;
       int length = start.length();
       dis[start] = 1;
       queue<string> words;
       words.push(start);
      dict.insert(end);
       while( !words.empty()){
            word = words.front();
            cout<<"word: "<<word<<"\n";
            words.pop();
            
            int pathlength = dis.at(word) + 1;
           for(int i = 0; i < length; i++){
               string temp = word;
               for(char ch = 'a'; ch < 'z'; ch++){
                   temp[i] = ch;
                   if(dict.count(temp) > 0){
                       if(temp == end)
                            return pathlength;
                       dis[temp] = pathlength;
                       dict.erase(temp);
                       cout<<temp<<": "<<pathlength<<"\n";
                       words.push(temp);
                   }
               }
       }
       }
       
       if(dis.count(end) > 0){
           return dis.at(end);
       }else
        return 0;
}


int main(int argc, char** argv) {
    string start = "hot";
    string end = "dog";
    unordered_set<string> dict;
    dict = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    int ans = ladderLength(start,end,dict);
    cout<<ans;
    return 0;
}

