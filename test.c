#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


bool inDiapozon(char s[100]){
    // bool norm = true;
    if((s[0] == '-' && strlen(s) > 6) || (s[0] != '-' && strlen(s) > 5)){
        return false;
    }

    char maxp[7] = "65536"; 
    char maxo[7] = "-65536"; 
    if((s[0] == '-' && strlen(s) == 6) || (s[0] != '-' && strlen(s) == 5)){
        if(s[0] == '-'){
            for(int i = 1; i < strlen(s); ++i){
            //     // 0 1 _ _ _
            //    if(!(s[i] - '0' <= maxo[i] - '0')){
            //         return false;
            //    } 
            if(s[i]-'0' < maxo[i]-'0'){
                return true;
            }else if(s[i]-'0' > maxo[i] - '0'){
                return false;
            }else{
                continue;
            }
            }
        }else{
          for(int i = 0; i < strlen(s); ++i){
               if(s[i]-'0' < maxp[i]-'0'){
                return true;
            }else if(s[i]-'0' > maxp[i] - '0'){
                return false;
            }else{
                continue;
            }
            } 
        }
    }

    return true;
}

int main(){
    char s[7] = "34248";
    printf("%d", inDiapozon(s));
    return 0;
}