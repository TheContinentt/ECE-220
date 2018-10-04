;Reverse Characters
;n characters are provided to you
;in which n is a positive number stored at x4FFF
;characters stored in sequential memory location
;starting at x5000
;Use the subroutine REVERSE to flip the order

.ORIG x3000

;your program starts here
		AND R0, R0, #0
		AND R2, R2, #0
		AND R4, R4, #0
		JSR REVERSE
		LDI R2, NUM_ADDR
		LD R4, CHAR_ADDR
OUTLOOP
		ADD R0, R4, #0
		LDR R0, R0, #0
		OUT
		LD R0, NEW_CHAR
		OUT
		ADD R4, R4, #1
		ADD R2, R2, #-1
		BRp OUTLOOP

TRAPP	TRAP x25

;REVERSE subroutine:
;reverse the order of n characters starting at x5000
;SWAPMEM subroutine must be called here, not in the main user program
REVERSE
		LDI R6, NUM_ADDR
		LD R5, CHAR_ADDR
		ADD R1, R6, R5
		ADD R1, R1, #-1
		ADD R0, R5, #0
CHANGE
		ST R7, SAVE_R7
		ST R1, SSAVE_R1
		ST R0, SSAVE_R0
		JSR SWAPMEM
		LD R7, SAVE_R7
		LD R1, SSAVE_R1
		LD R0, SSAVE_R0
		ADD R1, R1, #-1
		ADD R0, R0, #1
		NOT R6, R0
		ADD R6, R6, #1
		ADD R6, R6, R1
		BRzp CHANGE
		ADD R6, R6, #0
		RET


;SWAPMEM subroutine:
;address one is in R0, address two in R1
;if mem[R0]=A and mem[R1]=B, then after subroutine call
;   mem[R0]=B and mem[R1]=A
SWAPMEM
		ST R2, SAVE_R2
		ST R4, SAVE_R4
		ST R0, SAVE_R0
		ST R1, SAVE_R1
		LDI R2, SAVE_R0
		ST R2, SAVE_RR2
		LD R4, SAVE_R0				;2&4
		LDR R0, R1, #0
		STR R0, R4, #0
		LD R4, SAVE_R1		
		ADD R1, R2, #0
		STR R1, R4, #0
		LD R2, SAVE_R2
		LD R4, SAVE_R4
		RET

NUM_ADDR    .FILL x4FFF
CHAR_ADDR   .FILL x5000
SAVE_R0		.BLKW #1
SAVE_R1		.BLKW #1
SAVE_R7		.BLKW #1
SAVE_R2		.BLKW #1
SAVE_R4		.BLKW #1
SAVE_RR2	.BLKW #1
SSAVE_R0	.BLKW #1
SSAVE_R1	.BLKW #1
NEW_CHAR	.FILL x000A
.END
