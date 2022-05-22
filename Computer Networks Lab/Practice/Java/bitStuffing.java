import java.io.*;
import java.util.*;

public class bitStuffing{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int i =0, count = 0;
        String char_array = new String();
        System.out.print("Enter the bits \t");
        char_array = scan.nextLine();
        System.out.print("\nAfter bit stuffing \n");
        System.out.print("01111110 "); // Dummy representation for source information (Header) in Data link layer
        for(i=0;i<char_array.length();i++){
            if (char_array.charAt(i) == '1'){  //charAt() to find character at given index
                count++;
            }
            else{
                count = 0;
            }
            System.out.print(char_array.charAt(i));
            if (count == 5){
                count = 0;
                System.out.print("0");
            }
        }
        System.out.print(" 01111110"); // Dummy representation for destination information (Trailer) in Data link layer
    }
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