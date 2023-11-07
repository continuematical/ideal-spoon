;从键盘中输入一个0-9的数，求出它的立方值

DATA SEGMENT
    INPUT db 'please input x(0-9):$'
    TAB db '0  ','1  ','8  ','27 ','64 ','125','216','343','512','729','$'
    XXX dw ?
    ERROR db 0AH,0DH,'input error, try again',0AH,0DH,'$'
DATA ENDS

STACKS SEGMENT
    db 200 dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
NEXT:
    ;显示INPUT
    mov dx, offset INPUT
    mov ah,9
    int 21H
    ;输入一个值x的ASCII码值
    ;这里是字符串输入
    mov ah,1
    int 21H
    ;如果输入数值不是在0-9之间，转ERROR
    CMP	al,'0'
    JB ERR
    CMP al,'9'
    JA ERR
    ;将ASCII值转化为真值
    and al,0FH
    add al,al
    add al,al
    mov bl,al
    mov bh,0
    mov ax,TAB[bx]
    mov XXX,ax
    ;显示
    mov dx, ax
    mov ah, 9
    int 21H
    MOV AH, 4CH
    INT 21H
ERR:
    mov dx, offset ERROR
    mov ah,9
    int 21H
    JMP NEXT
CODES ENDS

END START