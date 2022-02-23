ORG 00H				;SET ORGIN TO 00H
MOV SCON,#40H 		;MOVE SCON #40H
MOV TMOD,#20H		;MOVE VALUE 40H TO TMOD
MOV TH1,#-3			;MOVE TIMER BAUD RATE
SETB TR1			;SET TIMER1 RUN
MOV SBUF,#'F'		;MOVE 'F' INTO SBUF
BACK:JNB TI,BACK	;STAY IN BACK UNTIL TRANSMIT INTERRUPT BIT IS 1 / TRANSMISSION IS COMPLETE
CLR TI				;CLEAR TRANSMISSION INTERRUPT
CLR TR1				;CLEAR TIMER1 RUN BIT
END					;END PROGRAM