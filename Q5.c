#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    size_t len = strlen(s);

    if(len == 1) return s;
    if(len == 2) return (s+1);

    char *pstr = (char*)calloc(len, sizeof(char));
    pstr[0] = s[0];
    pstr[1] = '\0';
    size_t len_of_curr_pstr=1;
    printf("current pstr: %s \npstr_len: %ld\n", pstr, len_of_curr_pstr);
    uint16_t cursor=1;
    uint16_t front;
    int16_t back;
    
    while(cursor<len-1)
    {
        front = cursor;
        back = (int16_t)cursor;
        
        if(s[back] == s[front+1]) {
            front++;
        }

        do {
            printf("current s[%d], s[%d] : %c %c \n", back, front, s[back], s[front]);
            if((s[back]  ==   s[front]) &&  ((front - back)+1  >   len_of_curr_pstr)) {
                len_of_curr_pstr = (front - back)+1;
                strncpy(pstr, (s+back), len_of_curr_pstr);
                pstr[len_of_curr_pstr] = '\0';
                printf("current pstr: %s \npstr_len: %ld\n", pstr, len_of_curr_pstr);
                ++front;
                --back;
                continue;
            } 
            printf("break\n");
            break;
        } while(
            (front < len)   &&  (back >= 0)
        );
        ++cursor;
    }

    return pstr;
}


int main(void) 
{
    const char *str = "1223245baabad"; // "sdfg adda hjk"
    char* pstr = longestPalindrome((char*)str);

    printf("longest palindrome string: %s\n", pstr);

    return 0;
}