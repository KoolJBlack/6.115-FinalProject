;=================================================================
; Memory and Constants Setup
;=================================================================
.equ STACK, 030h		; Bottom of the stack

.equ DAC, 0FE10H		; Address for DAC

.equ CNTH, 001H			; Delay high byte count
.equ CNTL, 0BFH			; Delay low byte count



;=================================================================
; Main program loop
;=================================================================
.org 000h			; Power up and reset vector
ljmp start


.org 100h
start:
	ljmp init		; Initialize program

main:

loop:
	sjmp loop


;=================================================================
; Subroutine init
; This routine initializes the program
;=================================================================
init:
	mov sp, #STACK		; Update stack pointer
	mov P1, #0FFh		; Reset P1
	
	lcall updLED		; Set the LED output	

ljmp main		; Start Main Program


;=================================================================
; Subroutine putbyte
; sends a byte out to the MAX7219 serial interface. Place byte
; to send in R0.
;=================================================================
putByte:
	mov a, R0		; Move byte to acc
	mov R1, #008h		; We send 8 bits per byte

putByteLoop:
	clr P1.1		; Set CLK low
	jnb acc.7, putByteLow	; If acc.7 is set, send a high,
				; else, send a low out DIn
	setb P1.0		; Set DIn high
	sjmp putByteEnd
putByteLow:
	clr P1.0		; Set DIn low
	setb P1.1		; Set CLK high

putByteEnd:
	setb P1.1		; Set CLK high
	rl a			; Rotate acc to get to lesser bit
	djnz R1, putByteLoop	; Loop till we've sent all bits
ret


;=================================================================
; Subroutine sndMAX
; sends a data out to the MAX7219 serial interface. Place Aaddres
; in R0 and data in R1
;=================================================================
sndMAX:
	push 001h		; Push R1
	lcall putByte		; Send Address
	pop 000h		; Pop R1 into R0
	lcall putByte		; Send data
ret


;=================================================================
; Subroutine latchMAX
; latches the serial data into the MAX7219
;=================================================================
latchMAX:
	clr P1.2		; Enable MAX
	setb P1.2		; Latch MAX
ret

;=================================================================
; Subroutine updLED
; Updates the LEDs attached to the MAX7219 serial interface
;=================================================================
updLED:
	mov R0, #0FFh		; Address Display Test
	mov R1, #0FFh		; Turn on Display Test
	lcall sndMAX		; Send data out to serial
	lcall latchMAX
ret


;=================================================================
; Subroutine setDAC
; Sets the DAC value from R)
;=================================================================
setDAC:
	mov dptr, #DAC		; Address for the DAC
	mov a, R0
	movx @dptr, a		; Write value to DAC
ret


;=================================================================
; Subroutine delay
; This routine delays for some time
;=================================================================
delay:
	; load R0 and R1 with 255
	mov R0, #CNTH
	mov R1, #CNTL

	loop_internal:
		djnz R1, loop_internal	; decrement R1  

	mov R1, CNTL	; reload R1 in case we need to loop again.
	djnz R0, loop_internal; decrement R0
ret


;===============================================================
; Subroutine sndchr
; This routine takes the chr in the R0 and sends it out the
; serial port.
;===============================================================
sndchr:
	clr  scon.1		; clear the tx  buffer full flag.
	mov  sbuf,R0		; put chr in sbuf
txloop:
    	jnb  scon.1, txloop 	; wait till chr is sent
ret


;===============================================================
; Subroutine getchr
; This routine reads in a chr from the serial port and saves it
; in the R0.
;===============================================================
getchr:
	jnb ri, getchr		; wait till character received
	mov a,  sbuf		; get character
	anl a,  #7Fh		; mask off 8th bit
	mov R0, a		; Move a into R0 for return
	clr ri			; clear serial status bit
ret


;===============================================================
; Subroutine crlf
; crlf sends a carriage return line feed out the serial port
;===============================================================
crlf:
	mov   R0,  #0Ah		; print lf
	lcall sndchr
	cret:
	mov   R0,  #0Dh		; print cr
	lcall sndchr
ret


;===============================================================
; Subroutine prthex
; This routine takes the contents of the R0 and prints it out
; as a 2 digit ascii hex number.
;===============================================================
prthex:
	mov a, R0
	push acc
	lcall binasc           ; convert acc to ascii
	mov R0, a
	lcall sndchr           ; print first ascii hex digit
	mov R0,  002h          ; get second ascii hex digit
	lcall sndchr           ; print it
	pop acc
ret


;===============================================================
; Subroutine binasc
; binasc takes the contents of the accumulator and converts it
; into two ascii hex numbers.  the result is returned in the
; accumulator and r2.
;===============================================================
binasc:
	mov   r2, a            ; save in r2
	anl   a,  #0fh         ; convert least sig digit.
	add   a,  #0f6h        ; adjust it
	jnc   noadj1           ; if a-f then readjust
	add   a,  #07h
noadj1:
	add   a,  #3ah         ; make ascii
	xch   a,  r2           ; put result in reg 2
	swap  a                ; convert most sig digit
	anl   a,  #0fh         ; look at least sig half of acc
	add   a,  #0f6h        ; adjust it
	jnc   noadj2           ; if a-f then re-adjust
	add   a,  #07h
noadj2:
	add   a,  #3ah         ; make ascii
ret


.end
