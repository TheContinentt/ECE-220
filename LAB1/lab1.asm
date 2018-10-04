 ;Lab 1 
 ; assignment: develop a code to print a value stored in a register 
 ;             as a hexadecimal number to the monitor
 ; algorithm: turnin each group of four bits into a digit
 ;            calculate the corresponding ASCII character;
 ;            print the character to the monitor

 .ORIG x3000
			AND R0, R0, #0
			AND R1, R1, #0
			ADD R1, R1, #4			;COUNTER OF EACH HEXADECIMAL DIGIT
			AND R2, R2, #0			;REGISTER OF HEXADECIMAL OUTPUT
			AND R6, R6, #0			;Counter of printed digits
			ADD R6, R6, #-5

NEWDIGITS	ADD R6, R6, #1
			BRzp HALTT
			AND R2, R2, #0
			AND R1, R1, #0
			ADD R1, R1, #4

NEWBITS		ADD R1, R1, #-1
			BRnz PRINTOUT
			ADD R3, R3, #0
			BRzp PRINTR
			ADD R2, R2, #1
			BRnzp LEFTSHIFTR

PRINTR		ADD R2, R2, #0

LEFTSHIFTR	ADD R2, R2, R2
			ADD R3, R3, R3
			BRnzp NEWBITS			;INCREMENT DIGIT COUNTER
			
PRINTOUT	ADD R3, R3, #0
			BRzp POSITIVE
			ADD R2, R2, #1
			BRnzp OUTPUTR

POSITIVE	ADD R2, R2, #0

OUTPUTR		ADD R3, R3, R3
			ADD R2, R2, #-9
			BRnz ASCII
			ADD R2, R2, #15
			ADD R2, R2, #15
			ADD R2, R2, #15
			ADD R2, R2, #15
			ADD R2, R2, #4
			BRnzp OUTPUT

ASCII		ADD R2, R2, #15
			ADD R2, R2, #15
			ADD R2, R2, #15
			ADD R2, R2, #12
			
OUTPUT		ADD R0, R2, #0
			OUT
			BRnzp NEWDIGITS

HALTT		TRAP x25				
 ; stop the computer


 ; program data section starts here
DATA		.FILL x3BCD

 .END

