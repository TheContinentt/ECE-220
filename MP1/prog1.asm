;
; The code given to you here implements the histogram calculation that 
; we developed in class.  In programming studio, we will add code that
; prints a number in hexadecimal to the monitor.
;
; Your assignment for this program is to combine these two pieces of 
; code to print the histogram to the monitor.
;
; If you finish your program, 
;    ** commit a working version to your repository  **
;    ** (and make a note of the repository version)! **


	.ORIG	x3000		; starting address is x3000


;
; Count the occurrences of each letter (A to Z) in an ASCII string 
; terminated by a NUL character.  Lower case and upper case should 
; be counted together, and a count also kept of all non-alphabetic 
; characters (not counting the terminal NUL).
;
; The string starts at x4000.
;
; The resulting histogram (which will NOT be initialized in advance) 
; should be stored starting at x3F00, with the non-alphabetic count 
; at x3F00, and the count for each letter in x3F01 (A) through x3F1A (Z).
;
; table of register use in this part of the code
;    R0 holds a pointer to the histogram (x3F00)
;    R1 holds a pointer to the current position in the string
;       and as the loop count during histogram initialization
;    R2 holds the current character being counted
;       and is also used to point to the histogram entry
;    R3 holds the additive inverse of ASCII '@' (xFFC0)
;    R4 holds the difference between ASCII '@' and 'Z' (xFFE6)
;    R5 holds the difference between ASCII '@' and '`' (xFFE0)
;    R6 is used as a temporary register
;

	LD R0,HIST_ADDR      	; point R0 to the start of the histogram
	
	; fill the histogram with zeroes 
	AND R6,R6,#0		; put a zero into R6
	LD R1,NUM_BINS		; initialize loop count to 27
	ADD R2,R0,#0		; copy start of histogram into R2

	; loop to fill histogram starts here
HFLOOP	STR R6,R2,#0		; write a zero into histogram
	ADD R2,R2,#1		; point to next histogram entry
	ADD R1,R1,#-1		; decrement loop count
	BRp HFLOOP		; continue until loop count reaches zero

	; initialize R1, R3, R4, and R5 from memory
	LD R3,NEG_AT		; set R3 to additive inverse of ASCII '@'
	LD R4,AT_MIN_Z		; set R4 to difference between ASCII '@' and 'Z'
	LD R5,AT_MIN_BQ		; set R5 to difference between ASCII '@' and '`'
	LD R1,STR_START		; point R1 to start of string

	; the counting loop starts here
COUNTLOOP
	LDR R2,R1,#0		; read the next character from the string
	BRz PRINT_HIST		; found the end of the string

	ADD R2,R2,R3		; subtract '@' from the character
	BRp AT_LEAST_A		; branch if > '@', i.e., >= 'A'
NON_ALPHA
	LDR R6,R0,#0		; load the non-alpha count
	ADD R6,R6,#1		; add one to it
	STR R6,R0,#0		; store the new non-alpha count
	BRnzp GET_NEXT		; branch to end of conditional structure
AT_LEAST_A
	ADD R6,R2,R4		; compare with 'Z'
	BRp MORE_THAN_Z         ; branch if > 'Z'

; note that we no longer need the current character
; so we can reuse R2 for the pointer to the correct
; histogram entry for incrementing
ALPHA	ADD R2,R2,R0		; point to correct histogram entry
	LDR R6,R2,#0		; load the count
	ADD R6,R6,#1		; add one to it
	STR R6,R2,#0		; store the new count
	BRnzp GET_NEXT		; branch to end of conditional structure

; subtracting as below yields the original character minus '`'
MORE_THAN_Z
	ADD R2,R2,R5		; subtract '`' - '@' from the character
	BRnz NON_ALPHA		; if <= '`', i.e., < 'a', go increment non-alpha
	ADD R6,R2,R4		; compare with 'z'
	BRnz ALPHA		; if <= 'z', go increment alpha count
	BRnzp NON_ALPHA		; otherwise, go increment non-alpha

GET_NEXT
	ADD R1,R1,#1		; point to next character in string
	BRnzp COUNTLOOP		; go to start of counting loop



PRINT_HIST
;Introduction:
;in this print program, I write three loops. The first is bits loop, the second is digits loop, and the last one is line loop.
;First I convert 16-bit binary number to 4-bit hex number, and this is the bit loop. Then print the 4 bits as a digit. In the 
;end the program goes to the new line. For convenience, I use some character data such as space, line feed, and '@'. ANd use 
;LDI, LD and ST to change them if necessary.

