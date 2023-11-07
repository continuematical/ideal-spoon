;二进制转为十六进制

DATA SEGMENT
    NUM db 00111001B
    BUF db 0AH,0DH,'(NUM)='
    BUF0 db 4 dup(?)
DATA ENDS

STACKS SEGMENT
    db 200 dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    lea di,BUF0
    ;获取NUM前四位的ASCII码值并存入BUF0
    mov al,NUM
    mov cl,4
    shr al,cl
    or al,30H
    mov [di],al
    ;获取NUM后四位的ASCII码值并存入BUF0
    inc di
    mov al,NUM
    and al,0FH
    or al,30H
    mov [di],al
    inc di
    mov byte ptr [di],'H'
    inc di
    mov byte ptr [di],'$'
    ;显示
    lea dx,BUF
    mov ah,9
    int 21H
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START