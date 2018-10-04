.ORIG x3000
; Write code to read in characters and echo them
; till a newline character is entered.
			AND R0, R0, #0
			AND R1, R1, #0
			AND R2, R2, #0
			AND R3, R3, #0
			AND R4, R4, #0
			AND R5, R5, #0
			AND R6, R6, #0
			AND R7, R7, #0


NEW_CHAR	LD R1, STARTB
			LD R2, CLOSEB
			LD R5, SPACECHAR
			LD R6, CHAR_RETURN
			NOT R1, R1
			ADD R1, R1, #1
			NOT R2, R2
			ADD R2, R2, #1
			NOT R5, R5
			ADD R5, R5, #1
			NOT R6, R6
			ADD R6, R6, #1


GETCHAR		IN
			ADD R4, R0, R6
			BRz DONE
			LDR R3, R0, #0
			ADD R4, R0, R1
			BRz PUSHH
			ADD R4, R0, R2
			BRz POPP
			ADD R4, R0, R5
			BRz GETCHAR


PUSHH		JSR PUSH
			ADD R5, R5, #0
			BRp DONE
			ADD R5, R5, #0
			BRz NEW_CHAR


POPP		JSR POP
			ADD R5, R5, #0
			BRp DONE
			ADD R5, R5, #0
			BRz NEW_CHAR
			
DONE		JSR IS_BALANCED
			ADD R5, R5, #0
			OUT
			BRnzp TRAPP

TRAPP		TRAp x25

			
			
 
SPACE   .FILL x0020
NEW_LINE        .FILL x000A
CHAR_RETURN     .FILL x000D
STARTB			.FILL x0028
CLOSEB			.FILL x0029
SPACECHAR		.FILL x0020
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;if ( push onto stack if ) pop from stack and check if popped value is (
;input - R0 holds the input
;output - R4 set to -1 if unbalanced. else not modified.


NEG_OPEN .FILL xFFD8
;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH
        ST R3, PUSH_SaveR3      ;save R3
        ST R4, PUSH_SaveR4      ;save R4
        AND R5, R5, #0          ;
        LD R3, STACK_END        ;
        LD R4, STACk_TOP        ;
        ADD R3, R3, #-1         ;
        NOT R3, R3              ;
        ADD R3, R3, #1          ;
        ADD R3, R3, R4          ;
        BRz OVERFLOW            ;stack is full
        STR R0, R4, #0          ;no overflow, store value in the stack
        ADD R4, R4, #-1         ;move top of the stack
        ST R4, STACK_TOP        ;store top of stack pointer
        BRnzp DONE_PUSH         ;
OVERFLOW
        ADD R5, R5, #1          ;
DONE_PUSH
        LD R3, PUSH_SaveR3      ;
        LD R4, PUSH_SaveR4      ;
        RET


PUSH_SaveR3     .BLKW #1        ;
PUSH_SaveR4     .BLKW #1        ;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP
        ST R3, POP_SaveR3       ;save R3
        ST R4, POP_SaveR4       ;save R3
        AND R5, R5, #0          ;clear R5
        LD R3, STACK_START      ;
        LD R4, STACK_TOP        ;
        NOT R3, R3              ;
        ADD R3, R3, #1          ;
        ADD R3, R3, R4          ;
        BRz UNDERFLOW           ;
        ADD R4, R4, #1          ;
        LDR R0, R4, #0          ;
        ST R4, STACK_TOP        ;
        BRnzp DONE_POP          ;
UNDERFLOW
        ADD R5, R5, #1          ;
DONE_POP
        LD R3, POP_SaveR3       ;
        LD R4, POP_SaveR4       ;
        RET


POP_SaveR3      .BLKW #1        ;
POP_SaveR4      .BLKW #1        ;
STACK_END       .FILL x3FF0     ;
STACK_START     .FILL x4000     ;
STACK_TOP       .FILL x4000     ;

;
IS_BALANCED
		ST R7, POP_SAVER7
		LDR R0, R3, #0
		JSR POP
		ADD R5, R5, #0
		BRp BALANCED

UNBALANCED
		ADD R5, R5, #-1

BALANCED
		ADD R5, R5, #0

DONE_CHECK
		LD R7, POP_SAVER7
		RET

POP_SAVER7      .BLKW #1  
.END

