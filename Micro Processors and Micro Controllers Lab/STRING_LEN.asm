ASSUME CS:CODE,ES:EXTRA
CODE SEGMENT
MOV AX,EXTRA
MOV ES,AX
MOV AX,0000H
MOV BX,0000H
MOV DI,OFFSET STR1
MOV AL,'$'
CLD
ITER:
    SCASB
    JE EOS
    INC SI
    INC BX
LOOP ITER
EOS:
    MOV AX,0FFFFH
HLT
CODE ENDS
EXTRA SEGMENT
STR1 DB 'KALYAN$'
EXTRA ENDS
END