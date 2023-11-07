;选出最大的数，并用二进制显示

DATA SEGMENT
    BUF db 11H,12H,13H,14H,15H
    M dw 5
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
;找到最大的值
    lea si,BUF
    mov cx,1
    mov bx,[si]
LOPA:
    inc si
    CMP bx,[si]
    JA LOPB
    mov bx,[si]
LOPB:
    inc cx
    CMP cx,M
    JBE LOPA


;转化为二进制
    mov cx,8
NEXT:
    rol bx,1
    mov al,bl
    and al,01H
    add al,30H
    ;显示输出
    mov dl,al
    mov ah,2
    int 21H
    dec cx
    JNE NEXT
    ;输出B
    mov dl,'B'
    mov ah,2
    int 21H

    MOV AH, 4CH
    INT 21H
CODES ENDS
END START