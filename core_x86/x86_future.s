%define asm
%ifdef x86_32
%include "./core_x86/x86_32.h"
%endif
%ifdef x86_64
%include "./core_x86/x86_64.h"
%endif
%undef asm

; interrupt disabling and enabling functions from minix
lock:
	pushf	;save flags on stack
	cli		;disable interrupts
	pop lockvar;save flags for possible restoration later
	ret		;return to caller

unlock:
	sti		;enable interrupts
	ret		;return to aller
restore:
	push lockvar	;push flags as they were before previous lock
	popf		;restore flags
	ret			;return to caller
	
; Reboot functions from minix
reboot:
	cli			;disable interrupts
	mov ax,#0x20
	out 0x20
	call resvec
	int 0x19
	
wreboot:
	cli
	mov ax,#0x20
	out 0x20
	call resvec
	xor ax,ax
	int 0x16
	int 0x19
	
resvec:
	cld
	mov cx,#2*65
	mov si,#_vec_table
	xor di,di
	mov es,di
	rep
	movw
	ret
	

.data
lockvar: 	.word 0
_vec_table: .zerow 130
