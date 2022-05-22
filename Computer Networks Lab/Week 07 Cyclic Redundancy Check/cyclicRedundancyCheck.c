#include <stdio.h>
#include <string.h>

int main(){
    int i,j,keyLen,msgLen;
    char input[100], temp[100], key[30], quo[100], rem[30], key1[30];
    printf("Enter Data: \t");
    scanf("%s", input);
    printf("Enter Key");
    scanf("%s", key);
    keyLen = strlen(key);
    msgLen = strlen(input);
    strcpy(key,key1);
    for(i =0;i<keyLen;i++){
        input[msgLen+i] = '0';
    }
    for (i=0;i<keyLen;i++){
        temp[i] = input[i];
    }
    for (i =0;i<msgLen;i++){
        quo[i] = temp[0];
        if(quo[i] == '0'){
            for (j =0;j<keyLen;j++){
                key[j] = '0';
            }
        }
        else{
            for (j=0;j<keyLen;j++){
                key[j] = key1[j];
            }
            for (j=0;j<keyLen;j++){
                if (temp[j] == key[j])
                {
                    rem[j-1] = '0';
                }
                else{
                    rem[j-1] = '1';
                }
            }
            rem[keyLen-1] = input[1+keyLen];
            strcpy(temp,rem);
        }
    }
    strcpy(rem,temp);
    printf("\nQuotient is");
    for (i=0; i<msgLen; i++){
        printf("%c",quo[i]);
    }
    printf("\nRemainder is");
    for (i=0; i<keyLen-1; i++){
        printf("%c",rem[i]);
    }
    printf("\nFinal Data is");
    for (i=0; i<msgLen; i++){
        printf("%c",input[i]);
    }
    for (i=0; i<keyLen; i++){
        printf("%c",rem[i]);
    }
}