/*
Sliding window protocol has two types:
Go-Back-N ARQ
Selective Repeat ARQ
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>

// Global Declartion of no of dataFrames to be sent
int numFrames;

// To select a random dataFrame to simulate collisions
int randInt;

struct dataFrame{
    int data;
    char acknowledge;
}frames[100]; // Overhead Frames

void sendData();
void receiveAck();
void reSendData(int protocol);
void windowProtocol(int protocol);

// Take User given data to form dataFrames
void sendData(){
    printf("Enter the number of packets to be sent\n");
    scanf("%d",&numFrames);
    for (int i=0;i<numFrames;i++){
        printf("Enter the Value for packet[%d]\t",i);
        scanf("%d",&frames[i].data);
        frames[i].acknowledge = 'Y';
    }
    printf("\n");
}

/*
protocol == 1 --> Go-Back-N ARQ
protocol == 2 --> Selective-Repeat ARQ
*/

void receiveAck(){
    randInt = rand()%numFrames; // Generate a random number in range [0:numFrames-1]
    frames[randInt].acknowledge = 'N';
    for(int i=0;i<numFrames;i++){
        if( frames[i].acknowledge == 'N'){
            printf("The packet number %d is not received\n",i);
        }
    }
}
void reSendData(int protocol){
    switch(protocol){
        // GO-BACK N-ARQ
        case 1:
            printf("Resending from packet %d\n",randInt);
            for(int i=randInt;i<numFrames;i++){
                sleep(2);
                frames[i].acknowledge = 'Y';
                printf("Received packet %d data is %d\n",i,frames[i].data);
            }
            break;
        // SELECTIVE REPEAT
        case 2:
            printf("Resending packet %d\n",randInt);
            frames[randInt].acknowledge = 'Y';
            printf("Received packet %d data is %d\n",randInt,frames[randInt].data);
            break;
    }
}
void windowProtocol(int protocol){
    sendData();
    receiveAck();
    // 1 --> Go-Back N-ARQ 2 --> Selective Repeat
    reSendData(protocol);
}
int main(){
    int choice;
    do{
        printf("\n\nChoose one of the following Protocols\n1.Go-Back N-ARQ\n2.Selective repeat ARQ\n3.Exit\n");
        printf("Enter your choice\t");
        scanf("%d",&choice);
        switch(choice){
            // Go-Back N-ARQ
            case 1:
                windowProtocol(1);
                break;
            // Selective Repeat
            case 2:
                windowProtocol(2);
                break;
            // Exit from program
            case 3:
                exit(0);
                break;
            default:
                printf("\nPlease enter a valid input\n");
                break;
        }
    }while(1);
}