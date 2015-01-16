/* 
 * File:   main.cpp
 * Author: liqihui
 *
 * Created on January 4, 2015, 1:24 PM
 */

#include <cstdlib>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>


using namespace std;

/*
 * 
 */
 bool isMatch(const char *s, const char *p) {
        int slength = strlen(s);
        int plength = strlen(p);
        int sindex = 0;
        int pindex = 0;
        bool result = true;
        char * pch;
        char pp[plength+1];
        memcpy( pp, &p[0], plength+1 );
        //pp[plength] = '\0';
        pch = strtok (pp, "*");
        int length = strlen(pch);
        if(pch != NULL) {
            
            if(length < plength){
                if( *p != '*'){
                //   cout<<pch;
                   sindex += length;
                   pindex += length;
                   char subs[length+1];
                   memcpy( subs, &s[0], length );
                   subs[length] = '\0';
                   char pch2[length+1];
                   memcpy(pch2, &pch[0],length);
                   pch2[length] = '\0';
                   pch = strtok(NULL,"*");
                   if(!isMatch(subs,pch2))
                     return false;
               }

            if(pch != NULL){
                
               char * qpch;
               int length = strlen(pch);
               char pch3[length+1];
                   memcpy(pch3, &pch[0],length);
                   pch3[length] = '\0';
               const char* ppch = strstr(p+pindex,pch3);
               pindex = ppch - p;
               qpch = strtok(pch3,"?");
               if(qpch == NULL) 
                qpch = pch;
               const char * spch;
               spch = strstr (s+sindex,qpch); 
               while(spch != NULL){
                  int length = strlen(qpch);
                  pindex += length;
                  sindex = spch - s + length;
                   if (!isMatch(s+sindex,p+pindex)){
                      spch = strstr (s+sindex,qpch); 
                   }else{
                      result = true;
                      break;
                   }
               }
               if(spch == NULL) result =  false;
            }else
                return true;

            
            }
        }
        else return true;
        
        
        
        while(pindex < plength){
            if(sindex >= slength)
                result = false;
            if(result == false)
                break;
            char pcurrent = *(p+pindex);
            char scurrent = *(s+sindex);
            
            switch(pcurrent){
                case '?': 
                        break;
                default : 
                   result =  (pcurrent == scurrent) ? true : false;
                   break;
                    
            }
            sindex++;
            pindex++;
        }
        if(sindex < slength ) result = false;
        return result;
    }
 
int main(int argc, char** argv) {
    char s[] = "abefcdgiescdfimde";
    char p[] = "ab*cd?i*de";
    bool result = isMatch(s,p);
  if(result){
       printf ("true");
  }
  else{
      cout<<"false";
  }
//    char * pch =strtok(p,"*");
//  while (pch != NULL)
//  {
//    printf ("token: %s\n",pch);
//    pch = strtok (NULL, " *");
//  }
  return 0;
}

