// Bit Stuffing
#include <stdio.h>
int main(){
    int i=0,count=0;
    char char_array[100];
    printf("Enter the bits \t");
    scanf("%s",char_array);
    printf("\nAfter bit stuffing \n");
    printf("01111110 "); // Dummy representation for source information (Header) in Data link layer
    for(int i=0;char_array[i];i++){
        if (char_array[i] == '1'){
            count++;
        }
        else{
            count = 0;
        }
        printf("%c",char_array[i]);
        if (count==5){
            printf("0");
            count=0;
        }
    }
    printf(" 01111110"); // Dummy representation for destination information (Trailer) in Data link layer
    printf("\n");
    return 1;
}

// Example-1:
// Input : 111111
// Output : 01111110 1111101 01111110

// Example-2:
// Input : 11111100111111100001100
// Output : 01111110 1111101001111101100001100 01111110

// Example-3:
// Input : 101010101010101010
// Output : 01111110 101010101010101010 01111110

// Example-4:
// Input : 11111001111101
// Output : 01111110 1111100011111001 01111110





