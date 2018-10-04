;Introduction: This program runs five kinds of calculation:+,-,*,/,^ and store and output the answer in hexadecimal numbers.
;For each input which detected as numbers, the programme simply push the number to the stack. And for each character detected, the program
;first pop two numbers from the stack and then apply calculation on them, then push the result into stack again.
;IN this programme, I use several subroutine:ADD MINUS MULTIPLY DIVIDE EVALUATION AND PRINT_HEX. By using these subroutine, my programme looks more tidy and easy to debug.
;The PRINT_HEX subroutine I used is my lab1 answer. And I make a little change to it in order to connect it with this programme.

;R1 as a temporary register to load Ascii code of different characters and numbers.

.ORIG x3000
	
;your code goes here
			
GETCHAR		AND R5, R5, #0				;Initialize
			GETC						;Get input
			OUT							;Echo input to the screen
			JSR EVALUATE				;Go to EVALUATE subroutine
RETURN		AND R1, R1, #0				;Initialize R1
			ADD R1, R1, #1				;R1 work as a counter which helps to determine which subroutine need to be applied
			ADD R2, R2, #-1				;Decrement R2 to know whether the input is a character or number or invalid input.
			BRz	VALIDCHAR				;go to VALIDCHAR
			ADD R1, R1, #1				;Increment R1
			ADD R2, R2, #-1				;Decrement R2
			BRz VALIDCHAR
			ADD R1, R1, #1				;Increment R1
			ADD R2, R2, #-1				;Decrement R2
			BRz VALIDCHAR
			ADD R1, R1, #1				;Increment R1
			ADD R2, R2, #-1				;Decrement R2
			BRz VALIDCHAR
			ADD R1, R1, #1				;Increment R1
			ADD R2, R2, #-1				;Decrement R2
			BRz VALIDCHAR
			ADD R0, R0, #-15			;Decrease x30 for input numbers since Ascii code is different from exact value
			ADD R0, R0, #-15			;
			ADD R0, R0, #-15			;
			ADD R0, R0, #-3				;
			ST R0, Savee_R0				
			ADD R2, R2, #-1				;Decrement R2
			BRz VALIDNUM		
			ADD R2, R2, #-1				;Decrement R2
			BRz INVALID	
			ADD R2, R2, #-1				;Decrement R2
			BRz GETCHAR
			ADD R2, R2, #-1				;Decrement R2
			BRz SEMICOLON
			
VALIDNUM	JSR PUSH					;Push number to the stack
			ADD R5, R5, #0				;determine whether the PUSH succeed
			BRp INVALID
			BRnzp GETCHAR				;get new input

VALIDCHAR	JSR POP						;POP first number from stack
			ADD R3, R0, #0				;store it to R3
			ADD R5, R5, #-1				;check if POP succeed
			BRz INVALID
			JSR POP						;POP the second number from stack
			ADD R5, R5, #-1				;check if POP succeed
			BRz INVALID		
			ADD R4, R0, #0				;store it to R4
			ADD R1, R1, #-1				;Decrement R1 to check the type of operator
			BRz DIVIDE
			ADD R1, R1, #-1				;Decrement R1 to check the type of operator
			BRz SUBSTRACT
			ADD R1, R1, #-1				;Decrement R1 to check the type of operator
			BRz ADDDD
			ADD R1, R1, #-1				;Decrement R1 to check the type of operator
			BRz MULTIPLY
			ADD R1, R1, #-1				;Decrement R1 to check the type of operator
			BRz EXPONENTIAL

DIVIDE		JSR DIV						;Go to DIV subroutine to apply calculation
			BRnzp RESTORE				;Store the result

MULTIPLY	JSR MUL						;Go to MUL subroutine to apply calculation
			BRnzp RESTORE				;store the result

ADDDD		JSR PLUS					;Go to PLUS subroutine to apply calculation
			BRnzp RESTORE				;store the result

SUBSTRACT	JSR MIN						;Go to MIN subroutine to apply calculation
			BRnzp RESTORE				;store the result

EXPONENTIAL	BRnzp EXP					;Go to apply exponential calculation
PPPPP		ADD R5, R5, #0				;check if the case 0^0 happens
			BRp INVALID
			ADD R0, R0, #0
			BRnzp RESTORE				;store the result

RESTORE		JSR PUSH					;PUSH the result to the stack
			BRnzp GETCHAR				;Get new input

