;=================================================================
; Memory and Constants Setup
;=================================================================
.equ STACK, 060h		; Bottom of the stack

.equ CNTH, 001h			; Delay high byte count
.equ CNTL, 0BFh			; Delay low byte count

; FFT Values in memory
.equ fft0, 030h
.equ fft1, 031h
.equ fft2, 032h
.equ fft3, 033h
.equ fft4, 034h
.equ fft5, 035h
.equ fft6, 036h
.equ fft7, 037h
.equ fftb, 038h

; FFT sequence values in memory
.equ fftmod, 020h		; Stores the current fft mode

.equ fftbt1, 021h		; Stores the position of beat1 wave
.equ fftbt2, 022h		; Stores the position of beat2 wave

.equ fftpt0, 023h		; Stores the address for pattern0 in external mem
.equ fftpt1, 024h		; Stores the address for pattern1 in external mem
.equ fftpt2, 025h		; Stores the address for pattern2 in external mem
.equ fftpt3, 026h		; Stores the address for pattern3 in external mem

; LED Image Bufer
.equ panel0, 040h		; First byte containnig LED panel0 data 
.equ panel1, 048h		; First byte contianing LED panel1 data
.equ panel2, 050h		; First byte containing LED panel2 data
.equ panel3, 058h		; First byte containing LED panel3 data


;=================================================================
; Main program loop
;=================================================================
.org 000h			; Power up and reset vector
ljmp start
.org 003h               	; interrupt 0 vector
ljmp updfft


.org 100h
start:
	ljmp init		; Initialize program

main:
	lcall getchr		; Get the next char. could start fft sequence 
	;lcall sndchr
	;cjne R0, #0FFh, main	; Loop until recieve FFh
	;lcall rcvFFT		; Read FFT values from serial and store in memory

	; Choose fft scheme based on current fft mode, then run sequence
	;mov R0, fftmod		; Mov fftmod into R0	
	;cjne R0, #000h, skip1	
	;lcall fftseq_bars		; Run FFT Bars Sequence
	sjmp loop
skip1:
	cjne R0, #001h, skip2
	lcall fftseq_beats		; Run FFT Beat Sequence
	sjmp loop
skip2:
	lcall fftseq_pattern		; Run FFT Pattern Sequence

loop:
	lcall updLED			; Push pattern out to LEDs
	;lcall delay			; Delay so that pattern frame is seen
	sjmp main


;=================================================================
; Subroutine init
; This routine initializes the program
;=================================================================
init:
	mov sp, #STACK		; Update stack pointer
	
	; Setup Interrupts for Sintab
	; Setup Serial Communication 
	mov   tmod, #022h 	; set timer 1/2 for auto reload - mode 2
	mov   tcon, #051h 	; run counter 1/0 and set edge trig ints
	mov   scon, #50h 	; set serial control reg for 8 bit data and mode 1

	mov th1, #0FDh 		; set 9600 baud with xtal=11.059mhz
	mov th0,  #04Ch		; set for 5120 interrupts per sec

	lcall initfft		; Init all fft params
	clr P1.2
	lcall initMAX		; Initialize the MAX chips
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
; Subroutine initFFT
; This subroutine inits all fft params
;=================================================================
initfft:
	mov fftmod, #000h	; Reset the fft mode register
ret


;=================================================================
; Subroutine initFFTseq_bars
; This subroutine inits all fft seq params
;=================================================================
initfftseq_bars:
	; Nothing to do here
ret


;=================================================================
; Subroutine initFFTseq_beats
; This subroutine inits all fft seq params
;=================================================================
initfftseq_beats:
ret


;=================================================================
; Subroutine initFFTseq_pattern
; This subroutine inits all fft seq params
;=================================================================
initfftseq_pattern:
ret


;=================================================================
; Subroutine updfft
; Reads in values for amulet and updates fft controller  
;=================================================================
updFFT:
	push 000h
	mov dptr, #0FE20h	; Read in a byte from the receiver buffer register
	movx a, @dptr
	pop 000h
reti


;=================================================================
; Subroutine updfft
; Reads in values for amulet and updates fft controller  
;=================================================================
rcvFFT:
	lcall getchr		; Get fft0
	mov fft0, R0
	lcall getchr		; Get fft1
	mov fft1, R0
	lcall getchr		; Get fft2
	mov fft2, R0
	lcall getchr		; get fft3
	mov fft3, R0
	lcall getchr		; get fft4
	mov fft4, R0
	lcall getchr		; get fft5
	mov fft5, R0
	lcall getchr		; get fft6
	mov fft6, R0
	lcall getchr		; get fft7
	mov fft7, R0
	lcall getchr		; get fftb
	mov fftb, R0
