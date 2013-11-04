;=================================================================
; Memory and Constants Setup
;=================================================================
.equ STACK, 030h		; Bottom of the stack

.equ DAC, 0FE10H		; Address for DAC

.equ CNTH, 0FFh			; Delay high byte count
.equ CNTL, 0FFh			; Delay low byte count

.equ PTNADR, 1000h		; Location of the LED patternin memory

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
	lcall updPTN		; Update the LED pattern
	lcall updLED		; Update the LEDs with new pattern
	lcall delay		; Wait a bit
	sjmp loop


;=================================================================
; Subroutine init
; This routine initializes the program
;=================================================================
init:
	mov sp, #STACK		; Update stack pointer

	; Setup Serial Communication 
	mov   tmod, #022h 	; set timer 0/1 for auto reload - mode 2
	mov   tcon, #051h 	; run counter 0/1 and set edge trig ints
	mov   scon, #50h 	; set serial control reg for 8 bit data and mode 1

	mov th1, #0FDh 		; set 9600 baud with xtal=11.059mhz

	mov P1, #0FFh		; Reset P1

	clr P1.2
	lcall initMAX		; Initialize the MAX chips

	;lcall initPTN		; Init the LED Pattern
		
	lcall updLED		; Set the LED output	

ljmp main		; Start Main Program


;=================================================================
; Subroutine initMAX
; This routine initializes the MAX7219 chips
;=================================================================
initMAX:
	mov R0, #00Ch		; Shutdown register
	mov R1, #001h		; No shutdown
	lcall sndMAX
	mov R0, #00Ch		; Shutdown register
	mov R1, #001h		; No shutdown
	lcall sndMAX
	mov R0, #00Ch		; Shutdown register
	mov R1, #001h		; No shutdown
	lcall sndMAX
	mov R0, #00Ch		; Shutdown register
	mov R1, #001h		; No shutdown
	lcall sndMAX
	lcall latchMAX

	mov R0, #00Bh		; Scan mode register
	mov R1, #007h		; Scan mode all
	lcall sndMAX
	mov R0, #00Bh		; Scan mode register
	mov R1, #007h		; Scan mode all
	lcall sndMAX
	mov R0, #00Bh		; Scan mode register
	mov R1, #007h		; Scan mode all
	lcall sndMAX
	mov R0, #00Bh		; Scan mode register
	mov R1, #007h		; Scan mode all
	lcall sndMAX
	lcall latchMAX

	mov R0, #009h		; Decode mode register
	mov R1, #00h		; No decode mode
	lcall sndMAX
	mov R0, #009h		; Decode mode register
	mov R1, #00h		; No decode mode
	lcall sndMAX
	mov R0, #009h		; Decode mode register
	mov R1, #00h		; No decode mode
	lcall sndMAX
	mov R0, #009h		; Decode mode register
	mov R1, #00h		; No decode mode
	lcall sndMAX
	lcall latchMAX

	;mov R0, #00Fh		; Display test register
	;mov R1, #000h		; No display test
	;lcall sndMAX
	;lcall latchMAX

	mov R0, #00Ah		; Intensity register
	mov R1, #00Fh		; Max intensity
	lcall sndMAX
	mov R0, #00Ah		; Intensity register
	mov R1, #00Fh		; Max intensity
	lcall sndMAX
	mov R0, #00Ah		; Intensity register
	mov R1, #00Fh		; Max intensity
	lcall sndMAX
	mov R0, #00Ah		; Intensity register
	mov R1, #00Fh		; Max intensity
	lcall sndMAX
	lcall latchMAX
ret


;=================================================================
; Subroutine init
; This routine initializes the LED pattern
;=================================================================
initPTN:

ret


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
	;clr P1.2		; Enable MAX
	setb P1.2		; Latch MAX
	clr P1.2
ret


;=================================================================
; Subroutine updLED
; Updates the LEDs attached to the MAX7219 serial interface
;=================================================================
updLED:
	mov dptr, #PTNADR	; Get location of pattern
	mov R2, #008h		; Loop 8 times
updLEDLoop:
	movx a, @dptr		; Copy the first value
	mov R1, a		; Place first value into data
	mov R0, dpl		; Use table pos as address
inc R0			; Must deal with address offset
	push 002h
	push dph
	push dpl

	mov R6, 000h
	mov R7, 001h
	lcall sndMAX		; Send data out to serial

	mov R0, 006h
	mov R1, 007h
	lcall sndMAX		; Send data out to serial

	mov R0, 006h
	mov R1, 007h
	lcall sndMAX		; Send data out to serial

	mov R0, 006h
	mov R1, 007h
	lcall sndMAX		; Send data out to serial

	lcall latchMAX		; Latch serial output

	pop dpl
	pop dph
	pop 002h
	inc dptr		; Move DPTR to next address 
	djnz R2, updLEDLoop	; Loop till reach end
ret


;=================================================================
; Subroutine updPTN
; Updates the pattern stored in memory
;=================================================================
updPTN:
	mov dptr, #PTNADR	; Get location of pattern
	movx a, @dptr		; Copy the first value
	mov R0, a		; Place first value into R0

	mov R2, #007h		; Loop 7 times
updPTNLoop:
	inc dptr		; Move DPTR to next address 
	movx a, @dptr		; Copy to be copied over
	mov R1, a		; Save in R1

	mov a, R0		; Set up old value
	movx @dptr, a		; Copy old value to new potion
	mov R0, 001h		; Move new value to old value
	djnz R2, updPTNLoop		; Loop till reach end

	mov dptr, #PTNADR	; Get location of pattern
	mov a, R0		; Set up old value
	movx @dptr, a		; Copy old value to new potion
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
