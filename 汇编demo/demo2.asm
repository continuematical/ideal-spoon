;输出BUF字符串，大小写转换
DATA SEGMENT
    BUF db 'add ax,bx',0DH,0AH
        db 'sub cx,10',0DH,0AH
        db 'mov dx,1234H',0DH,0AH,'$'
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    lea bx,BUF
LOPA:
    mov dl,[bx]
    cmp dl,'$'
    JE EXIT
    cmp dl,'a'
    JB N
    cmp dl,'z'
    JA N
    sub dl,20H
N:
    mov ah,2
    INT 21H
    INC	bx
    JMP LOPA
EXIT:
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START