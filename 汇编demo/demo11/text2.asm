;输入一个字符串，将其转化为二进制数据，以十六进制的形式显示出来
DATA SEGMENT
    BUF db 6
        db ?
        db 6 dup(0) 
    RES db 6 dup(0);结果存放位置
    C10 dw 10
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
    lea di, RES
    ;输入字符串
    lea dx,BUF
    mov ah,10
    int 21H
    ;cx为字符串长度
    mov cl,BUF+1
    mov ch,0
    ;真值存储到ax
    xor ax,ax
    lea si, BUF+2

BEGIN:
    mul C10
    ;dl读取每一个字符
    mov dl,[si]
    ;将字符串转化为真值
    and dl,0FH
    add al,dl
    adc ah,0
    inc si
    dec cx
    CMP cx,0
    JNE BEGIN

    ;转化为十六进制
    mov bx,ax
    mov ch,4;循环次数
NEXT:
    mov cl,4
    rol bx,cl;循环左移四位
    mov al,bl
    and al,0FH;取出四位数
    add al,30H;转化为ASCII码值
    CMP al,'9'
    JBE PRINT
    add al,07H;如果大于9，转化为A-F

;打印输出
PRINT:
    ;显示输出
    mov dl,al
    mov ah,2
    int 21H
    dec ch
    JNE NEXT

    ;输出'H'
    mov dl,'H'
    mov ah,2
    int 21H
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START