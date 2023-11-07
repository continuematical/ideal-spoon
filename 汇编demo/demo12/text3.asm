;求出20个BCD数字之和，并存入SUM1双字单元
DATA SEGMENT
    LIST1 db '6705762998'
          db '4322687310'
    SUM1 dd ?
DATA ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATA, SS:STACKS
START:
    MOV AX, DATA
    MOV DS, AX
;结果存入ax中
    xor ax,ax
    mov cx,20
    lea bx,LIST1
;求和
NEXT:
    add al,CS:[bx];加上一个非压缩的BCD数
    aaa
    inc bx;指针向后移一位
    CMP cx,0
    JBE NEXT

    mov byte ptr SUM1, al;保存个位
    mov al,ah
    mov ah,0
    ;aam指令用来调整al寄存器的值
    ;al<-al%10,ah<-al/10
    aam
    mov word ptr SUM1+1,ax
    mov word ptr SUM1+3,0
    
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START