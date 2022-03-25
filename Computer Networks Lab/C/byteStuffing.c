#include <stdio.h>
#include <string.h>

int main(){
    int j, l, c, k;
    char input_string[50], encoded_string[50];
    printf("Enter the string\n");
    scanf("%s",input_string);
    strcpy(encoded_string,"DELSTX");
    int input_string_len = strlen(input_string);
    for(j=0;j<input_string_len;j++){
        if (input_string[j] == 'd' && input_string[j+1] == 'l' && input_string[j+2] == 'e'){ // check if input string has "dle"
        c = j+2;
        for (l=0;l<3;l++){
            for (k=input_string_len;k>c;k--){
                input_string[k] = input_string[k-1];
            }
            input_string_len++;
            input_string[input_string_len] = ' ';
            c+=1;
            }
            input_string[j+3] = 'd';
            input_string[j+4] = 'l';
            input_string[j+5] = 'e';
            input_string[input_string_len] = ' ';
            j=j+5;
        }
    }
    strcat(encoded_string,input_string);
    strcat(encoded_string,"DLEETX");
    printf("%s",encoded_string);
    for(j=0;j<input_string_len;j++){
        if (input_string[j] == 'd' && input_string[j+1] == 'l' && input_string[j+2] == 'e'){ // check if input string has "dle"
        c = j;
        for (l=0;l<3;l++){
            for ( k=3;k<input_string_len;k++){
                input_string[k] = input_string[k+1];
            }
        }
        c++;
        j=c;
        }
    }
    printf("\n%s\n",input_string);
}