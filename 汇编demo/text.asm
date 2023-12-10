DATA SEGMENT
    
DATA ENDS

STACKS SEGMENT
    db 10H dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AX, STACKS
    MOV SS, AX

    MOV BX, 0   ;BX存放运算结果
    ;输入N
    MOV AH, 1
    INT 21H
    ;转化为真值
    SUB	AL, 30H
    MOV AH, 0
    MOV SI, AX

    ;保护现场
    PUSH SI
    CALL Fun
    POP SI
    ;转化为ASCII码值
    ADD BX, 30H
    ;输出
    MOV DL, BL
    MOV AH, 2
    INT 21H
    
    MOV AH, 4CH
    INT 21H

Fun:
    ;和零比较，如果相等就赋值为1
    CMP	SI, 0
    JE re

    PUSH SI
    DEC	SI
    CALL Fun
    POP SI

    MOV AX, SI
    MUL	BX
    MOV BX, AX
    RET
re:
    MOV BX, 1
    RET 

CODES ENDS
END START