ret


;=================================================================
; Subroutine cvt_fft_to_bar:
; Converts fft value to bar value
;=================================================================
cvt_fft_to_bar_low:
	mov a, R0		; Move fft val into a
	mov b, #010h		; Move 16 into b
	div ab			; Divide by 16
	;mov a,b		; Place low result in a
	lcall val_to_bar_low	; Convert to bar val
	mov R0, a		; Place result in R0
ret


;=================================================================
; Subroutine cvt_fft_to_bar:
; Converts fft value to bar value
;=================================================================
cvt_fft_to_bar_high:
	mov a, R0		; Move fft val into a
	mov b, #010h		; Move 16 into b
	div ab			; Divide by 16
	;mov a, b		; Place low result in a
	lcall val_to_bar_high	; Convert to bar val
	mov R0, a		; Place result in R0
ret


;=================================================================
; Subroutine fftseq_bars:
; Sequences lights with fft bar pattern
;=================================================================
fftseq_bars:
	; Panel0
	mov R0, fft0
	lcall cvt_fft_to_bar_high
	mov 040h, R0
	mov 041h, R0
	mov R0, fft2
	lcall cvt_fft_to_bar_high
	mov 042h, R0
	mov 043h, R0
	mov R0, fft2
	lcall cvt_fft_to_bar_high
	mov 044h, R0
	mov 045h, R0
	mov R0, fft3
	lcall cvt_fft_to_bar_high
	mov 046h, R0
	mov 047h, R0

	; Panel1
	mov R0, fft0
	lcall cvt_fft_to_bar_low
	mov 048h, R0
	mov 049h, R0
	mov R0, fft1
	lcall cvt_fft_to_bar_low
	mov 04Ah, R0
	mov 04Bh, R0
	mov R0, fft2
	lcall cvt_fft_to_bar_low
	mov 04Ch, R0
	mov 04Dh, R0
	mov R0, fft3
	lcall cvt_fft_to_bar_low
	mov 04Eh, R0
	mov 04Fh, R0

	; Panel2
	mov R0, fft4
	lcall cvt_fft_to_bar_high
	mov 050h, R0
	mov 051h, R0
	mov R0, fft5
	lcall cvt_fft_to_bar_high
	mov 052h, R0
	mov 053h, R0
	mov R0, fft6
	lcall cvt_fft_to_bar_high
	mov 054h, R0
	mov 055h, R0
	mov R0, fft7
	lcall cvt_fft_to_bar_high
	mov 056h, R0
	mov 057h, R0

	; Panel3
	mov R0, fft4
	lcall cvt_fft_to_bar_low
	mov 058h, R0
	mov 059h, R0
	mov R0, fft5
	lcall cvt_fft_to_bar_low
	mov 05Ah, R0
	mov 05Bh, R0
	mov R0, fft6
	lcall cvt_fft_to_bar_low
	mov 05Ch, R0
	mov 05Dh, R0
	mov R0, fft7
	lcall cvt_fft_to_bar_low
	mov 05Eh, R0
	mov 05Fh, R0
ret


;=================================================================
; Subroutine fftseq_beats
; Sequences lights with beat wave pattern
;=================================================================
fftseq_beats:
ret


;=================================================================
; Subroutine fftseq_pattern
; Sequences lights with beat triggered pattern shifting
;=================================================================
fftseq_pattern:
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
	mov R7, #008h		; Use R7 as countdown, loop 8 times
	mov R6, #007h
