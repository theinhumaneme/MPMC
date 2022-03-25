ASSUME CS:CODE, DS:DATA

CODE SEGMENT
MOV AX,DATA
MOV DS,AX
MOV AX,0000H
MOV DL,ARR_SIZE
DEC DL

OUTER:
        MOV CL,DL
        MOV SI,OFFSET ARRAY
INNER:
        MOV AX,[SI]
        CMP AX,[SI+2]
        JLE ITER
        XCHG AX,[SI+2]
        MOV [SI],AX
ITER:
        INC SI
        INC SI
        LOOP INNER
        DEC DL
        JNZ OUTER
HLT
CODE ENDS
DATA SEGMENT
ARR_SIZE DB 05H
ARRAY DB 0001H, 0002H, 0003H, 0004H, 0005H
DATA ENDS
END