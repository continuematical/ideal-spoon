DATA SEGMENT
    ;缓冲区
    ;第一个数为缓冲区的大小，第二个字节存放实际字节的个数
    BUF db 50
        db 0
        db 50 dup(0)
        CRLF db 0DH,0AH,'$'
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
    ;键盘上输入一行字符串，十号调用
    lea dx,BUF
    mov ah,10
    int 21H
    ;输入回车换行
    lea dx,CRLF
    mov ah,9
    int 21H
    ;在输入的串尾补上结束符
    mov bl,BUF+1
    mov bh,0
    mov BYTE PTR BUF+2[bx], '$'
    ;输出前面输入的字符串
    lea dx,BUF+2
    mov ah,9
    int 21H
    ;结束
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START