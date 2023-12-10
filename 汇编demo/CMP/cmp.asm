DATA SEGMENT
    str1 db 80
         db 0
         db 80 dup(0)
    str2 db 'wan1.asm'
    count equ $-str2
DATA ENDS

STACKS SEGMENT
    db 200 dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
    mov ES, ax
    ;输入一串字符
    lea dx, str1
    mov ah, 10
    INT 21H
    ;比较
    mov al, str1+1
    cmp al, count
    JNE EXIT
    lea si, str1+2;
    lea di,str2
    mov cx, count
    REPZ CMPSB
    JNE EXIT
    mov bx, 0
    JMP RETU
EXIT:
    mov bx, -1
RETU:
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START