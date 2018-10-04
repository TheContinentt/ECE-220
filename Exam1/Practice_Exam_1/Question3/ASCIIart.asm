;Load ASCII art character, stored at memory address x5000 (IMAGEADDR)
;The first two numbers are the width (number of columns) and the height (number of rows) in the ASCII art image
;The memory addresses starting at x5002 are ASCII characters. The first N characters are the first row of the image, the second N characters are the second row of the image, etc.
;each row should end with a newline character

.ORIG x3000
;YOUR CODE GOES HERE
		AND R0, R0, #0
		AND R2, R2, #0
		AND R5, R5, #0
		AND R6, R6, #0
		AND R4, R4, #0
		AND R1, R1, #0
		LD R4, IMAGEADDR
		LDR R1, R4, #0
		LDR R5, R4, #0			;R5 is the number of columns
		BRnz TRAPP
		ADD R4, R4, #1
		LDR R6, R4, #0			;R6 is the number of lines
		BRnz TRAPP
COLUMNLOOP
		ADD R6, R6, #-1
		BRn TRAPP
LINELOOP
		ADD R5, R5, #-1
		BRn NEXT_LINE
		ADD R4, R4, #1
		LDR R0, R4, #0
		OUT
		BRnzp LINELOOP
NEXT_LINE	
		LD R0, NEWCHAR
		OUT
		ADD R5, R1, #0
		BRnzp COLUMNLOOP
TRAPP
		TRAP x25

IMAGEADDR 	.FILL x5000			; address of image
NEWCHAR		.FILL x000D			; linefeed character
.END
