;删除第五行字符串的数字
DATA SEGMENT
    BUF db '1234567',0AH,0DH
        db 'abcdefg',0AH,0DH
        db 'wnejdkn',0AH,0DH
        db 'dnjwkxe',0AH,0DH
        db '387hrbr',0AH,0DH
        db 'dnwexhu',0H
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    lea bx,WORD PTR BUF
    mov cx,5
LOPA1:
    CMP [bx],0DH
    INC	bx
    JNE LOPA1
    dec cx
    JNE LOPA1

    mov dl,[bx]
    mov ah,2
    INT 21H
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START