	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.section	.text$_ZNSt11char_traitsIcE6assignERcRKc,"x"
	.linkonce discard
	.globl	_ZNSt11char_traitsIcE6assignERcRKc
	.def	_ZNSt11char_traitsIcE6assignERcRKc;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11char_traitsIcE6assignERcRKc
_ZNSt11char_traitsIcE6assignERcRKc:
.LFB6010:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 24[rbp]
	movzx	edx, BYTE PTR [rax]
	mov	rax, QWORD PTR 16[rbp]
	mov	BYTE PTR [rax], dl
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt11char_traitsIcE12to_char_typeERKi,"x"
	.linkonce discard
	.globl	_ZNSt11char_traitsIcE12to_char_typeERKi
	.def	_ZNSt11char_traitsIcE12to_char_typeERKi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11char_traitsIcE12to_char_typeERKi
_ZNSt11char_traitsIcE12to_char_typeERKi:
.LFB6019:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	eax, DWORD PTR [rax]
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt11char_traitsIcE11eq_int_typeERKiS2_,"x"
	.linkonce discard
	.globl	_ZNSt11char_traitsIcE11eq_int_typeERKiS2_
	.def	_ZNSt11char_traitsIcE11eq_int_typeERKiS2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11char_traitsIcE11eq_int_typeERKiS2_
_ZNSt11char_traitsIcE11eq_int_typeERKiS2_:
.LFB6021:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 16[rbp]
	mov	edx, DWORD PTR [rax]
	mov	rax, QWORD PTR 24[rbp]
	mov	eax, DWORD PTR [rax]
	cmp	edx, eax
	sete	al
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt11char_traitsIcE3eofEv,"x"
	.linkonce discard
	.globl	_ZNSt11char_traitsIcE3eofEv
	.def	_ZNSt11char_traitsIcE3eofEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11char_traitsIcE3eofEv
_ZNSt11char_traitsIcE3eofEv:
.LFB6022:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	eax, -1
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt11char_traitsIwE6assignERwRKw,"x"
	.linkonce discard
	.globl	_ZNSt11char_traitsIwE6assignERwRKw
	.def	_ZNSt11char_traitsIwE6assignERwRKw;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11char_traitsIwE6assignERwRKw
_ZNSt11char_traitsIwE6assignERwRKw:
.LFB6024:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 24[rbp]
	movzx	edx, WORD PTR [rax]
	mov	rax, QWORD PTR 16[rbp]
	mov	WORD PTR [rax], dx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt11char_traitsIwE6lengthEPKw,"x"
	.linkonce discard
	.globl	_ZNSt11char_traitsIwE6lengthEPKw
	.def	_ZNSt11char_traitsIwE6lengthEPKw;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11char_traitsIwE6lengthEPKw
_ZNSt11char_traitsIwE6lengthEPKw:
.LFB6028:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	eax, 0
	test	al, al
	je	.L11
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZN9__gnu_cxx11char_traitsIwE6lengthEPKw
	jmp	.L12
.L11:
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	wcslen
	nop
.L12:
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZStorSt13_Ios_OpenmodeS_,"x"
	.linkonce discard
	.globl	_ZStorSt13_Ios_OpenmodeS_
	.def	_ZStorSt13_Ios_OpenmodeS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZStorSt13_Ios_OpenmodeS_
_ZStorSt13_Ios_OpenmodeS_:
.LFB7504:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	DWORD PTR 16[rbp], ecx
	mov	DWORD PTR 24[rbp], edx
	mov	eax, DWORD PTR 16[rbp]
	or	eax, DWORD PTR 24[rbp]
	pop	rbp
	ret
	.seh_endproc
	.globl	CLASS_NAME
	.section .rdata,"dr"
	.align 2
.LC0:
	.ascii "N\0o\0t\0e\0p\0a\0d\0\0\0"
	.data
	.align 8
CLASS_NAME:
	.quad	.LC0
	.globl	hwndEdit
	.bss
	.align 8
hwndEdit:
	.space 8
	.globl	originalEditProc
	.align 8
originalEditProc:
	.space 8
	.globl	_Z15currentFileNameB5cxx11
	.align 32
_Z15currentFileNameB5cxx11:
	.space 32
	.globl	isModified
isModified:
	.space 1
	.text
	.globl	_Z15StringToWStringRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	_Z15StringToWStringRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z15StringToWStringRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
