//stop and wait protocol

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
int main()
{
    int i,j,packet[30];
    int fsize=(rand()%16)+1;
    printf("\n \t Frame Size  :  %d \n ",fsize);
    printf("\n \t --------DATA LOG-------\n");
    printf("\nFrame   Data  WAITING  ACKNOW   RESEND");
    for(i=0;i<fsize;i++)
    {
        packet[i]=rand()%1000;
        printf("\n   %d   \t %d",i+1,packet[i]);
        while(j==0 ||rand()%2==0)
        {
            sleep(1);
            printf("\t1");
            sleep(1);
            for(j=2;rand()%2==0&&j<4;j++)
            {
                printf("%d",j);
                sleep(1);
            }
        if(j==4)
            printf("\t NO \t RESENDING... \n %d \t %d",i+1,packet[i]);
        else
            break;
        }
    if(j==0)
        {
          sleep(1);
          printf("\t0");
        }
    printf("\t    YES  \t    NO");
    }
    printf("\n \n -------ALL DATA PACKETS SENT---------\n");
    return 0;
}


// Output:
// ----------
// Frame Size  :  8
// --------DATA LOG-------

// Frame   Data  WAITING  ACKNOW   RESEND
// 1   	 886	 0	    YES  	    NO
// 2   	 915	 0	    YES  	    NO
// 3   	 335	2	    YES  	    NO
// 4   	 421		    YES  	    NO
// 5   	 690	 0	    YES  	    NO
// 6   	 763	23	 NO 	 RESENDING...
// 6 	 763		    YES  	    NO
// 7   	 368	 0	    YES  	    NO
// 8   	 429	23	 NO 	 RESENDING...
// 8 	 429	 0	    YES  	    NO

//  -------ALL DATA PACKETS SENT---------