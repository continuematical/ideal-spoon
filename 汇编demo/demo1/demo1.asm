;数组求和
DATA SEGMENT
    ARRAY DW 1,2,3,4
    SUM DW ?
DATA ENDS

STACKS SEGMENT
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    MOV CX,4
    MOV AX,0
NEXT: 
    ADD	AX,	[BX]
    INC	BX
LOOP NEXT
    
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START