; you will need to insert your code to print the histogram here

			AND R4, R4, #0			;initialize R4
			LD R4, NUM_BINS 		;R4 as a line counter
			AND R0, R0, #0			;initialize R0
			AND R5, R5, #0			;initialize R5
			AND R3, R3, #0			;initialize R3
			LD R5, CHARSTART		;load R5 as character register
			
NEWLINE		LDI R3, HIST_ADDR		;load histogram results into R3
			ADD R4, R4, #-1			;decrement R4
			BRn HALTT				;end the program
			LD R0, CHARSTART		;load current character ASCII code to R0
			OUT						;print
			LD R0, SPACE			;load ' ' ASCII code to R0
			OUT						;print
			AND R0, R0, #0			;initialize R0
			AND R1, R1, #0			;initialize R1
			ADD R1, R1, #4			;COUNTER OF EACH HEXADECIMAL DIGIT
			AND R2, R2, #0			;REGISTER OF HEXADECIMAL OUTPUT
			AND R6, R6, #0			;initialize R6
			ADD R6, R6, #-5			;Counter of printed digits

NEWDIGITS	ADD R6, R6, #1			;increment R6
			BRzp NEWLINEE			;go to the next line
			AND R2, R2, #0			;initialize R2
			AND R1, R1, #0			;initialize R1
			ADD R1, R1, #4			;R1 as bits counter

NEWBITS		ADD R1, R1, #-1			;decrement R1
			BRnz PRINTOUT			;print the digit
			ADD R3, R3, #0			
			BRzp PRINTR				;determine the most significant bits of R3
			ADD R2, R2, #1			;add the most siginificant bit of R3 to R2
			BRnzp LEFTSHIFTR

PRINTR		ADD R2, R2, #0			;add the most siginificant bit of R3 to R2

LEFTSHIFTR	ADD R2, R2, R2			;left shift R2
			ADD R3, R3, R3			;left shift R3
			BRnzp NEWBITS			;INCREMENT DIGIT COUNTER
			
PRINTOUT	ADD R3, R3, #0
			BRzp POSITIVE			;determine the most siginificant to be 1 or 0
			ADD R2, R2, #1			;add the most siginificant bit to R2
			BRnzp OUTPUTR

POSITIVE	ADD R2, R2, #0

OUTPUTR		ADD R3, R3, R3			;left shift the last bit of one of the digits of R3
			ADD R2, R2, #-9
			BRnz ASCII				;determine whether R2 is greater to 9 and branch
			ADD R2, R2, #15
			ADD R2, R2, #15
			ADD R2, R2, #15
			ADD R0, R2, #15
			ADD R0, R0, #4			;add to match the ASCII code of the character
			BRnzp OUTPUT

ASCII		ADD R2, R2, #15
			ADD R2, R2, #15
			ADD R2, R2, #11
			ADD R2, R2, #9
			ADD R0, R2, #7			;add to match the ASCII code of the character
			
OUTPUT		ADD R0, R0, #0
			OUT						;print the 4-bit hexadecimal number
			BRnzp NEWDIGITS
NEWLINEE
			ADD R5, R5, x1			
			ST R5, CHARSTART		;change to the next character address
			LD R3, HIST_ADDR		;store the address of current histogram
			ADD R3, R3, #1			;renew the address of histogram
			ST R3, HIST_ADDR		;store the new adress of histogram
			LD R0, NEXTLINE
			OUT						;print the nextline character to go to the new line
			BRnzp NEWLINE
HALTT		
			TRAP x25				;Halt the program


; the data needed by the program
NUM_BINS	.FILL #27	; 27 loop iterations
NEG_AT		.FILL xFFC0	; the additive inverse of ASCII '@'
AT_MIN_Z	.FILL xFFE6	; the difference between ASCII '@' and 'Z'
AT_MIN_BQ	.FILL xFFE0	; the difference between ASCII '@' and '`'
HIST_ADDR	.FILL x3F00 ; histogram starting address
STR_START	.FILL x4000	; string starting address
CHARSTART	.FILL x40   ; character '@'
CHARZERO		.FILL x30	; character '0'
SPACE		.FILL x20	; space character ' '
NEXTLINE	.FILL x0A	; Line Feed character 'LF'

; for testing, you can use the lines below to include the string in this
; program...
; STR_START	.FILL STRING	; string starting address
; STRING		.STRINGZ "This is a test of the counting frequency code.  AbCd...WxYz."



	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END