SEMICOLON	JSR POP						;POP to check whether at least one number is left in stack
			ADD R5, R5, #0
			BRp INVALID		
			ST R0, SAVE_R0				;store R0
			JSR POP						;POP the second number
			LD R0, SAVE_R0				;load R0
			ADD R5, R5, #0				;if the second POP fails, only one number is left in the stack, which means the input is correct
			BRp TRUEE					;go to final step

INVALID		LEA R0, FAIL_PRINT			;print the string "Invalid Expression"
			PUTS						;Output the string
			BRnzp HALTT

TRUEE		JSR PRINT_HEX				;Go to PRINT_HEX subroutine
			LD R5, SAVE_R0				;Load the content to R5
			BRnzp HALTT

HALTT		TRAP x25					;End the programme

;
SAVE_RR0	.BLKW #1
SAVE_RR7	.BLKW #1
SPACE_CHAR	.FILL x0020
SEMI_CHAR	.FILL x003B
SAVE_RRR0	.BLKW #1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R3- value to print in hexadecimal
PRINT_HEX	
			LD R3, SAVE_R0
			AND R0, R0, #0
			AND R1, R1, #0
			ADD R1, R1, #4			;COUNTER OF EACH HEXADECIMAL DIGIT
			AND R2, R2, #0			;REGISTER OF HEXADECIMAL OUTPUT
			AND R6, R6, #0			;Counter of printed digits
			ADD R6, R6, #-5

NEWDIGITS	ADD R6, R6, #1
			BRzp HALTTT
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
			ST R7, SAVE_R7777
			ADD R0, R0, #0
			OUT
			LD R7, SAVE_R7777
			BRnzp NEWDIGITS

HALTTT		RET				
 ; stop the computer

 ; program data section starts here

 ; stop the computer


 ; program data section starts here

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R0 - character input from keyboard
;R6 - current numerical output
;
;
EVALUATE
			
;your code goes here
			ST R7, Savee_R7				;Store the address
			ST R0, Savee_R0				;Store the content
			AND R2, R2, #0				;Initialize R2
			LD R1, SEMI_CHAR			;load R1 as semicolon
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;check if input is semicolon
			BRz SEE
			LD R1, SPACE_CHAR			;load R1 as space
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;check if input is space
			BRz SPP
			LD R1, MULCHAR				;load R1 as mulpiple sign
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;check if input is valid
			BRn INVALIDC
			ADD R1, R1, #0				;CHeck if input is multiple sign
			BRz TTT
			LD R1, NINE_CHAR			;load '9' to R1
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;check if input is valid
			BRp CHECK
			LD R1, ZERO_CHAR			;load '0' to R1
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;check if input is a number
			BRzp NUMMM
			LD R1, SLASH_CHAR			;load '/' to R1
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;check if input is slash
			BRz DDD
			LD R1, MINUS_CHAR			;load '-' to R1
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;check if input is minus
			BRz MMM
			LD R1, PLUS_CHAR			;load '+' to R1
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;check if input is '+'
			BRz PPP
			ADD R1, R1, #0				;all other inputs are invalid
			BRnzp INVALID
			
CHECK		LD R1, EXPCHAR				;load R1 as '^'
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0				;Check if R1 is '^'
			BRz EEE
			
DDD			ADD R2, R2, #1				;increment R2 as a counter
			BRnzp RRR
MMM			ADD R2, R2, #2				;increment R2 as a counter
			BRnzp RRR
PPP			ADD R2, R2, #3				;increment R2 as a counter
			BRnzp RRR
TTT			ADD R2, R2, #4				;increment R2 as a counter
			BRnzp RRR
EEE			ADD R2, R2, #5				;increment R2 as a counter
			BRnzp RRR
NUMMM		ADD R2, R2, #6				;increment R2 as a counter
			BRnzp RRR
INVALIDC	ADD R2, R2, #7				;increment R2 as a counter
			BRnzp RRR
SPP			ADD R2, R2, #8				;increment R2 as a counter
			BRnzp RRR
SEE			ADD R2, R2, #9				;increment R2 as a counter
RRR			LD R7, Savee_R7
			LD R0, Savee_R0
			RET							;return to main programme

Savee_R0	.BLKW #1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
PLUS	
;your code goes here
			ST R7, Savee_R7
			ADD R0, R3, R4				;Add two inputs
			LD R7, Savee_R7
			RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MIN	
;your code goes here
		ST R7, Savee_R7
		NOT R3, R3
		ADD R3, R3, #1
		ADD R0, R4, R3					;Minus two inputs
		LD R7, Savee_R7
		RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MUL	
