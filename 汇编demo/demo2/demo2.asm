data segment
    string db 'abcdefg $'
data ends

code segment ;代码段定义开始
    assume cs:code 
start:  
    mov ax,data
    mov DS,ax

    lea dx,string
    mov ah,9
    int 21h

    mov ah,4ch  ;返回
    int 21h

code ends  ;代码段结束  
    end start   ;整个程序结束
