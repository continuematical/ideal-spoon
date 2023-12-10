DATA SEGMENT
    BUFA db 15 dup(0)
    BUFB db 400000, 4096, 18, 0F1234567H
    N = ($-BUFB)/4
DATA ENDS

STACKS SEGMENT
    db 200 dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
    MOV cx, N   ;待转换的二进制个数
    lea di, BUFB
LOPA:
    ;进行二进制到十进制的转换
    MOV eax, di
    MOV ebx, 10
    lea si, BUFA
    CALL RADIX
    ;显示转换后的十进制数
    MOV byte ptr [si], 0DH
    MOV byte ptr [si+1], 0AH
    MOV byte ptr [si+2], '$'
    lea dx, BUFA
    MOV ah, 9
    INT 21H
    ;进行二进制到十六进制的转换
    MOV eax, [di]
    MOV ebx, 16
    lea si, BUFA
    CALL RADIX
    ;显示转换后的十六进制数
    MOV byte ptr [si], 'H'
    MOV byte ptr [si+1], 0AH
    MOV byte ptr [si+2], 0DH
    MOV byte ptr [si+3],'$'
    lea dx, BUFA
    MOV ah, 9
    INT 21H

    add di, 4   ;指向下一个待转换的数
    LOOP LOPA

    MOV AH, 4CH
    INT 21H

;编写基数转换子程序
;ebx 需要转换进制的基数
RADIX PROC 
    push cx
    push edx
    xor cx,cx
LOP1:
    xor edx, edx
    div ebx
    push dx
    inc cx
    or eax, eax
    JNZ LOP1

LOP2:
    pop ax
    CMP al, 10
    JB L1
    add al, 7
L1:
    and al, 30H
    MOV [si], al
    inc si
    LOOP LOP2

    pop edx
    pop cx
RADIX ENDP
CODES ENDS
END START