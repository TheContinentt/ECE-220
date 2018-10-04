.ORIG x3000
AND R0, R0, #0;
AND R1, R1, #0
ADD R1, R1, #2
JSR BITSWAP
LEA R0, RETURNED
PUTS
HALT

RETURNED .STRINGZ "Successfully Returned\n"
; x3000

LD R2, STRSTART

LOOP
LDR R0, R2, #0
BRz FINISH		; We are done when we hit NULL
LD R1, BITMASK
JSR BITSWAP		; Do the bitswap
STR R0, R2, #0		; Writes back to the original location
ADD R2, R2, #1
BRnzp LOOP 
FINISH 
HALT

STRSTART .FILL x4000
BITMASK .FILL x0003	; set n = 3

;Do not touch or change and code above this line
;---------------------------------------------
;You must not change the separation line above
;Please write ALL your code for BITSWAP in between the separations lines,
;including all the labels, code, and .FILL commands

 
;Subroutine to swap bits
;Input: 
;R0: the ascii that to be swapped 
;R1: the number of bits to be swapped
; You can assume R1 is always 0, 1, 2, or 3
;Output: R0, the swapped ascii
BITSWAP
;;YOUR CODE STARTS HERE
		ST R0, SAVE_RR0
		ST R2, SSAVE_R2
		ADD R2, R1, #0
		BRz ZEROO
		ADD R2, R2, #-1
		BRz ONEE
		ADD R2, R2, #-1
		BRz TWOOO
		ADD R2, R2, #-1
		BRz THREE
		ADD R2, R2, #-1
		BRz FOURRR

ZEROO
		LD R2, ZEROOO
		AND R0, R0, R2
		BRnzp NEXTTT
ONEE
		LD R2, ONEEE
		AND R0, R0, R2
		BRnzp NEXTTT
TWOOO
		LD R2, TWOOOO
		AND R0, R0, R2
		BRnzp NEXTTT
THREE
		LD R2, THREEE
		AND R0, R0, R2
		BRnzp NEXTTT
FOURRR
		LD R2, FOURRRR
		AND R0, R0, R2
		BRnzp NEXTTT

NEXTTT
		ADD R6, R0, #0					;MIDDLE IN R6

MOSTT	LD R0, SAVE_RR0
		ST R1, SAVE_RR1
		ST R7, SAVE_RRR7
		JSR EXTRACT
		LD R7, SAVE_RRR7
		LD R1, SAVE_RR1
		NOT R5, R1
		ADD R5, R5, #1
		ADD R5, R5, #8

AAAD	ADD R6, R6, R0

LEEAT	LD R0, SAVE_RR0	
		LD R1, SAVE_RR1
		ADD R1, R1, #0
		BRz FINISHH
		ADD R1, R1, #-1
		BRz ZRR
		ADD R1, R1, #-1
		BRz TWWW
		ADD R1, R1, #-1
		BRz TTRE
		ADD R1, R1, #-1
		BRz FFRE

ZRR
		LD R3, OOO
		AND R0, R3, R0
		BRnzp FFFI
TWWW
		LD R3, TT
		AND R0, R3, R0
		BRnzp FFFI
TTRE
		LD R3, TTT
		AND R0, R3, R0
		BRnzp FFFI
FFRE
		LD R3, FFF
		AND R0, R3, R0
		BRnzp FFFI
FINISHH
		AND R0, R0, #0

FFFI
		ADD R0, R0, R0
		ADD R5, R5, #-1
		BRp FFFI
		ADD R6, R0, R6
		ADD R0, R6, #0
		LD R2, SSAVE_R2
		RET

ZEROOO		.FILL xFFFF
ONEEE		.FILL x007E
TWOOOO		.FILL x003C
THREEE		.FILL x0018
FOURRRR		.FILL X0000
SAVE_RRR7	.BLKW #1
SAVE_RR0	.BLKW #1
SAVE_RR1	.BLKW #1
OOO			.FILL x0001
TT			.FILL x0003
TTT			.FILL x0007
FFF			.FILL x000F
SSAVE_R2	.BLKW #1
;You must not change the separation line below.
;Write all your code for BITSWAP above this line
;=============================================


;DO NOT CHANGE THE GIVEN CODE BELOW
;=============================================
;;EXTRACT Subroutine (Given Code) 
;;Input: R0 - ASCII value
;;       R1 - n (between 0 and 4) bits to be extracted
EXTRACT
ST R0, SAVER1
ST R7, SAVER3
LEA R0, EXCALLED
PUTS
LD R0, SAVER1
LD R7, SAVER3
RET
EXCALLED .STRINGZ "\nEXTRACT CALLED\n"
SAVER1 .FILL #0
SAVER2 .FILL #0
SAVER3 .FILL #0
.END
