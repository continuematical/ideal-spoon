;循环结构
DATA SEGMENT
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    xor ax,ax ;ax置零操作
    mov cx,100

NEXT:
    add ax,cx
    LOOP NEXT

    mov dx,ax
    mov ah,2
    int 21H

    MOV AH, 4CH
    INT 21H
CODES ENDS
END START