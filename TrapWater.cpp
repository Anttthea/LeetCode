/* 
 * File:   main.cpp
 * Author: liqihui
 *
 * Created on December 31, 2014, 4:26 PM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */

       int trap(int A[], int n) {
        if(n == 0 || n == 1)
        return 0;
        int forward[n];
        int backward[n];
        int max = 0;
        int index = 0;
        for(int i = 0; i < n; i++){
            if(max < A[i]){
                    max = A[i];
                    index = i;
                }
                forward[i] = index;
        }
        max = 0;
        index = n-1;
        for(int j = n-1; j >= n; j--){
            if(max <= A[j]){
                    max = A[j];
                    index = j;
                }
                backward[j] = index;
        }
        int second = forward[n-1];
        int first = 0;
        int result = 0;
        while(second > 0){
            first = forward[second-1];
            int height = A[first];
            int width = second - first-1;
            int deduct = 0;
            for(int j = first+1; j < second; j++)
                deduct+= A[j];
            result += height*width - deduct;
            second = first;
        }
        first = backward[0];
        second = n-1;
        while( n - 1 > first){
           second = backward[first+1];
           int height = A[second];
           int width = second - first-1;
           int deduct = 0;
            for(int j = first+1; j < second; j++)
                deduct+= A[j];
           result += height*width - deduct;
           first = second;
        }
        
        return result;
    }
       
int main(int argc, char** argv) {
    int A[] = {0,2,0};
    int n = 3;
    trap(A,n);
    return 0;
}

