/* 
 * File:   main.cpp
 * Author: liqihui
 *
 * Created on January 9, 2015, 4:59 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 
 */
int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int steps[n+1][m+1];
        
        for(int i = 0; i < n+1; i++)
            steps[i][0] = i;
            
        for(int i = 0; i < m+1; i++)
            steps[0][i] = i;
            
        for(int i = 1; i < n+1; i++){
           for(int j = 1; j < m+1; j++){
               int steps1 = steps[i-1][j] + 1;
               int steps2 = steps[i][j-1] + 1;
               int steps3 = steps[i-1][j-1];
               if( word1[i-1] != word2[j-1]) steps3++;
               int step = min(steps1,steps2);
               step = min(step, steps3);
               steps[i][j] = step;
           } 
        }
        
        return steps[n][m];
    }
int main(int argc, char** argv) {
    string a = "";
    string b = "";
    cout<<minDistance(a,b)<<"\n";
    return 0;
}

