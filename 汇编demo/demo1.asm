DATA SEGMENT
    BUF db 'MOV AX,DATA',0DH,0AH
        db 'MOV DX,AX',0DH,0AH
        db 'MOV AX,0',0DH,0AH
        db 'MOV BX,2',0DH,0AH,'LEA SI,MMOV',0DH,0AH
        db 'ADD AX,BX',0DH,0AH,'MOV MOMOV[SI],AX',0DH,0AH,1AH,1AH
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX

    xor ax,ax
    mov si,offset BUF
LOPA:
    CMP BYTE PTR [si], 1AH
    JE EXIT
    CMP BYTE PTR [si],'M'
    JNE NEXT
    CMP BYTE PTR [si+1],'O'
    JNE NEXT
    CMP BYTE PTR [si+2],'V'
    JNE NEXT
    INC ax
    add si,2
NEXT:
    INC si
    JMP LOPA
EXIT:    
    mov dl,al
    mov ah,2
    INT 21H
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START