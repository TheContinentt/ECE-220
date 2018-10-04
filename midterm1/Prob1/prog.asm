; Implement a program to find the nearest smaller (or equal) perfect square of a given positive number
; The input will be stored in R2 and output (the nearest perfect square) should be stored in R3
; TODO: Write a subroutine called "PSquare" which returns the nearest perfect square of a given input and 
;       you must invoke this subroutine in the main part.
; Note : R2, R4, R5 and R6 must be left unchanged in PSquare.
;
; 
; PSquare :  input is stored in R2
;            output is stored in R3

.ORIG	x3000		; starting address is x3000

;;YOUR CODE STARTS HERE
		ST R2, SAVE_R2
		ADD R2, R2, #0
		BRnz INVALID
		ST R7, SAVE_R7
		ST R4, SAVE_RR4
		ST R2, SAVE_R2
		ST R5, SAVE_R5
		ST R6, SAVE_R6
		JSR PSquare
		LD R7, SAVE_R7
		LD R2, SAVE_R2
		ST R7, SAVE_R7
		JSR SSQUARE
		LD R7, SAVE_R7
		LD R2, SAVE_R2
		LD R4, SAVE_RR4
		LD R5, SAVE_R5
		LD R6, SAVE_R6
		BRnzp TRAPP

INVALID
		AND R3, R3, #0

TRAPP
		TRAP x25


PSquare
		ST R4, SAVE_R4
		AND R6, R6, #0
		AND R1, R1, #0

NEXTT	ST R2, SAVEE_R2
		ADD R1, R1, #1
		ST R7, SAVE_RR7
		JSR SQUARE
		LD R7, SAVE_RR7
		LD R2, SAVEE_R2
		NOT R0, R0
		ADD R0, R0, #1
		ADD R0, R0, R2
		BRzp NEXTT
		ADD R1, R1, #-1
		ADD R3, R1, #0
		LD R4, SAVE_R4
		RET





SQUARE	ST R1, SAVE_R1
		AND R0, R0, #0
		AND R4, R4, #0
		ADD R4, R1, R4
MULT	ADD R0, R1, R0
		ADD R4, R4, #-1
		BRp MULT
		ADD R0, R0, #0
		LD R1, SAVE_R1
		RET		

SSQUARE
		ADD R0, R3, #0
		AND R1, R1, #0
LLP		ADD R1, R1, R3
		ADD R0, R0, #-1
		BRp LLP
		ADD R3, R1, #0
		RET



SAVE_R2		.BLKW #1
SAVE_R7		.BLKW #1
SAVE_RR7	.BLKW #1
SAVEE_R2	.BLKW #1
SAVE_R1		.BLKW #1
SAVE_R4		.BLKW #1
SAVE_RR4	.BLKW #1
SAVE_R5		.BLKW #1
SAVE_R6		.BLKW #1


.END