updLEDLoop:
	mov a, #panel0		; Get locaiton of pattern 0	
	push 006h
	add a, R6		; Add location offset
	pop 006h
	mov R0, a		; Move into R0 for indirect address
	mov a, @R0		; Get data from memory
	mov R1, 007h		; Place value into R1
	mov R0, 007h		; Use table pos as address
	lcall sndMAX		; Send data out to serial

	mov a, #panel1		; Get locaiton of pattern 0	
	push 006h
	add a, R6		; Add location offset
	pop 006h
	mov R0, a		; Move into R0 for indirect address
	mov a, @R0		; Get data from memory
	mov R1, 007h		; Place value into R1
	mov R0, 007h		; Use table pos as address
	lcall sndMAX		; Send data out to serial

	mov a, #panel2		; Get locaiton of pattern 0	
	push 006h
	add a, R6		; Add location offset
	pop 006h
	mov R0, a		; Move into R0 for indirect address
	mov a, @R0		; Get data from memory
	mov R1, 007h		; Place value into R1
	mov R0, 007h		; Use table pos as address
	lcall sndMAX		; Send data out to serial

	mov a, #panel3		; Get locaiton of pattern 0	
	push 006h
	add a, R6		; Add location offset
	pop 006h
	mov R0, a		; Move into R0 for indirect address
	mov a, @R0		; Get data from memory
	mov R1, 007h		; Place value into R1
	mov R0, 007h		; Use table pos as address
	lcall sndMAX		; Send data out to serial

	lcall latchMAX		; Latch values into MAX

	dec R6
	djnz R7, updLEDLoop	; Loop till reach end
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
	;mov a,  sbuf		; get character
	;anl a,  #7Fh		; mask off 8th bit
	;mov R0, a		; Move a into R0 for return
	mov R0, sbuf		; Move character into R0
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


;===============================================================
; subroutine getbyt
; this routine reads in an 2 digit ascii hex number from the
; serial port. the result is returned in the R0.
;===============================================================
getbyt:
	lcall getchr           ; get msb ascii chr
	mov a, R0
	lcall ascbin           ; conv it to binary
	swap  a                ; move to most sig half of acc
	mov   b,  a            ; save in b
	lcall getchr           ; get lsb ascii chr
	mov a, R0
	lcall ascbin           ; conv it to binary
	orl   a,  b            ; combine two halves
	mov R0, a
ret


;===============================================================
; subroutine ascbin
; this routine takes the ascii character passed to it in the
; acc and converts it to a 4 bit binary number which is returned
; in the acc.
;===============================================================
ascbin:
	;clr   errorf
	add   a,  #0d0h        ; if chr < 30 then error
	jnc   notnum
	clr   c                ; check if chr is 0-9
	add   a,  #0f6h        ; adjust it
	jc    hextry           ; jmp if chr not 0-9
	add   a,  #0ah         ; if it is then adjust it
ret
hextry:
	clr   acc.5            ; convert to upper
	clr   c                ; check if chr is a-f
	add   a,  #0f9h        ; adjust it
	jnc   notnum           ; if not a-f then error
	clr   c                ; see if char is 46 or less.
	add   a,  #0fah        ; adjust acc
	jc    notnum           ; if carry then not hex
	anl   a,  #0fh         ; clear unused bits
ret
notnum:
	;setb  errorf           ; if not a valid digit
	;ljmp  endloop


;=================================================================
; This routine serves as a lookup table for the sin wave values
; Place the sin tab address in ACC, then call
; this function to have the val_to_bar_low value placed in the ACC
;=================================================================
val_to_bar_low:
	inc a
	movc a, @a+pc
	ret
	.db 00000001b		; 0
	.db 00000011b		; 1
	.db 00000111b		; 2
	.db 00001111b		; 3
	.db 00011111b		; 4
	.db 00111111b		; 5
	.db 01111111b		; 6
	.db 11111111b		; 7
	.db 11111111b		; 8
	.db 11111111b		; 9
	.db 11111111b		; 10
	.db 11111111b		; 11
	.db 11111111b		; 12
	.db 11111111b		; 13
	.db 11111111b		; 14
	.db 11111111b		; 15


;=================================================================
; This routine serves as a lookup table for the sin wave values
; Place the sin tab address in ACC, then call
; this function to have the val_to_bar_high value placed in the ACC
;=================================================================
val_to_bar_high:
	inc a
	movc a, @a+pc
	ret
	.db 00000000b		; 0
	.db 00000000b		; 1
	.db 00000000b		; 2
	.db 00000000b		; 3
	.db 00000000b		; 4
	.db 00000000b		; 5
	.db 00000000b		; 6
	.db 00000000b		; 7
	.db 00000001b		; 8
	.db 00000011b		; 9
	.db 00000111b		; 10
	.db 00001111b		; 11
	.db 00011111b		; 12
	.db 00111111b		; 13
	.db 01111111b		; 14
	.db 11111111b		; 15


.end
