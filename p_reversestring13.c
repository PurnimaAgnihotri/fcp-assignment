#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    int len;
    printf("\nEnter a string\n");
    scanf("%s",&str);
    len=strlen(str);
    printf("\nThe reverse string is :\n");
    for(int i=len-1;i>=0;i--){
        
        printf("%c",str[i]);
    }
}