;your code goes here
		ST R7, Savee_R7
		AND R6, R6, #0					;initialize
		AND R0, R0, #0					;initialize
		ADD R4, R4, #0
		BRz ZEROO
		ADD R3, R3, #0
		BRz ZEROO
		ADD R4, R4, #0
		BRn	NEGATT
ADDD	ADD R0, R3, R0					;add R3 to the sum
		ADD R4, R4, #-1					;R4 as a counter
		BRp ADDD						;check counter's value
		ADD R6, R6, #0
		BRz RRET
		ADD R6, R6, #0					;make outputs back to negative numbers
		BRp NEGT
ZEROO	AND R0, R0, #0
		BRnzp RRET
NEGATT	NOT R4, R4						;the case R4 is negative
		ADD R4, R4, #1
		ADD R6, R6, #1
		BRnzp ADDD
NEGT	NOT R0, R0						;Output negative numbers
		ADD R0, R0, #1
RRET	LD R7, Savee_R7
		RET		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
DIV	
;your code goes here
		ST R7, Savee_R7
		AND R0, R0, #0					;Initialize R0
		AND R6, R6, #0					;Initialize R6
		NOT R3, R3
		ADD R3, R3, #1
DIVID	ADD R6, R6, #1					;R6 as a counter
		ADD R4, R4, R3					;minus R3 from R4
		BRzp DIVID
OUTTT	ADD R6, R6, #-1
		ST R6, SAVE_R6
		LD R0, SAVE_R6					;load R6 to R0 as output
		LD R7, Savee_R7
		RET								;return to the main programme

SAVE_R66	.BLKW #1
SAVE_R6		.BLKW #1
MULCHAR		.FILL x002A
EXPCHAR		.FILL x005E
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
EXP
;your code goes here
		ST R7, Savee_R7
		AND R2, R2, #0					;initialize
		AND R5, R5, #0					;initialize
		AND R1, R1, #0					;initialize
		AND R0, R0, #0					;initialize
		ADD R1, R4, #0					;load R4 to R1
		ADD R4, R4, #0					;chech whether R4 is zero
		BRz RZERO
		ADD R3, R3, #0					;check whether R3 is zero
		BRz OUTONE
		ADD R2, R4, #0					;load R4 to R2
		ADD R3, R3, #-1
		ST R4, SAVE_R44
NT		ST R3, SAVE_R33
		ADD R4, R1, #0					;load counter to R4
		ADD R3, R2, #0					;load the previous result to R3
		ST R7, SAVE_RR7					;store R7 since it would go to another subroutine
		JSR MUL							;go to MUL subroutine to calculate
		LD R7, SAVE_RR7					;load R7 since back from another subroutine
		ADD R2, R0, #0					;load sum to R2
		ADD R4, R1, #0					;load back value to R4
		LD R3, SAVE_R33					;load back R3 value as a counter
		ADD R3, R3, #-1					;check whether exponential complete
		BRp NT
		ADD R3, R3, #0					;output R0
		BRnzp OTT		
RZERO	ADD R3, R3, #0					;if 0^0 happens, it's invalid
		BRz INVAL
		ADD R3, R3, #0					;other case output is 0
		BRp OUTZ
INVAL	AND R0, R0, #0
		ADD R5, R5, #1					;R5 as a signal register to check whether the EXP result is invalid
		BRnzp OUTTTT
OUTONE	ADD R0, R0, #1					;output #1
		BRnzp OUTTTT
OUTZ	AND R0, R0, #0					;output #0
		BRnzp OUTTTT
OTT		ADD R0, R2, #0					;load result from R2 to R0
		BRnzp OUTTTT
OUTTTT	LD R7, Savee_R7					;Load R7 value back
		BRnzp PPPPP						;go back to main programme

SAVE_R77	.BLKW #1
SAVE_R44	.BLKW #1
SAVE_R33	.BLKW #1
SAVE_R0		.BLKW #1
ZERO_CHAR	.FILL x0030
NINE_CHAR	.FILL x0039
SLASH_CHAR	.FILL x002F
FAIL_PRINT	.STRINGZ "Invalid Expression"
STACK_TOPP	.FILL x4000
NUMM		.FILL x0060
SAVE_R7777	.BLKW #1
MINUS_CHAR	.FILL x002D
PLUS_CHAR	.FILL x002B

;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3			;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET

PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3			;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET
Savee_R7	.BLKW #1
POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;
SAVE_R7		.BLKW #1
.END
