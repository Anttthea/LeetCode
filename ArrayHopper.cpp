/* 
 * File:   main.cpp
 * Author: liqihui
 *
 * Created on December 27, 2014, 10:54 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
 * 
 */
string jump(int A[], int n) {
        int Max = 0;
        int sequences[n];
        sequences[0] = -1;
        string output = "failure\n";
        for(int i = 0; i < n; i++){
             if(Max < i){
                 output = "failure\n";
                 break;
             }
             if(Max >= n-1){
                 output = "";
                 int k = n-1;
            while(k != -1){
                output = (to_string(k)+", ") + output ;
                k = sequences[k];
            }
            output.append("out\n");
            break;
            }
            
             int current = i + A[i];
             
             if(Max < current){
                 int num = (current < n-1) ? current : n-1;
                 for(int j = Max+1; j <= num ; j++){
                     sequences[j] = i;
                 }
                Max = current;
            }
        }
       return output;
    }

int main(int argc, char** argv) {
    int number;
    string line;
    vector<int> myvector;
      while ( getline(cin,line)){
          istringstream iss(line);
          iss >> number;
        myvector.push_back(number);
      }

        int n = myvector.size();
        int A[n];
        for(int i = 0; i < n; i++){
            A[i] = myvector[i];
        }
        string output = jump(A,n);
        cout<<output;
    return 0;
}


