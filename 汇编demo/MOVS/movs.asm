;串操作指令
DATA SEGMENT
    str1 db 'abcdefghijklm'
    count equ $-str1
    str2 db count dup(0)
DATA ENDS
STACKS SEGMENT
    db 200 dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    MOV es, ax
    lea si, str1
    lea di, str2
    MOV cx, count
    cld ;将DF清零
    rep movsb

    ;显示
    lea dx, str2
    mov ah, 9
    INT 21H
    
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START