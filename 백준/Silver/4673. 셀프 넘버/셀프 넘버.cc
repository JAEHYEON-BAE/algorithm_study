#include <stdio.h>

int main() {
        int n[10035] = {1}, i=9999;
        while (i--) 
                n[i + i%10 + (i/10)%10 + (i/100)%10 + (i/1000)%10]++;
        for( ; i++<10001 ;)
                if(!n[i])
                        printf("%d\n",i);
}