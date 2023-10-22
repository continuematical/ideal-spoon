DATA SEGMENT
    a db 10011010B
    b db '(A)=$'
    c db 'B',0DH,0AH,'$'
DATA ENDS

STACKS SEGMENT
    db 200 dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
    ;输出字符串b
    lea dx,b
    mov ah,9
    int 21H
    ;将a中的无符号数扩展为16位数
    mov bl,a
    mov bh,0
    mov cx,7 ;计数器赋值
L:  bt bx,cx
    JC P
    mov dl,30H
    JMP Q

P:  mov dl,31H
    ;显示分解出的一位
Q:  mov ah,2
    int 21H
    ;修改位号，如位号为负，结束循环
    dec cx
    JGE L
    ;输出结束符B结束循环
    lea dx,c
    mov ah,2
    int 21H
    
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START