_Z15StringToWStringRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB8057:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 56
	.seh_stackalloc	56
	lea	rbp, 48[rsp]
	.seh_setframe	rbp, 48
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	lea	rax, -9[rbp]
	mov	QWORD PTR -8[rbp], rax
	nop
	nop
	mov	rax, QWORD PTR 40[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE3endEv
	mov	rbx, rax
	mov	rax, QWORD PTR 40[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5beginEv
	mov	rdx, rax
	lea	rcx, -9[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r9, rcx
	mov	r8, rbx
	mov	rcx, rax
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEvEET_SE_RKS3_
.LEHE0:
	lea	rax, -9[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	jmp	.L19
.L18:
	mov	rbx, rax
	lea	rax, -9[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	mov	rax, rbx
	mov	rcx, rax
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L19:
	mov	rax, QWORD PTR 32[rbp]
	add	rsp, 56
	pop	rbx
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8057:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8057-.LLSDACSB8057
.LLSDACSB8057:
	.uleb128 .LEHB0-.LFB8057
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L18-.LFB8057
	.uleb128 0
	.uleb128 .LEHB1-.LFB8057
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE8057:
	.text
	.seh_endproc
	.section .rdata,"dr"
	.align 2
.LC1:
	.ascii "*\0\0\0"
	.align 2
.LC2:
	.ascii "\0\0"
	.align 2
.LC3:
	.ascii " \0-\0 \0N\0o\0t\0e\0p\0a\0d\0\0\0"
	.text
	.globl	_Z17UpdateWindowTitleP6HWND__
	.def	_Z17UpdateWindowTitleP6HWND__;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z17UpdateWindowTitleP6HWND__
_Z17UpdateWindowTitleP6HWND__:
.LFB8058:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 104
	.seh_stackalloc	104
	lea	rbp, 96[rsp]
	.seh_setframe	rbp, 96
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	movzx	eax, BYTE PTR isModified[rip]
	test	al, al
	je	.L21
	lea	rax, .LC1[rip]
	jmp	.L22
.L21:
	lea	rax, .LC2[rip]
.L22:
	lea	rcx, -32[rbp]
	lea	r8, _Z15currentFileNameB5cxx11[rip]
	mov	rdx, rax
.LEHB2:
	call	_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
.LEHE2:
	lea	rax, -64[rbp]
	lea	rdx, -32[rbp]
	lea	r8, .LC3[rip]
	mov	rcx, rax
.LEHB3:
	call	_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_
.LEHE3:
	lea	rax, -32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv
	mov	rdx, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SetWindowTextW[rip]
.LEHB4:
	call	rax
.LEHE4:
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	jmp	.L27
.L25:
	mov	rbx, rax
	lea	rax, -32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB5:
	call	_Unwind_Resume
.L26:
	mov	rbx, rax
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	mov	rax, rbx
	mov	rcx, rax
	call	_Unwind_Resume
	nop
.LEHE5:
.L27:
	add	rsp, 104
	pop	rbx
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8058:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8058-.LLSDACSB8058
.LLSDACSB8058:
	.uleb128 .LEHB2-.LFB8058
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB8058
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L25-.LFB8058
	.uleb128 0
	.uleb128 .LEHB4-.LFB8058
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L26-.LFB8058
	.uleb128 0
	.uleb128 .LEHB5-.LFB8058
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE8058:
	.text
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC4:
	.ascii "T\0e\0x\0t\0 \0F\0i\0l\0e\0s\0\0\0*\0.\0T\0X\0T\0\0\0A\0l\0l\0 \0F\0i\0l\0e\0s\0\0\0*\0.\0*\0\0\0\0\0"
	.align 2
.LC5:
	.ascii "E\0r\0r\0o\0r\0\0\0"
	.align 8
.LC6:
	.ascii "F\0a\0i\0l\0e\0d\0 \0t\0o\0 \0o\0p\0e\0n\0 \0t\0h\0e\0 \0f\0i\0l\0e\0.\0\0\0"
	.text
	.globl	_Z8OpenFileP6HWND__
	.def	_Z8OpenFileP6HWND__;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8OpenFileP6HWND__
_Z8OpenFileP6HWND__:
.LFB8059:
	push	rbp
	.seh_pushreg	rbp
	push	rdi
	.seh_pushreg	rdi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 1344
	.seh_stackalloc	1344
	lea	rbp, 128[rsp]
	.seh_setframe	rbp, 128
	.seh_endprologue
	mov	QWORD PTR 1248[rbp], rcx
	lea	rdx, 480[rbp]
	mov	eax, 0
	mov	ecx, 65
	mov	rdi, rdx
	rep stosq
	lea	rax, 1008[rbp]
	mov	r8d, 152
	mov	edx, 0
	mov	rcx, rax
	call	memset
	mov	DWORD PTR 1008[rbp], 152
	mov	rax, QWORD PTR 1248[rbp]
	mov	QWORD PTR 1016[rbp], rax
	lea	rax, 480[rbp]
	mov	QWORD PTR 1056[rbp], rax
	mov	DWORD PTR 1064[rbp], 260
	lea	rax, .LC4[rip]
	mov	QWORD PTR 1032[rbp], rax
	mov	DWORD PTR 1052[rbp], 1
	mov	QWORD PTR 1072[rbp], 0
	mov	DWORD PTR 1080[rbp], 0
	mov	QWORD PTR 1088[rbp], 0
	mov	DWORD PTR 1104[rbp], 6144
	lea	rax, 1008[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetOpenFileNameW[rip]
.LEHB6:
	call	rax
	test	eax, eax
	setne	al
	test	al, al
	je	.L40
	mov	rdx, QWORD PTR 1056[rbp]
	mov	rax, rbp
	mov	r8d, 4
	mov	rcx, rax
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKwSt13_Ios_Openmode
.LEHE6:
	mov	rax, rbp
	mov	rcx, rax
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE7is_openEv
	test	al, al
	je	.L30
	lea	rax, 1167[rbp]
	mov	QWORD PTR 1208[rbp], rax
	nop
	nop
	lea	rax, 1168[rbp]
	mov	rcx, rax
	call	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1Ev
	mov	rdx, rbp
	lea	rax, 1184[rbp]
	mov	rcx, rax
	call	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1ERSi
	mov	rax, QWORD PTR 1184[rbp]
	mov	rdx, QWORD PTR 1192[rbp]
	mov	QWORD PTR -80[rbp], rax
	mov	QWORD PTR -72[rbp], rdx
	mov	rax, QWORD PTR 1168[rbp]
	mov	rdx, QWORD PTR 1176[rbp]
	mov	QWORD PTR -96[rbp], rax
	mov	QWORD PTR -88[rbp], rdx
	lea	r8, 1167[rbp]
	lea	rcx, -96[rbp]
	lea	rdx, -80[rbp]
	lea	rax, -64[rbp]
	mov	r9, r8
	mov	r8, rcx
	mov	rcx, rax
.LEHB7:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt19istreambuf_iteratorIcS2_EvEET_S8_RKS3_
.LEHE7:
	lea	rax, 1167[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
	mov	rax, rbp
	mov	rcx, rax
.LEHB8:
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv
	lea	rax, -32[rbp]
	lea	rdx, -64[rbp]
	mov	rcx, rax
	call	_Z15StringToWStringRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE8:
	lea	rax, -32[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv
	mov	rdx, rax
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SetWindowTextW[rip]
.LEHB9:
	call	rax
	mov	rax, QWORD PTR 1056[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_PathFindFileNameW[rip]
	call	rax
	mov	rdx, rax
	lea	rax, _Z15currentFileNameB5cxx11[rip]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEaSEPKw
	mov	BYTE PTR isModified[rip], 0
	mov	rax, QWORD PTR 1248[rbp]
	mov	rcx, rax
	call	_Z17UpdateWindowTitleP6HWND__
	mov	DWORD PTR 476[rbp], 16
	lea	rdx, 476[rbp]
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	r9, rdx
	mov	r8d, 1
	mov	edx, 203
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SendMessageA[rip]
	call	rax
.LEHE9:
	lea	rax, -32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L31
.L30:
	mov	rax, QWORD PTR 1248[rbp]
	mov	r9d, 16
	lea	r8, .LC5[rip]
	lea	rdx, .LC6[rip]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_MessageBoxW[rip]
.LEHB10:
	call	rax
.LEHE10:
.L31:
	mov	rax, rbp
	mov	rcx, rax
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	jmp	.L40
.L36:
	mov	rbx, rax
	lea	rax, 1167[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
	jmp	.L33
.L38:
	mov	rbx, rax
	lea	rax, -32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	jmp	.L35
.L37:
	mov	rbx, rax
.L35:
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L33
.L39:
	mov	rbx, rax
.L33:
	mov	rax, rbp
	mov	rcx, rax
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB11:
	call	_Unwind_Resume
.LEHE11:
.L40:
	nop
	add	rsp, 1344
	pop	rbx
	pop	rdi
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8059:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8059-.LLSDACSB8059
.LLSDACSB8059:
	.uleb128 .LEHB6-.LFB8059
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB7-.LFB8059
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L36-.LFB8059
	.uleb128 0
	.uleb128 .LEHB8-.LFB8059
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L37-.LFB8059
	.uleb128 0
	.uleb128 .LEHB9-.LFB8059
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L38-.LFB8059
	.uleb128 0
	.uleb128 .LEHB10-.LFB8059
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L39-.LFB8059
	.uleb128 0
	.uleb128 .LEHB11-.LFB8059
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
.LLSDACSE8059:
	.text
	.seh_endproc
	.section .rdata,"dr"
	.align 2
.LC7:
	.ascii "*\0.\0t\0x\0t\0\0\0"
	.align 8
.LC8:
	.ascii "T\0e\0x\0t\0 \0D\0o\0c\0u\0m\0e\0n\0t\0s\0 \0(\0*\0.\0t\0x\0t\0)\0\0\0*\0.\0t\0x\0t\0\0\0A\0l\0l\0 \0F\0i\0l\0e\0s\0 \0(\0*\0.\0*\0)\0\0\0*\0.\0*\0\0\0\0\0"
	.align 2
.LC9:
	.ascii ".\0\0\0"
	.align 2
.LC10:
	.ascii ".\0t\0x\0t\0\0\0"
	.text
	.globl	_Z8SaveFileP6HWND__S0_
	.def	_Z8SaveFileP6HWND__S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8SaveFileP6HWND__S0_
_Z8SaveFileP6HWND__S0_:
.LFB8060:
	push	rbp
	.seh_pushreg	rbp
	push	rdi
	.seh_pushreg	rdi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 1248
	.seh_stackalloc	1248
	lea	rbp, 128[rsp]
	.seh_setframe	rbp, 128
	.seh_endprologue
	mov	QWORD PTR 1152[rbp], rcx
	mov	QWORD PTR 1160[rbp], rdx
	lea	rdx, 400[rbp]
	mov	eax, 0
	mov	ecx, 65
	mov	rdi, rdx
	rep stosq
	lea	rax, 400[rbp]
	lea	rdx, .LC7[rip]
	mov	rcx, rax
.LEHB12:
	call	_Z8wcscpy_sILy260EEiRAT__wPKw
	lea	rax, 928[rbp]
	mov	r8d, 152
	mov	edx, 0
	mov	rcx, rax
	call	memset
	mov	DWORD PTR 928[rbp], 152
	mov	rax, QWORD PTR 1152[rbp]
	mov	QWORD PTR 936[rbp], rax
	lea	rax, 400[rbp]
	mov	QWORD PTR 976[rbp], rax
	mov	DWORD PTR 984[rbp], 260
	lea	rax, .LC8[rip]
	mov	QWORD PTR 952[rbp], rax
	mov	DWORD PTR 972[rbp], 1
	mov	QWORD PTR 992[rbp], 0
	mov	DWORD PTR 1000[rbp], 0
	mov	QWORD PTR 1008[rbp], 0
	mov	DWORD PTR 1024[rbp], 2050
	lea	rax, 928[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetSaveFileNameW[rip]
	call	rax
.LEHE12:
	test	eax, eax
	setne	al
	test	al, al
	je	.L55
	lea	rax, 1095[rbp]
	mov	QWORD PTR 1096[rbp], rax
	nop
	nop
	mov	rdx, QWORD PTR 976[rbp]
	lea	rcx, 1095[rbp]
	lea	rax, -96[rbp]
	mov	r8, rcx
	mov	rcx, rax
.LEHB13:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IS3_EEPKwRKS3_
.LEHE13:
	lea	rax, 1095[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	lea	rax, -96[rbp]
	mov	r8d, 0
	lea	rdx, .LC9[rip]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE4findEPKwy
	cmp	rax, -1
	sete	al
	test	al, al
	je	.L43
	lea	rax, -96[rbp]
	lea	rdx, .LC10[rip]
	mov	rcx, rax
.LEHB14:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEpLEPKw
.L43:
	mov	rax, QWORD PTR 1160[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetWindowTextLengthW[rip]
	call	rax
	add	eax, 1
	mov	DWORD PTR 1116[rbp], eax
	mov	eax, DWORD PTR 1116[rbp]
	cdqe
	movabs	rdx, 4611686018427387900
	cmp	rdx, rax
	jb	.L44
	add	rax, rax
	mov	rcx, rax
	call	_Znay
	jmp	.L54
.L44:
	call	__cxa_throw_bad_array_new_length
.L54:
	mov	QWORD PTR 1104[rbp], rax
	mov	ecx, DWORD PTR 1116[rbp]
	mov	rdx, QWORD PTR 1104[rbp]
	mov	rax, QWORD PTR 1160[rbp]
	mov	r8d, ecx
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetWindowTextW[rip]
	call	rax
	mov	edx, 32
	mov	ecx, 16
	call	_ZStorSt13_Ios_OpenmodeS_
	mov	ebx, eax
	lea	rax, -96[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv
	mov	rdx, rax
	lea	rax, -64[rbp]
	mov	r8d, ebx
	mov	rcx, rax
	call	_ZNSt14basic_ofstreamIwSt11char_traitsIwEEC1EPKwSt13_Ios_Openmode
.LEHE14:
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt14basic_ofstreamIwSt11char_traitsIwEE7is_openEv
	test	al, al
	je	.L46
	mov	eax, DWORD PTR 1116[rbp]
	sub	eax, 1
	movsx	rcx, eax
	mov	rdx, QWORD PTR 1104[rbp]
	lea	rax, -64[rbp]
	mov	r8, rcx
	mov	rcx, rax
.LEHB15:
	call	_ZNSt13basic_ostreamIwSt11char_traitsIwEE5writeEPKwx
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt14basic_ofstreamIwSt11char_traitsIwEE5closeEv
	lea	rax, -96[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_PathFindFileNameW[rip]
	call	rax
	mov	rdx, rax
	lea	rax, _Z15currentFileNameB5cxx11[rip]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEaSEPKw
	mov	BYTE PTR isModified[rip], 0
	mov	rax, QWORD PTR 1152[rbp]
	mov	rcx, rax
	call	_Z17UpdateWindowTitleP6HWND__
.LEHE15:
.L46:
	cmp	QWORD PTR 1104[rbp], 0
	je	.L47
	mov	rax, QWORD PTR 1104[rbp]
	mov	rcx, rax
	call	_ZdaPv
.L47:
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt14basic_ofstreamIwSt11char_traitsIwEED1Ev
	lea	rax, -96[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	jmp	.L55
.L51:
	mov	rbx, rax
	lea	rax, 1095[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	mov	rax, rbx
	mov	rcx, rax
.LEHB16:
	call	_Unwind_Resume
.L53:
	mov	rbx, rax
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt14basic_ofstreamIwSt11char_traitsIwEED1Ev
	jmp	.L50
.L52:
	mov	rbx, rax
.L50:
	lea	rax, -96[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	mov	rax, rbx
	mov	rcx, rax
	call	_Unwind_Resume
.LEHE16:
.L55:
	nop
	add	rsp, 1248
	pop	rbx
	pop	rdi
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8060:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8060-.LLSDACSB8060
.LLSDACSB8060:
	.uleb128 .LEHB12-.LFB8060
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB13-.LFB8060
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L51-.LFB8060
	.uleb128 0
	.uleb128 .LEHB14-.LFB8060
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L52-.LFB8060
	.uleb128 0
	.uleb128 .LEHB15-.LFB8060
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L53-.LFB8060
	.uleb128 0
	.uleb128 .LEHB16-.LFB8060
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0
	.uleb128 0
.LLSDACSE8060:
	.text
	.seh_endproc
	.section .rdata,"dr"
	.align 2
.LC11:
	.ascii "W\0a\0r\0n\0i\0n\0g\0\0\0"
	.align 8
.LC12:
	.ascii "Y\0o\0u\0 \0h\0a\0v\0e\0 \0u\0n\0s\0a\0v\0e\0d\0 \0c\0h\0a\0n\0g\0e\0s\0.\0 \0D\0o\0 \0y\0o\0u\0 \0w\0a\0n\0t\0 \0t\0o\0 \0s\0a\0v\0e\0 \0t\0h\0e\0m\0?\0\0\0"
	.text
	.globl	_Z19CheckUnsavedChangesP6HWND__
	.def	_Z19CheckUnsavedChangesP6HWND__;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z19CheckUnsavedChangesP6HWND__
_Z19CheckUnsavedChangesP6HWND__:
.LFB8061:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	movzx	eax, BYTE PTR isModified[rip]
	test	al, al
	je	.L56
	mov	rax, QWORD PTR 16[rbp]
	mov	r9d, 51
	lea	r8, .LC11[rip]
	lea	rdx, .LC12[rip]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_MessageBoxW[rip]
	call	rax
	mov	DWORD PTR -4[rbp], eax
	cmp	DWORD PTR -4[rbp], 6
	jne	.L58
	mov	rdx, QWORD PTR hwndEdit[rip]
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_Z8SaveFileP6HWND__S0_
	jmp	.L56
.L58:
	cmp	DWORD PTR -4[rbp], 2
.L56:
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.globl	WinMain
	.def	WinMain;	.scl	2;	.type	32;	.endef
	.seh_proc	WinMain
WinMain:
.LFB8062:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 224
	.seh_stackalloc	224
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	QWORD PTR 32[rbp], r8
	mov	DWORD PTR 40[rbp], r9d
	pxor	xmm0, xmm0
	movups	XMMWORD PTR -80[rbp], xmm0
	movups	XMMWORD PTR -64[rbp], xmm0
	movups	XMMWORD PTR -48[rbp], xmm0
	movups	XMMWORD PTR -32[rbp], xmm0
	movq	QWORD PTR -16[rbp], xmm0
	lea	rax, _Z10WindowProcP6HWND__jyx[rip]
	mov	QWORD PTR -72[rbp], rax
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR -56[rbp], rax
	mov	rax, QWORD PTR CLASS_NAME[rip]
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR 16[rbp]
	mov	edx, 101
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_LoadIconA[rip]
	call	rax
	mov	QWORD PTR -48[rbp], rax
	lea	rax, -80[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_RegisterClassW[rip]
	call	rax
	mov	rax, QWORD PTR CLASS_NAME[rip]
	mov	QWORD PTR 88[rsp], 0
	mov	rdx, QWORD PTR 16[rbp]
	mov	QWORD PTR 80[rsp], rdx
	mov	QWORD PTR 72[rsp], 0
	mov	QWORD PTR 64[rsp], 0
	mov	DWORD PTR 56[rsp], -2147483648
	mov	DWORD PTR 48[rsp], -2147483648
	mov	DWORD PTR 40[rsp], -2147483648
	mov	DWORD PTR 32[rsp], -2147483648
	mov	r9d, 13565952
	lea	r8, .LC0[rip]
	mov	rdx, rax
	mov	ecx, 0
	mov	rax, QWORD PTR __imp_CreateWindowExW[rip]
	call	rax
	mov	QWORD PTR -8[rbp], rax
	cmp	QWORD PTR -8[rbp], 0
	jne	.L60
	mov	eax, 0
	jmp	.L64
.L60:
	mov	edx, DWORD PTR 40[rbp]
	mov	rax, QWORD PTR -8[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_ShowWindow[rip]
	call	rax
	mov	rax, QWORD PTR -8[rbp]
	mov	rcx, rax
	call	_Z17UpdateWindowTitleP6HWND__
	pxor	xmm0, xmm0
	movups	XMMWORD PTR -128[rbp], xmm0
	movups	XMMWORD PTR -112[rbp], xmm0
	movups	XMMWORD PTR -96[rbp], xmm0
	jmp	.L62
.L63:
	lea	rax, -128[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_TranslateMessage[rip]
	call	rax
	lea	rax, -128[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_DispatchMessageA[rip]
	call	rax
.L62:
	lea	rax, -128[rbp]
	mov	r9d, 0
	mov	r8d, 0
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetMessageA[rip]
	call	rax
	test	eax, eax
	setne	al
	test	al, al
	jne	.L63
	mov	eax, 0
.L64:
	add	rsp, 224
	pop	rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 2
.LC13:
	.ascii "N\0e\0w\0\0\0"
	.align 2
.LC14:
	.ascii "O\0p\0e\0n\0\0\0"
	.align 2
.LC15:
	.ascii "S\0a\0v\0e\0\0\0"
	.align 2
.LC16:
	.ascii "E\0x\0i\0t\0\0\0"
	.align 2
.LC17:
	.ascii "U\0n\0d\0o\0\0\0"
	.align 2
.LC18:
	.ascii "C\0u\0t\0\0\0"
	.align 2
.LC19:
	.ascii "C\0o\0p\0y\0\0\0"
	.align 2
.LC20:
	.ascii "P\0a\0s\0t\0e\0\0\0"
	.align 2
.LC21:
	.ascii "F\0i\0l\0e\0\0\0"
	.align 2
.LC22:
	.ascii "E\0d\0i\0t\0\0\0"
	.align 2
.LC23:
	.ascii "E\0D\0I\0T\0\0\0"
	.align 2
.LC24:
	.ascii "C\0o\0n\0s\0o\0l\0a\0s\0\0\0"
	.align 2
.LC25:
	.ascii "U\0n\0t\0i\0t\0l\0e\0d\0\0\0"
	.text
	.globl	_Z10WindowProcP6HWND__jyx
	.def	_Z10WindowProcP6HWND__jyx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10WindowProcP6HWND__jyx
_Z10WindowProcP6HWND__jyx:
.LFB8063:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 160
	.seh_stackalloc	160
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	DWORD PTR 24[rbp], edx
	mov	QWORD PTR 32[rbp], r8
	mov	QWORD PTR 40[rbp], r9
	cmp	DWORD PTR 24[rbp], 273
	je	.L66
	cmp	DWORD PTR 24[rbp], 273
	ja	.L67
	cmp	DWORD PTR 24[rbp], 5
	je	.L68
	cmp	DWORD PTR 24[rbp], 5
	ja	.L67
	cmp	DWORD PTR 24[rbp], 1
	je	.L69
	cmp	DWORD PTR 24[rbp], 2
	je	.L70
	jmp	.L67
.L69:
	mov	rax, QWORD PTR __imp_CreateMenu[rip]
	call	rax
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR __imp_CreateMenu[rip]
	call	rax
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR __imp_CreateMenu[rip]
	call	rax
	mov	QWORD PTR -24[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	lea	r9, .LC13[rip]
	mov	r8d, 1
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rax, QWORD PTR -16[rbp]
	lea	r9, .LC14[rip]
	mov	r8d, 2
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rax, QWORD PTR -16[rbp]
	lea	r9, .LC15[rip]
	mov	r8d, 3
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rax, QWORD PTR -16[rbp]
	mov	r9d, 0
	mov	r8d, 0
	mov	edx, 2048
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rax, QWORD PTR -16[rbp]
	lea	r9, .LC16[rip]
	mov	r8d, 4
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rax, QWORD PTR -24[rbp]
	lea	r9, .LC17[rip]
	mov	r8d, 5
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rax, QWORD PTR -24[rbp]
	lea	r9, .LC18[rip]
	mov	r8d, 6
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rax, QWORD PTR -24[rbp]
	lea	r9, .LC19[rip]
	mov	r8d, 7
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rax, QWORD PTR -24[rbp]
	lea	r9, .LC20[rip]
	mov	r8d, 8
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rdx, QWORD PTR -16[rbp]
	mov	rax, QWORD PTR -8[rbp]
	lea	r9, .LC21[rip]
	mov	r8, rdx
	mov	edx, 16
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rdx, QWORD PTR -24[rbp]
	mov	rax, QWORD PTR -8[rbp]
	lea	r9, .LC22[rip]
	mov	r8, rdx
	mov	edx, 16
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_AppendMenuW[rip]
	call	rax
	mov	rdx, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SetMenu[rip]
	call	rax
	mov	ecx, 0
	mov	rax, QWORD PTR __imp_GetModuleHandleA[rip]
	call	rax
	mov	QWORD PTR 88[rsp], 0
	mov	QWORD PTR 80[rsp], rax
	mov	QWORD PTR 72[rsp], 101
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR 64[rsp], rax
	mov	DWORD PTR 56[rsp], -2147483648
	mov	DWORD PTR 48[rsp], -2147483648
	mov	DWORD PTR 40[rsp], 0
	mov	DWORD PTR 32[rsp], 0
	mov	r9d, 1344278596
	lea	r8, .LC2[rip]
	lea	rax, .LC23[rip]
	mov	rdx, rax
	mov	ecx, 0
	mov	rax, QWORD PTR __imp_CreateWindowExW[rip]
	call	rax
	mov	QWORD PTR hwndEdit[rip], rax
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetDC[rip]
	call	rax
	mov	edx, 90
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetDeviceCaps[rip]
	call	rax
	mov	r8d, 72
	mov	edx, eax
	mov	ecx, 11
	mov	rax, QWORD PTR __imp_MulDiv[rip]
	call	rax
	neg	eax
	lea	rdx, .LC24[rip]
	mov	QWORD PTR 104[rsp], rdx
	mov	DWORD PTR 96[rsp], 49
	mov	DWORD PTR 88[rsp], 0
	mov	DWORD PTR 80[rsp], 0
	mov	DWORD PTR 72[rsp], 0
	mov	DWORD PTR 64[rsp], 1
	mov	DWORD PTR 56[rsp], 0
	mov	DWORD PTR 48[rsp], 0
	mov	DWORD PTR 40[rsp], 0
	mov	DWORD PTR 32[rsp], 400
	mov	r9d, 0
	mov	r8d, 0
	mov	edx, 0
	mov	ecx, eax
	mov	rax, QWORD PTR __imp_CreateFontW[rip]
	call	rax
	mov	QWORD PTR -32[rbp], rax
	mov	rdx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	r9d, 1
	mov	r8, rdx
	mov	edx, 48
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SendMessageA[rip]
	call	rax
	lea	rdx, _Z8EditProcP6HWND__jyx[rip]
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	r8, rdx
	mov	edx, -4
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SetWindowLongPtrA[rip]
	call	rax
	mov	QWORD PTR originalEditProc[rip], rax
	jmp	.L67
.L68:
	lea	rdx, -48[rbp]
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetClientRect[rip]
	call	rax
	mov	ecx, DWORD PTR -36[rbp]
	mov	edx, DWORD PTR -40[rbp]
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	DWORD PTR 48[rsp], 4
	mov	DWORD PTR 40[rsp], ecx
	mov	DWORD PTR 32[rsp], edx
	mov	r9d, 0
	mov	r8d, 0
	mov	edx, 0
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SetWindowPos[rip]
	call	rax
	jmp	.L67
.L66:
	mov	rax, QWORD PTR 32[rbp]
	movzx	eax, ax
	cmp	eax, 8
	ja	.L82
	mov	eax, eax
	lea	rdx, 0[0+rax*4]
	lea	rax, .L73[rip]
	mov	eax, DWORD PTR [rdx+rax]
	cdqe
	lea	rdx, .L73[rip]
	add	rax, rdx
	jmp	rax
	.section .rdata,"dr"
	.align 4
.L73:
	.long	.L82-.L73
	.long	.L80-.L73
	.long	.L79-.L73
	.long	.L78-.L73
	.long	.L77-.L73
	.long	.L76-.L73
	.long	.L75-.L73
	.long	.L74-.L73
	.long	.L72-.L73
	.text
.L80:
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_Z19CheckUnsavedChangesP6HWND__
	mov	rax, QWORD PTR hwndEdit[rip]
	lea	rdx, .LC2[rip]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SetWindowTextW[rip]
	call	rax
	lea	rax, .LC25[rip]
	mov	rdx, rax
	lea	rax, _Z15currentFileNameB5cxx11[rip]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEaSEPKw
	mov	BYTE PTR isModified[rip], 0
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_Z17UpdateWindowTitleP6HWND__
	jmp	.L71
.L79:
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_Z19CheckUnsavedChangesP6HWND__
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_Z8OpenFileP6HWND__
	jmp	.L71
.L78:
	mov	rdx, QWORD PTR hwndEdit[rip]
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_Z8SaveFileP6HWND__S0_
	jmp	.L71
.L77:
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_Z19CheckUnsavedChangesP6HWND__
	mov	ecx, 0
	mov	rax, QWORD PTR __imp_PostQuitMessage[rip]
	call	rax
	jmp	.L71
.L76:
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	r9d, 0
	mov	r8d, 0
	mov	edx, 772
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SendMessageA[rip]
	call	rax
	jmp	.L71
.L75:
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	r9d, 0
	mov	r8d, 0
	mov	edx, 768
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SendMessageA[rip]
	call	rax
	jmp	.L71
.L74:
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	r9d, 0
	mov	r8d, 0
	mov	edx, 769
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SendMessageA[rip]
	call	rax
	jmp	.L71
.L72:
	mov	rax, QWORD PTR hwndEdit[rip]
	mov	r9d, 0
	mov	r8d, 0
	mov	edx, 770
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SendMessageA[rip]
	call	rax
	nop
.L71:
	jmp	.L82
.L70:
	mov	ecx, 0
	mov	rax, QWORD PTR __imp_PostQuitMessage[rip]
	call	rax
	mov	eax, 0
	jmp	.L81
.L82:
	nop
.L67:
	mov	r8, QWORD PTR 40[rbp]
	mov	rcx, QWORD PTR 32[rbp]
	mov	edx, DWORD PTR 24[rbp]
	mov	rax, QWORD PTR 16[rbp]
	mov	r9, r8
	mov	r8, rcx
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_DefWindowProcW[rip]
	call	rax
	nop
.L81:
	add	rsp, 160
	pop	rbp
	ret
	.seh_endproc
	.globl	_Z8EditProcP6HWND__jyx
	.def	_Z8EditProcP6HWND__jyx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8EditProcP6HWND__jyx
_Z8EditProcP6HWND__jyx:
.LFB8064:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	DWORD PTR 24[rbp], edx
	mov	QWORD PTR 32[rbp], r8
	mov	QWORD PTR 40[rbp], r9
	cmp	DWORD PTR 24[rbp], 256
	jne	.L84
	mov	ecx, 17
	mov	rax, QWORD PTR __imp_GetKeyState[rip]
	call	rax
	shr	ax, 15
	test	al, al
	je	.L85
	cmp	QWORD PTR 32[rbp], 65
	je	.L86
	cmp	QWORD PTR 32[rbp], 83
	je	.L87
	jmp	.L85
.L86:
	mov	rax, QWORD PTR 16[rbp]
	mov	r9, -1
	mov	r8d, 0
	mov	edx, 177
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_SendMessageA[rip]
	call	rax
	mov	eax, 0
	jmp	.L88
.L87:
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetParent[rip]
	call	rax
	mov	rcx, rax
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, rax
	call	_Z8SaveFileP6HWND__S0_
	mov	eax, 0
	jmp	.L88
.L84:
	cmp	DWORD PTR 24[rbp], 258
	je	.L89
	cmp	DWORD PTR 24[rbp], 770
	jne	.L85
.L89:
	mov	BYTE PTR isModified[rip], 1
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_GetParent[rip]
	call	rax
	mov	rcx, rax
	call	_Z17UpdateWindowTitleP6HWND__
.L85:
	mov	rax, QWORD PTR originalEditProc[rip]
	mov	r9, QWORD PTR 32[rbp]
	mov	r8d, DWORD PTR 24[rbp]
	mov	rdx, QWORD PTR 16[rbp]
	mov	rcx, QWORD PTR 40[rbp]
	mov	QWORD PTR 32[rsp], rcx
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_CallWindowProcA[rip]
	call	rax
	nop
.L88:
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9__gnu_cxx11char_traitsIwE6lengthEPKw,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9__gnu_cxx11char_traitsIwE6lengthEPKw
	.def	_ZN9__gnu_cxx11char_traitsIwE6lengthEPKw;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9__gnu_cxx11char_traitsIwE6lengthEPKw
_ZN9__gnu_cxx11char_traitsIwE6lengthEPKw:
.LFB8068:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR -8[rbp], 0
	jmp	.L91
.L92:
	add	QWORD PTR -8[rbp], 1
.L91:
	mov	WORD PTR -10[rbp], 0
	mov	rax, QWORD PTR -8[rbp]
	lea	rdx, [rax+rax]
	mov	rax, QWORD PTR 16[rbp]
	lea	rcx, [rdx+rax]
	lea	rax, -10[rbp]
	mov	rdx, rax
	call	_ZN9__gnu_cxx11char_traitsIwE2eqERKwS3_
	xor	eax, 1
	test	al, al
	jne	.L92
	mov	rax, QWORD PTR -8[rbp]
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev:
.LFB8164:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
	nop
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderD1Ev
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderD1Ev
_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderD1Ev:
.LFB8284:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	nop
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC26:
	.ascii "basic_string: construction from null is not valid\0"
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IS3_EEPKwRKS3_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IS3_EEPKwRKS3_
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IS3_EEPKwRKS3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IS3_EEPKwRKS3_
_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IS3_EEPKwRKS3_:
.LFB8358:
	push	rbp
	.seh_pushreg	rbp
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 48
	.seh_stackalloc	48
	lea	rbp, 48[rsp]
	.seh_setframe	rbp, 48
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	QWORD PTR 48[rbp], r8
	mov	rbx, QWORD PTR 32[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_local_dataEv
	mov	rdx, QWORD PTR 48[rbp]
	mov	r8, rdx
	mov	rdx, rax
	mov	rcx, rbx
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS3_
	cmp	QWORD PTR 40[rbp], 0
	jne	.L97
	lea	rax, .LC26[rip]
	mov	rcx, rax
.LEHB17:
	call	_ZSt19__throw_logic_errorPKc
.L97:
	mov	rax, QWORD PTR 40[rbp]
	mov	rcx, rax
	call	_ZNSt11char_traitsIwE6lengthEPKw
	lea	rdx, [rax+rax]
	mov	rax, QWORD PTR 40[rbp]
	add	rax, rdx
	mov	QWORD PTR -8[rbp], rax
	mov	rcx, QWORD PTR -8[rbp]
	mov	rdx, QWORD PTR 40[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r9d, esi
	mov	r8, rcx
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tag
.LEHE17:
	jmp	.L100
.L99:
	mov	rbx, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderD1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB18:
	call	_Unwind_Resume
	nop
.LEHE18:
.L100:
	add	rsp, 48
	pop	rbx
	pop	rsi
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8358:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8358-.LLSDACSB8358
.LLSDACSB8358:
	.uleb128 .LEHB17-.LFB8358
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L99-.LFB8358
	.uleb128 0
	.uleb128 .LEHB18-.LFB8358
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0
	.uleb128 0
.LLSDACSE8358:
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IS3_EEPKwRKS3_,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEvEET_SE_RKS3_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEvEET_SE_RKS3_
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEvEET_SE_RKS3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEvEET_SE_RKS3_
_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEvEET_SE_RKS3_:
.LFB8363:
	push	rbp
	.seh_pushreg	rbp
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 48
	.seh_stackalloc	48
	lea	rbp, 48[rsp]
	.seh_setframe	rbp, 48
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	QWORD PTR 48[rbp], r8
	mov	QWORD PTR 56[rbp], r9
	mov	rbx, QWORD PTR 32[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_local_dataEv
	mov	rdx, QWORD PTR 56[rbp]
	mov	r8, rdx
	mov	rdx, rax
	mov	rcx, rbx
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS3_
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 8[rax], 0
	nop
	mov	rcx, QWORD PTR 48[rbp]
	mov	rdx, QWORD PTR 40[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r9d, esi
	mov	r8, rcx
	mov	rcx, rax
.LEHB19:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tag
.LEHE19:
	jmp	.L105
.L104:
	mov	rbx, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderD1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB20:
	call	_Unwind_Resume
	nop
.LEHE20:
.L105:
	add	rsp, 48
	pop	rbx
	pop	rsi
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8363:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8363-.LLSDACSB8363
.LLSDACSB8363:
	.uleb128 .LEHB19-.LFB8363
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L104-.LFB8363
	.uleb128 0
	.uleb128 .LEHB20-.LFB8363
	.uleb128 .LEHE20-.LEHB20
	.uleb128 0
	.uleb128 0
.LLSDACSE8363:
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEvEET_SE_RKS3_,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,"x"
	.linkonce discard
	.globl	_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
	.def	_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_:
.LFB8364:
	push	rbp
	.seh_pushreg	rbp
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 64
	.seh_stackalloc	64
	lea	rbp, 64[rsp]
	.seh_setframe	rbp, 64
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	QWORD PTR 48[rbp], r8
	lea	rax, -1[rbp]
	mov	rdx, QWORD PTR 48[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13get_allocatorEv
	mov	rax, QWORD PTR 48[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE4sizeEv
	mov	rbx, rax
	mov	rax, QWORD PTR 48[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv
	mov	rsi, rax
	mov	rax, QWORD PTR 40[rbp]
	mov	rcx, rax
.LEHB21:
	call	_ZNSt11char_traitsIwE6lengthEPKw
	mov	r8, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rdx, QWORD PTR 40[rbp]
	lea	rcx, -1[rbp]
	mov	QWORD PTR 40[rsp], rcx
	mov	QWORD PTR 32[rsp], rbx
	mov	r9, rsi
	mov	rcx, rax
	call	_ZSt12__str_concatINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE
.LEHE21:
	nop
	lea	rax, -1[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	jmp	.L110
.L109:
	mov	rbx, rax
	lea	rax, -1[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	mov	rax, rbx
	mov	rcx, rax
.LEHB22:
	call	_Unwind_Resume
.LEHE22:
.L110:
	mov	rax, QWORD PTR 32[rbp]
	add	rsp, 64
	pop	rbx
	pop	rsi
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8364:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8364-.LLSDACSB8364
.LLSDACSB8364:
	.uleb128 .LEHB21-.LFB8364
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L109-.LFB8364
	.uleb128 0
	.uleb128 .LEHB22-.LFB8364
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
.LLSDACSE8364:
	.section	.text$_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_,"x"
	.linkonce discard
	.globl	_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_
	.def	_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_
_ZStplIwSt11char_traitsIwESaIwEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_:
.LFB8365:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	QWORD PTR 32[rbp], r8
	mov	rdx, QWORD PTR 32[rbp]
	mov	rax, QWORD PTR 24[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKw
	mov	rcx, rax
	call	_ZSt4moveIRNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEEONSt16remove_referenceIT_E4typeEOS8_
	mov	rdx, rax
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1EOS4_
	mov	rax, QWORD PTR 16[rbp]
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1ERSi,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1ERSi
	.def	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1ERSi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1ERSi
_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1ERSi:
.LFB8376:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 24[rbp]
	mov	rax, QWORD PTR [rax]
	sub	rax, 24
	mov	rax, QWORD PTR [rax]
	mov	rdx, rax
	mov	rax, QWORD PTR 24[rbp]
	add	rax, rdx
	mov	rcx, rax
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEE5rdbufEv
	mov	rdx, QWORD PTR 16[rbp]
	mov	QWORD PTR [rdx], rax
	call	_ZNSt11char_traitsIcE3eofEv
	mov	rdx, QWORD PTR 16[rbp]
	mov	DWORD PTR 8[rdx], eax
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1Ev
	.def	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1Ev
_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEC1Ev:
.LFB8379:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR [rax], 0
	call	_ZNSt11char_traitsIcE3eofEv
	mov	rdx, QWORD PTR 16[rbp]
	mov	DWORD PTR 8[rdx], eax
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt19istreambuf_iteratorIcS2_EvEET_S8_RKS3_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt19istreambuf_iteratorIcS2_EvEET_S8_RKS3_
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt19istreambuf_iteratorIcS2_EvEET_S8_RKS3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt19istreambuf_iteratorIcS2_EvEET_S8_RKS3_
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt19istreambuf_iteratorIcS2_EvEET_S8_RKS3_:
.LFB8382:
	push	rbp
	.seh_pushreg	rbp
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 96
	.seh_stackalloc	96
	lea	rbp, 96[rsp]
	.seh_setframe	rbp, 96
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	rbx, rdx
	mov	rax, QWORD PTR [rbx]
	mov	rdx, QWORD PTR 8[rbx]
	mov	QWORD PTR -16[rbp], rax
	mov	QWORD PTR -8[rbp], rdx
	mov	rbx, r8
	mov	rax, QWORD PTR [rbx]
	mov	rdx, QWORD PTR 8[rbx]
	mov	QWORD PTR -32[rbp], rax
	mov	QWORD PTR -24[rbp], rdx
	mov	QWORD PTR 56[rbp], r9
	mov	rbx, QWORD PTR 32[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	mov	rdx, QWORD PTR 56[rbp]
	mov	r8, rdx
	mov	rdx, rax
	mov	rcx, rbx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 8[rax], 0
	nop
	mov	rax, QWORD PTR -16[rbp]
	mov	rdx, QWORD PTR -8[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR -64[rbp], rax
	mov	QWORD PTR -56[rbp], rdx
	lea	rcx, -64[rbp]
	lea	rdx, -48[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r9d, esi
	mov	r8, rcx
	mov	rcx, rax
.LEHB23:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tag
.LEHE23:
	jmp	.L119
.L118:
	mov	rbx, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB24:
	call	_Unwind_Resume
	nop
.LEHE24:
.L119:
	add	rsp, 96
	pop	rbx
	pop	rsi
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8382:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8382-.LLSDACSB8382
.LLSDACSB8382:
	.uleb128 .LEHB23-.LFB8382
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L118-.LFB8382
	.uleb128 0
	.uleb128 .LEHB24-.LFB8382
	.uleb128 .LEHE24-.LEHB24
	.uleb128 0
	.uleb128 0
.LLSDACSE8382:
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt19istreambuf_iteratorIcS2_EvEET_S8_RKS3_,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_Z8wcscpy_sILy260EEiRAT__wPKw,"x"
	.linkonce discard
	.globl	_Z8wcscpy_sILy260EEiRAT__wPKw
	.def	_Z8wcscpy_sILy260EEiRAT__wPKw;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8wcscpy_sILy260EEiRAT__wPKw
_Z8wcscpy_sILy260EEiRAT__wPKw:
.LFB8385:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rdx, QWORD PTR 24[rbp]
	mov	rax, QWORD PTR 16[rbp]
	mov	r8, rdx
	mov	edx, 260
	mov	rcx, rax
	mov	rax, QWORD PTR __imp_wcscpy_s[rip]
	call	rax
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9__gnu_cxx11char_traitsIwE2eqERKwS3_,"x"
	.linkonce discard
	.globl	_ZN9__gnu_cxx11char_traitsIwE2eqERKwS3_
	.def	_ZN9__gnu_cxx11char_traitsIwE2eqERKwS3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9__gnu_cxx11char_traitsIwE2eqERKwS3_
_ZN9__gnu_cxx11char_traitsIwE2eqERKwS3_:
.LFB8399:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 16[rbp]
	movzx	edx, WORD PTR [rax]
	mov	rax, QWORD PTR 24[rbp]
	movzx	eax, WORD PTR [rax]
	cmp	dx, ax
	sete	al
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt15__new_allocatorIwED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt15__new_allocatorIwED2Ev
	.def	_ZNSt15__new_allocatorIwED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt15__new_allocatorIwED2Ev
_ZNSt15__new_allocatorIwED2Ev:
.LFB8430:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt15__new_allocatorIcED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt15__new_allocatorIcED2Ev
	.def	_ZNSt15__new_allocatorIcED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt15__new_allocatorIcED2Ev
_ZNSt15__new_allocatorIcED2Ev:
.LFB8451:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardC1EPS4_,"x"
	.linkonce discard
	.align 2
	.globl	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardC1EPS4_
	.def	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardC1EPS4_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardC1EPS4_
_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardC1EPS4_:
.LFB8466:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rax], rdx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev
	.def	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev
_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev:
.LFB8469:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	je	.L129
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE10_M_disposeEv
.L129:
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8469:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8469-.LLSDACSB8469
.LLSDACSB8469:
.LLSDACSE8469:
	.section	.text$_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tag,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tag
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tag;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tag
_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tag:
.LFB8463:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 104
	.seh_stackalloc	104
	lea	rbp, 96[rsp]
	.seh_setframe	rbp, 96
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	QWORD PTR 48[rbp], r8
	mov	rax, QWORD PTR 40[rbp]
	mov	QWORD PTR -56[rbp], rax
	mov	rax, QWORD PTR 48[rbp]
	mov	QWORD PTR -8[rbp], rax
	nop
	mov	rax, QWORD PTR -56[rbp]
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR -24[rbp], rax
	mov	rax, QWORD PTR -24[rbp]
	sub	rax, QWORD PTR -16[rbp]
	sar	rax
	nop
	mov	QWORD PTR -40[rbp], rax
	mov	rax, QWORD PTR -40[rbp]
	cmp	rax, 7
	jbe	.L134
	lea	rdx, -40[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r8d, 0
	mov	rcx, rax
.LEHB25:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE9_M_createERyy
.LEHE25:
	mov	rdx, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEPw
	mov	rdx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE11_M_capacityEy
	jmp	.L135
.L134:
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR -32[rbp], rax
	nop
.L135:
	mov	rdx, QWORD PTR 32[rbp]
	lea	rax, -48[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardC1EPS4_
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEv
	mov	rcx, rax
	mov	rdx, QWORD PTR 48[rbp]
	mov	rax, QWORD PTR 40[rbp]
	mov	r8, rdx
	mov	rdx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsEPwPKwS7_
	mov	QWORD PTR -48[rbp], 0
	mov	rdx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
.LEHB26:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_set_lengthEy
.LEHE26:
	lea	rax, -48[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev
	jmp	.L138
.L137:
	mov	rbx, rax
	lea	rax, -48[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tagEN6_GuardD1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB27:
	call	_Unwind_Resume
	nop
.LEHE27:
.L138:
	add	rsp, 104
	pop	rbx
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8463:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8463-.LLSDACSB8463
.LLSDACSB8463:
	.uleb128 .LEHB25-.LFB8463
	.uleb128 .LEHE25-.LEHB25
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB26-.LFB8463
	.uleb128 .LEHE26-.LEHB26
	.uleb128 .L137-.LFB8463
	.uleb128 0
	.uleb128 .LEHB27-.LFB8463
	.uleb128 .LEHE27-.LEHB27
	.uleb128 0
	.uleb128 0
.LLSDACSE8463:
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIPKwEEvT_S8_St20forward_iterator_tag,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardC1EPS4_,"x"
	.linkonce discard
	.align 2
	.globl	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardC1EPS4_
	.def	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardC1EPS4_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardC1EPS4_
_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardC1EPS4_:
.LFB8516:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rax], rdx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardD1Ev
	.def	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardD1Ev
_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardD1Ev:
.LFB8519:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	je	.L142
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE10_M_disposeEv
.L142:
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8519:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8519-.LLSDACSB8519
.LLSDACSB8519:
.LLSDACSE8519:
	.section	.text$_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardD1Ev,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tag,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tag
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tag;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tag
_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tag:
.LFB8513:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 104
	.seh_stackalloc	104
	lea	rbp, 96[rsp]
	.seh_setframe	rbp, 96
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	QWORD PTR 48[rbp], r8
	mov	rax, QWORD PTR 40[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	rax, QWORD PTR 48[rbp]
	mov	QWORD PTR -40[rbp], rax
	nop
	mov	rax, QWORD PTR -32[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	rax, QWORD PTR -40[rbp]
	mov	QWORD PTR -56[rbp], rax
	lea	rdx, -48[rbp]
	lea	rax, -56[rbp]
	mov	rcx, rax
	call	_ZN9__gnu_cxxmiIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSC_SF_
	nop
	nop
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	cmp	rax, 7
	jbe	.L147
	lea	rdx, -16[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r8d, 0
	mov	rcx, rax
.LEHB28:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE9_M_createERyy
.LEHE28:
	mov	rdx, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEPw
	mov	rdx, QWORD PTR -16[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE11_M_capacityEy
	jmp	.L148
.L147:
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR -8[rbp], rax
	nop
.L148:
	mov	rdx, QWORD PTR 32[rbp]
	lea	rax, -24[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardC1EPS4_
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEv
	mov	rcx, rax
	mov	rdx, QWORD PTR 48[rbp]
	mov	rax, QWORD PTR 40[rbp]
	mov	r8, rdx
	mov	rdx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvPwT_SF_
	mov	QWORD PTR -24[rbp], 0
	mov	rdx, QWORD PTR -16[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
.LEHB29:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_set_lengthEy
.LEHE29:
	lea	rax, -24[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardD1Ev
	jmp	.L151
.L150:
	mov	rbx, rax
	lea	rax, -24[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tagEN6_GuardD1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB30:
	call	_Unwind_Resume
	nop
.LEHE30:
.L151:
	add	rsp, 104
	pop	rbx
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8513:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8513-.LLSDACSB8513
.LLSDACSB8513:
	.uleb128 .LEHB28-.LFB8513
	.uleb128 .LEHE28-.LEHB28
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB29-.LFB8513
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L150-.LFB8513
	.uleb128 0
	.uleb128 .LEHB30-.LFB8513
	.uleb128 .LEHE30-.LEHB30
	.uleb128 0
	.uleb128 0
.LLSDACSE8513:
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_M_constructIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvT_SE_St20forward_iterator_tag,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZSt12__str_concatINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE,"x"
	.linkonce discard
	.globl	_ZSt12__str_concatINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE
	.def	_ZSt12__str_concatINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt12__str_concatINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE
_ZSt12__str_concatINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE:
.LFB8522:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 104
	.seh_stackalloc	104
	lea	rbp, 96[rsp]
	.seh_setframe	rbp, 96
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	QWORD PTR 48[rbp], r8
	mov	QWORD PTR 56[rbp], r9
	mov	rax, QWORD PTR 72[rbp]
	mov	QWORD PTR -8[rbp], rax
	lea	rax, -49[rbp]
	mov	rdx, QWORD PTR -8[rbp]
	mov	QWORD PTR -16[rbp], rdx
	mov	QWORD PTR -24[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR -40[rbp], rax
	mov	rax, QWORD PTR -32[rbp]
	mov	QWORD PTR -48[rbp], rax
	nop
	nop
	nop
	nop
	lea	rdx, -49[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1ERKS3_
	lea	rax, -49[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	mov	rdx, QWORD PTR 48[rbp]
	mov	rax, QWORD PTR 64[rbp]
	add	rdx, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
.LEHB31:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7reserveEy
	mov	rcx, QWORD PTR 48[rbp]
	mov	rdx, QWORD PTR 40[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r8, rcx
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKwy
	mov	rcx, QWORD PTR 64[rbp]
	mov	rdx, QWORD PTR 56[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r8, rcx
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKwy
.LEHE31:
	jmp	.L158
.L157:
	mov	rbx, rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB32:
	call	_Unwind_Resume
.LEHE32:
.L158:
	mov	rax, QWORD PTR 32[rbp]
	add	rsp, 104
	pop	rbx
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8522:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8522-.LLSDACSB8522
.LLSDACSB8522:
	.uleb128 .LEHB31-.LFB8522
	.uleb128 .LEHE31-.LEHB31
	.uleb128 .L157-.LFB8522
	.uleb128 0
	.uleb128 .LEHB32-.LFB8522
	.uleb128 .LEHE32-.LEHB32
	.uleb128 0
	.uleb128 0
.LLSDACSE8522:
	.section	.text$_ZSt12__str_concatINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZSt4moveIRNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEEONSt16remove_referenceIT_E4typeEOS8_,"x"
	.linkonce discard
	.globl	_ZSt4moveIRNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEEONSt16remove_referenceIT_E4typeEOS8_
	.def	_ZSt4moveIRNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEEONSt16remove_referenceIT_E4typeEOS8_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4moveIRNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEEONSt16remove_referenceIT_E4typeEOS8_
_ZSt4moveIRNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEEONSt16remove_referenceIT_E4typeEOS8_:
.LFB8524:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardC1EPS4_,"x"
	.linkonce discard
	.align 2
	.globl	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardC1EPS4_
	.def	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardC1EPS4_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardC1EPS4_
_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardC1EPS4_:
.LFB8553:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rax], rdx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardD1Ev
	.def	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardD1Ev
_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardD1Ev:
.LFB8556:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	je	.L164
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
.L164:
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8556:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8556-.LLSDACSB8556
.LLSDACSB8556:
.LLSDACSE8556:
	.section	.text$_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardD1Ev,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tag,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tag
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tag;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tag
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tag:
.LFB8550:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 120
	.seh_stackalloc	120
	lea	rbp, 112[rsp]
	.seh_setframe	rbp, 112
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	rbx, rdx
	mov	rax, QWORD PTR [rbx]
	mov	rdx, QWORD PTR 8[rbx]
	mov	QWORD PTR -64[rbp], rax
	mov	QWORD PTR -56[rbp], rdx
	mov	rbx, r8
	mov	rax, QWORD PTR [rbx]
	mov	rdx, QWORD PTR 8[rbx]
	mov	QWORD PTR -80[rbp], rax
	mov	QWORD PTR -72[rbp], rdx
	mov	QWORD PTR -8[rbp], 0
	mov	QWORD PTR -40[rbp], 15
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR -24[rbp], rax
	nop
	jmp	.L166
.L169:
	lea	rax, -64[rbp]
	mov	rcx, rax
.LEHB33:
	call	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEEdeEv
	mov	edx, eax
	mov	rax, QWORD PTR -8[rbp]
	lea	rcx, 1[rax]
	mov	QWORD PTR -8[rbp], rcx
	mov	rcx, QWORD PTR 32[rbp]
	mov	BYTE PTR 16[rcx+rax], dl
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv
.L166:
	lea	rdx, -80[rbp]
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZStneIcSt11char_traitsIcEEbRKSt19istreambuf_iteratorIT_T0_ES7_
.LEHE33:
	test	al, al
	je	.L167
	mov	rax, QWORD PTR -40[rbp]
	cmp	QWORD PTR -8[rbp], rax
	jnb	.L167
	mov	eax, 1
	jmp	.L168
.L167:
	mov	eax, 0
.L168:
	test	al, al
	jne	.L169
	mov	rdx, QWORD PTR 32[rbp]
	lea	rax, -48[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardC1EPS4_
	jmp	.L170
.L172:
	mov	rax, QWORD PTR -40[rbp]
	cmp	QWORD PTR -8[rbp], rax
	jne	.L171
	mov	rax, QWORD PTR -8[rbp]
	add	rax, 1
	mov	QWORD PTR -40[rbp], rax
	mov	rcx, QWORD PTR -8[rbp]
	lea	rdx, -40[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r8, rcx
	mov	rcx, rax
.LEHB34:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	mov	rdx, rax
	mov	rcx, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR -16[rbp]
	mov	r8, rcx
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcy
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	mov	rdx, QWORD PTR -16[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
	mov	rdx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy
.L171:
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEEdeEv
	mov	BYTE PTR -25[rbp], al
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	mov	rdx, rax
	mov	rax, QWORD PTR -8[rbp]
	lea	rcx, 1[rax]
	mov	QWORD PTR -8[rbp], rcx
	lea	rcx, [rdx+rax]
	lea	rax, -25[rbp]
	mov	rdx, rax
	call	_ZNSt11char_traitsIcE6assignERcRKc
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv
.L170:
	lea	rdx, -80[rbp]
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	_ZStneIcSt11char_traitsIcEEbRKSt19istreambuf_iteratorIT_T0_ES7_
	test	al, al
	jne	.L172
	mov	QWORD PTR -48[rbp], 0
	mov	rdx, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy
.LEHE34:
	lea	rax, -48[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardD1Ev
	jmp	.L175
.L174:
	mov	rbx, rax
	lea	rax, -48[rbp]
	mov	rcx, rax
	call	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tagEN6_GuardD1Ev
	mov	rax, rbx
	mov	rcx, rax
.LEHB35:
	call	_Unwind_Resume
	nop
.LEHE35:
.L175:
	add	rsp, 120
	pop	rbx
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8550:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8550-.LLSDACSB8550
.LLSDACSB8550:
	.uleb128 .LEHB33-.LFB8550
	.uleb128 .LEHE33-.LEHB33
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB34-.LFB8550
	.uleb128 .LEHE34-.LEHB34
	.uleb128 .L174-.LFB8550
	.uleb128 0
	.uleb128 .LEHB35-.LFB8550
	.uleb128 .LEHE35-.LEHB35
	.uleb128 0
	.uleb128 0
.LLSDACSE8550:
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructISt19istreambuf_iteratorIcS2_EEEvT_S8_St18input_iterator_tag,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvPwT_SF_,"x"
	.linkonce discard
	.globl	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvPwT_SF_
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvPwT_SF_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvPwT_SF_
_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsIN9__gnu_cxx17__normal_iteratorIPKcNS0_IcS1_IcESaIcEEEEEEEvPwT_SF_:
.LFB8639:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	QWORD PTR 32[rbp], r8
	jmp	.L177
.L178:
	lea	rax, 24[rbp]
	mov	rcx, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEdeEv
	movzx	eax, BYTE PTR [rax]
	cbw
	mov	WORD PTR -2[rbp], ax
	lea	rdx, -2[rbp]
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZNSt11char_traitsIwE6assignERwRKw
	lea	rax, 24[rbp]
	mov	rcx, rax
	call	_ZN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEppEv
	add	QWORD PTR 16[rbp], 2
.L177:
	lea	rdx, 32[rbp]
	lea	rax, 24[rbp]
	mov	rcx, rax
	call	_ZN9__gnu_cxxneIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEbRKNS_17__normal_iteratorIT_T0_EESE_
	test	al, al
	jne	.L178
	nop
	nop
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZStneIcSt11char_traitsIcEEbRKSt19istreambuf_iteratorIT_T0_ES7_,"x"
	.linkonce discard
	.globl	_ZStneIcSt11char_traitsIcEEbRKSt19istreambuf_iteratorIT_T0_ES7_
	.def	_ZStneIcSt11char_traitsIcEEbRKSt19istreambuf_iteratorIT_T0_ES7_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZStneIcSt11char_traitsIcEEbRKSt19istreambuf_iteratorIT_T0_ES7_
_ZStneIcSt11char_traitsIcEEbRKSt19istreambuf_iteratorIT_T0_ES7_:
.LFB8659:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	rdx, QWORD PTR 24[rbp]
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE5equalERKS2_
	xor	eax, 1
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEEdeEv
	.def	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEEdeEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEEdeEv
_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEEdeEv:
.LFB8660:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE6_M_getEv
	mov	DWORD PTR -4[rbp], eax
	lea	rax, -4[rbp]
	mov	rcx, rax
	call	_ZNSt11char_traitsIcE12to_char_typeERKi
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv
	.def	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv
_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv:
.LFB8661:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	mov	rcx, rax
	call	_ZNSt15basic_streambufIcSt11char_traitsIcEE6sbumpcEv
	call	_ZNSt11char_traitsIcE3eofEv
	mov	rdx, QWORD PTR 16[rbp]
	mov	DWORD PTR 8[rdx], eax
	mov	rax, QWORD PTR 16[rbp]
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9__gnu_cxxneIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEbRKNS_17__normal_iteratorIT_T0_EESE_,"x"
	.linkonce discard
	.globl	_ZN9__gnu_cxxneIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEbRKNS_17__normal_iteratorIT_T0_EESE_
	.def	_ZN9__gnu_cxxneIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEbRKNS_17__normal_iteratorIT_T0_EESE_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9__gnu_cxxneIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEbRKNS_17__normal_iteratorIT_T0_EESE_
_ZN9__gnu_cxxneIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEbRKNS_17__normal_iteratorIT_T0_EESE_:
.LFB8716:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 40
	.seh_stackalloc	40
	lea	rbp, 32[rsp]
	.seh_setframe	rbp, 32
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv
	mov	rbx, QWORD PTR [rax]
	mov	rax, QWORD PTR 40[rbp]
	mov	rcx, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv
	mov	rax, QWORD PTR [rax]
	cmp	rbx, rax
	setne	al
	add	rsp, 40
	pop	rbx
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEppEv
	.def	_ZN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEppEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEppEv
_ZN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEppEv:
.LFB8717:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	lea	rdx, 1[rax]
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR 16[rbp]
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEdeEv
	.def	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEdeEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEdeEv
_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEdeEv:
.LFB8718:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE5equalERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE5equalERKS2_
	.def	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE5equalERKS2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE5equalERKS2_
_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE5equalERKS2_:
.LFB8721:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 40
	.seh_stackalloc	40
	lea	rbp, 32[rsp]
	.seh_setframe	rbp, 32
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE9_M_at_eofEv
	mov	ebx, eax
	mov	rax, QWORD PTR 40[rbp]
	mov	rcx, rax
	call	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE9_M_at_eofEv
	cmp	bl, al
	sete	al
	add	rsp, 40
	pop	rbx
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE6_M_getEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE6_M_getEv
	.def	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE6_M_getEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE6_M_getEv
_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE6_M_getEv:
.LFB8722:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	eax, DWORD PTR 8[rax]
	mov	DWORD PTR -4[rbp], eax
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	je	.L194
	mov	eax, DWORD PTR -4[rbp]
	mov	ecx, eax
	call	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEE9_S_is_eofEi
	test	al, al
	je	.L194
	mov	rax, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR [rax]
	mov	rcx, rax
	call	_ZNSt15basic_streambufIcSt11char_traitsIcEE5sgetcEv
	mov	DWORD PTR -4[rbp], eax
	mov	eax, DWORD PTR -4[rbp]
	mov	ecx, eax
	call	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEE9_S_is_eofEi
	test	al, al
	je	.L194
	mov	eax, 1
	jmp	.L195
.L194:
	mov	eax, 0
.L195:
	test	al, al
	je	.L196
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR [rax], 0
.L196:
	mov	eax, DWORD PTR -4[rbp]
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9__gnu_cxxmiIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSC_SF_,"x"
	.linkonce discard
	.globl	_ZN9__gnu_cxxmiIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSC_SF_
	.def	_ZN9__gnu_cxxmiIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSC_SF_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9__gnu_cxxmiIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSC_SF_
_ZN9__gnu_cxxmiIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSC_SF_:
.LFB8743:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 40
	.seh_stackalloc	40
	lea	rbp, 32[rsp]
	.seh_setframe	rbp, 32
	.seh_endprologue
	mov	QWORD PTR 32[rbp], rcx
	mov	QWORD PTR 40[rbp], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv
	mov	rbx, QWORD PTR [rax]
	mov	rax, QWORD PTR 40[rbp]
	mov	rcx, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv
	mov	rax, QWORD PTR [rax]
	sub	rbx, rax
	mov	rdx, rbx
	mov	rax, rdx
	add	rsp, 40
	pop	rbx
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv
	.def	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv
_ZNK9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4baseEv:
.LFB8744:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE9_M_at_eofEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE9_M_at_eofEv
	.def	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE9_M_at_eofEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE9_M_at_eofEv
_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE9_M_at_eofEv:
.LFB8746:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZNKSt19istreambuf_iteratorIcSt11char_traitsIcEE6_M_getEv
	mov	ecx, eax
	call	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEE9_S_is_eofEi
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEE9_S_is_eofEi,"x"
	.linkonce discard
	.globl	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEE9_S_is_eofEi
	.def	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEE9_S_is_eofEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEE9_S_is_eofEi
_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEE9_S_is_eofEi:
.LFB8747:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	DWORD PTR 16[rbp], ecx
	mov	DWORD PTR -4[rbp], -1
	lea	rax, -4[rbp]
	mov	rdx, rax
	lea	rcx, 16[rbp]
	call	_ZNSt11char_traitsIcE11eq_int_typeERKiS2_
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB8770:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	lea	rax, _Z15currentFileNameB5cxx11[rip]
	mov	rcx, rax
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0v;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0v
_Z41__static_initialization_and_destruction_0v:
.LFB8769:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 56
	.seh_stackalloc	56
	lea	rbp, 48[rsp]
	.seh_setframe	rbp, 48
	.seh_endprologue
	lea	rax, -9[rbp]
	mov	QWORD PTR -8[rbp], rax
	nop
	nop
	lea	rax, -9[rbp]
	mov	r8, rax
	lea	rax, .LC25[rip]
	mov	rdx, rax
	lea	rax, _Z15currentFileNameB5cxx11[rip]
	mov	rcx, rax
.LEHB36:
	call	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1IS3_EEPKwRKS3_
.LEHE36:
	lea	rax, -9[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	lea	rax, __tcf_0[rip]
	mov	rcx, rax
	call	atexit
	jmp	.L210
.L209:
	mov	rbx, rax
	lea	rax, -9[rbp]
	mov	rcx, rax
	call	_ZNSt15__new_allocatorIwED2Ev
	nop
	mov	rax, rbx
	mov	rcx, rax
.LEHB37:
	call	_Unwind_Resume
	nop
.LEHE37:
.L210:
	add	rsp, 56
	pop	rbx
	pop	rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8769:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8769-.LLSDACSB8769
.LLSDACSB8769:
	.uleb128 .LEHB36-.LFB8769
	.uleb128 .LEHE36-.LEHB36
	.uleb128 .L209-.LFB8769
	.uleb128 0
	.uleb128 .LEHB37-.LFB8769
	.uleb128 .LEHE37-.LEHB37
	.uleb128 0
	.uleb128 0
.LLSDACSE8769:
	.text
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.text
	.def	_GLOBAL__sub_I_CLASS_NAME;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_CLASS_NAME
_GLOBAL__sub_I_CLASS_NAME:
.LFB8771:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	call	_Z41__static_initialization_and_destruction_0v
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_CLASS_NAME
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev1, Built by MSYS2 project) 14.2.0"
	.def	wcslen;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE3endEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5beginEv;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKwSt13_Ios_Openmode;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE7is_openEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEaSEPKw;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE4findEPKwy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEpLEPKw;	.scl	2;	.type	32;	.endef
	.def	_Znay;	.scl	2;	.type	32;	.endef
	.def	__cxa_throw_bad_array_new_length;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ofstreamIwSt11char_traitsIwEEC1EPKwSt13_Ios_Openmode;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ofstreamIwSt11char_traitsIwEE7is_openEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt13basic_ostreamIwSt11char_traitsIwEE5writeEPKwx;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ofstreamIwSt11char_traitsIwEE5closeEv;	.scl	2;	.type	32;	.endef
	.def	_ZdaPv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt14basic_ofstreamIwSt11char_traitsIwEED1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_local_dataEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS3_;	.scl	2;	.type	32;	.endef
	.def	_ZSt19__throw_logic_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13get_allocatorEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE4sizeEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKw;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1EOS4_;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt9basic_iosIcSt11char_traitsIcEE5rdbufEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE10_M_disposeEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE9_M_createERyy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEPw;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE11_M_capacityEy;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsEPwPKwS7_;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_set_lengthEy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1ERKS3_;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7reserveEy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKwy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt15basic_streambufIcSt11char_traitsIcEE6sbumpcEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt15basic_streambufIcSt11char_traitsIcEE5sgetcEv;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
