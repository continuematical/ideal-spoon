DATA SEGMENT
    BUF db '5792'
    BCD db 4 dup(?)
DATA ENDS

STACKS SEGMENT
    DB 200 dup(?)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    MOV cx,4
    lea si,BUF
    lea di,BCD+3

NEXT:
    MOV al,[si]
    and al,0fH
    mov [di],al
    inc si
    dec di
    dec cx
    LOOP NEXT
    
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START