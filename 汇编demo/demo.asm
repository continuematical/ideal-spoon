;对于buf存储区内的数，如果大于0，送入buf1，否则送入buf2
DATA SEGMENT
    BUF dw -5,2,32767,-32768,-1,15,-4,-9,200,0,300
    N = ($-BUF)/2
    BUF1 dw N dup(?)
    BUF2 dw N dup(?)
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    lea bx,BUF
    lea si,BUF1
    lea di,BUF2
    MOV cx,N

LOPA:
    MOV ax,[bx]
    cmp ax,0
    JGE L1
    MOV [di],ax
    add di,2
    JMP NEXT
L1:
    MOV [si],ax
    add si,2
NEXT:
    add bx,2
    DEC	cx
    JNE LOPA

    MOV bx,BUF1
    MOV dl,[bx]
    MOV ah,2
    INT 21H

    MOV AH, 4CH
    INT 21H
CODES ENDS
END START