CODE segment
ASSUME DS:CODE,DS:CODE
ORG 100H
START:
		PUSH CS
		POP DS
Again:
        LEA DX,Tips1
		MOV AH,9
		INT 21H ;显示提示
		XOR BP,BP ;BP�?
		MOV CS,2
		@In:mov ah,0
		INT 16H ;无回显输�?
		CMP AL,1BH ;Esc退出程�?
		JZ quit
		CMP AL,ODH
		JZ Show ;回车结束输入
		CMP AL,'0'
		JB @In
		CMP AL,'9';数据校验
		JA 
		MOV AH,0EH
		INT 10H ;显示有效输入
		AND AL,0FH
		MOV AH,0
		XCHG AX,BP
		MOV BL,10 ;BP×10
		MUL BL
		ADD BP,AX ;BP+AX
		LOOP @In
Show:
		CMP BP,40
		JBE Q4
		LEA DX,CuoWu
		MOV AH,9
		INT 21H
		JMP quit
Q4:
		XOR DX,DX
		MOV AX,BP
		MUL BP
		MUL BP
		MOV DX,AX
		MOV CUBE,AX
		PUSH AX
		MOV AL,'='
		MOV AH,0EH
		INT 10H
		POP AX
		call binidec
		JUP START
quit:
		MOV AH,0
		INT 16H
		MOV AH,4CH
		int 21H
		Tips1 DB 0DH,0AH,'Input(0-40),Esc to Quit: $'
		CuoWu db 'Input Error!$'
		CUBE dw 0
		binidec:
		mov cx,10000d
		call dec_div
		mov cx,1000d
		call dec_div
		mov cx,100d
		call dec_div
		mov cx,10d
		call dec_div
		mov cx,1d
		call dec_div
		ret
dec_div:
    mov ax,dx
    mov dx,0
    div cx
    mov bx,dx
    add al,30h
    mov ah,0eh
		int 10h
		ret
code ends
end start