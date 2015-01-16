/* 
 * File:   main.cpp
 * Author: liqihui
 *
 * Created on January 9, 2015, 7:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
 double pow(double x, int n) {
        vector<int> record;
        int i = 0;
      //  memeset(record,0,sizeof(record));
        bool nega = false;
        if( n < 0 ) nega = true;
        n = abs(n);
        while(n > 0){
            record.push_back(n % 2); 
            n = n / 2;
            i++;
        }
        
        double result = 1.0;
        double current = x;
        if(nega) current = 1/x;
        for(int j = 0; j < i; j++){
            if(record[j] == 1)
                result *= current;
            current *= current;
        }
        
        return result;
    }
 
int main(int argc, char** argv) {
    //int n = 2147483647;
    //int j = n % 2;
    //cout<<j;
    cout.precision(15);
    cout<<fixed<<pow(34.00515,-3)<<"\n";
    return 0;
}

