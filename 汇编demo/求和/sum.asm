DATA SEGMENT
    BUF db 11H, 12H, 13H, 14H, 15H
        db 21H, 22H, 23H, 24H, 25H
        db 31H, 32H, 33H, 34H, 35H
        db 41H, 42H, 43H, 44H, 45H
    M = 4
    N = 5
    BUFS dw M dup(?)
DATA ENDS

STACKS SEGMENT
    db 200 dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
    ;为循环设置初值
    lea si, BUF
    lea di, BUFS
    MOV bx, 1
LOP1:
    MOV dx, 0
    MOV cx, 1
LOP2:
    MOV al, [si]
    MOV ah, 0
    ADD dx, ax
    inc si
    inc cx
    CMP	cx, N
    JBE LOP2
    MOV [di], dx
    ADD di, 2
    inc bx
    CMP bx, M
    JBE LOP1
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START