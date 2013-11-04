;=================================================================
; Memory and Constants Setup
;=================================================================
.equ STACK, 040h		; Bottom of the stack

.equ CNTH, 020h			; Delay high byte count
.equ CNTL, 0FFh			; Delay low byte count

.equ CNTHMAX, 001h
.equ CNTLMAX, 040h

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

.equ fftptp, 021h		; Stores the pointer for the current pattern
.equ ptpaddrH, 022h		; Address fo current pattern
.equ ptpaddrL, 023h		; Address fo current pattern

.equ fftptH, 041h
.equ fftpt0, 000h		; Stores the address for pattern0 in external mem
.equ fftpt1, 008h		; Stores the address for pattern1 in external mem
.equ fftpt2, 010h		; Stores the address for pattern2 in external mem
.equ fftpt3, 018h		; Stores the address for pattern3 in external mem


; LED Image Bufer
.equ panel00, 4000h		; First byte containnig LED panel0 data 
.equ panel01, 4001h		; First byte containnig LED panel0 data 
.equ panel02, 4002h		; First byte containnig LED panel0 data 
.equ panel03, 4003h		; First byte containnig LED panel0 data 
.equ panel04, 4004h		; First byte containnig LED panel0 data 
.equ panel05, 4005h		; First byte containnig LED panel0 data 
.equ panel06, 4006h		; First byte containnig LED panel0 data 
.equ panel07, 4007h		; First byte containnig LED panel0 data 

.equ PTNADR, 4000h		; Location of the LED pattern in memory


;=================================================================
; Main program loop
;=================================================================
.org 000h			; Power up and reset vector
ljmp start


.org 100h
start:
	ljmp init		; Initialize program

main:
	lcall getchr		; Get the next char. could start fft sequence 
	lcall sndchr
	cjne R0, #0FFh, main	; Loop until recieve FFh
	lcall rcvFFT		; Read FFT values from serial and store in memory
	lcall checkMode		; Chedks to see if fftmode has changed

	; Choose fft scheme based on current fft mode, then run sequence
	mov R0, fftmod		; Mov fftmod into R0	
	cjne R0, #000h, skip1	
	lcall fftseq_bars		; Run FFT Bars Sequence
	lcall updLED			; Push pattern out to LEDs
	sjmp loop

skip1:
	cjne R0, #001h, skip2
	lcall fftseq_beats		; Run FFT Beat Sequence
	sjmp loop

skip2:
	lcall fftseq_pattern		; Run FFT Pattern Sequence

loop:
	sjmp main


;=================================================================
; Subroutine init
; This routine initializes the program
;=================================================================
init:
	mov sp, #STACK		; Update stack pointer
	
	; Setup Interrupts for Sintab
	; Setup Serial Communication 
	mov   tmod, #020h 	; set timer 1/2 for auto reload - mode 2
	mov   tcon, #041h 	; run counter 1/0 and set edge trig ints
	mov   scon, #50h 	; set serial control reg for 8 bit data and mode 1

	mov th1, #0FDh 		; set 9600 baud with xtal=11.059mhz

	lcall initfft		; Init all fft params
	;clr P1.2
	lcall initMAX		; Initialize the MAX chips
ljmp main		; Start Main Program}}}


;=================================================================
; Subroutine initMAX
; This routine initializes the MAX7219 chips
;=================================================================
initMAX:
	mov R0, #00Ch		; Shutdown register
	mov R1, #001h		; No shutdown
	lcall sndMAX
	lcall latchMAX

	mov R0, #00Bh		; Scan mode register
	mov R1, #007h		; Scan mode all
	lcall sndMAX
	lcall latchMAX

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
	lcall latchMAX
ret


;=================================================================
; Subroutine initFFT
; This subroutine inits all fft params
;=================================================================
initfft:
	mov fftmod, #001h	; Reset the fft mode register
	lcall initfftseq_pattern ;setup this pointer in mem
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
	mov a, #0FFh
	mov dptr, #panel00
	movx @dptr, a
	mov a, #000h
	mov dptr, #panel01
	movx @dptr, a
	mov dptr, #panel02
	movx @dptr, a
	mov dptr, #panel03
	movx @dptr, a
	mov dptr, #panel04
	movx @dptr, a
	mov dptr, #panel05
	movx @dptr, a
	mov dptr, #panel06
	movx @dptr, a
	mov dptr, #panel07
	movx @dptr, a
ret


;=================================================================
; Subroutine initFFTseq_pattern
; This subroutine inits all fft seq params
;=================================================================
initfftseq_pattern:
	mov fftptp, #011h		; Init the pointer
ret


;=================================================================
; subroutine checkMode
; reads in values for amulet and updates fft controller  
; 07h = fftbars
; 06h = fftbeat
; 05h = fftpattern
;=================================================================
checkMode:
	mov R0, fftb
	cjne R0, #017h, checkSkip1
	lcall initfftseq_bars
	mov fftmod, #000h			; Set new fft mode
	sjmp checkModeEnd	
checkSkip1:
	cjne R0, #016h, checkSkip2
	lcall initfftseq_beats
	mov fftmod, #001h			; Set new fft mode
	sjmp checkModeEnd
checkSkip2:
	cjne R0, #015h, checkModeEnd
	lcall initfftseq_pattern
	mov fftmod, #002h			; Set new FTT mode
	sjmp checkModeEnd	
checkModeEnd:
ret


;=================================================================
; subroutine updfft
; reads in values for amulet and updates fft controller  
;=================================================================
updFFT:
	push 000h
	mov dptr, #0FE20h	; Read in a byte from the receiver buffer register
	movx a, @dptr
	pop 000h
ret


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
cvt_fft_to_bar:
	mov a, R0		; Move fft val into a
	mov b, #020h		; Move 16 into b
	div ab			; Divide by 16
	;mov a,b		; Place low result in a
	lcall val_to_bar	; Convert to bar val
	mov R0, a		; Place result in R0
ret


;=================================================================
; Subroutine fftseq_bars:
; Sequences lights with fft bar pattern
;=================================================================
fftseq_bars:
	mov R0, fft0
	lcall cvt_fft_to_bar
	mov dptr, #panel00
	mov a, R0
	movx @dptr, a
	mov R0, fft1
	lcall cvt_fft_to_bar
	mov dptr, #panel01
	mov a, R0
	movx @dptr, a
	mov R0, fft2
	lcall cvt_fft_to_bar
	mov dptr, #panel02
	mov a, R0
	movx @dptr, a
	mov R0, fft3
	lcall cvt_fft_to_bar
	mov dptr, #panel03
	mov a, R0
	movx @dptr, a
	mov R0, fft4
	lcall cvt_fft_to_bar
	mov dptr, #panel04
	mov a, R0
	movx @dptr, a
	mov R0, fft5
	lcall cvt_fft_to_bar
	mov dptr, #panel05
	mov a, R0
	movx @dptr, a
	mov R0, fft6
	lcall cvt_fft_to_bar
	mov dptr, #panel06
	mov a, R0
	movx @dptr, a
	mov R0, fft7
	lcall cvt_fft_to_bar
	mov dptr, #panel07
	mov a, R0
	movx @dptr, a
ret


;=================================================================
; Subroutine fftseq_beats
; Sequences lights with beat wave pattern
;=================================================================
fftseq_beats:
	mov R0, fftb
	cjne R0, #001h, no_beats	; If there is no beat, skip

	lcall initfftseq_beats		; Clear the display for values
	lcall updLED			; Update the display

	; Move 1	
	;lcall getchr
	lcall delay			; Wait or timeout
	lcall updPTN			; Advance pattern
	lcall updLED			; Update display
	; Move 2	
	;lcall getchr
	lcall delay			; Wait or timeout
	lcall updPTN			; Advance pattern
	lcall updLED			; Update display
	; Move 3	
	;lcall getchr
	lcall delay			; Wait or timeout
	lcall updPTN			; Advance pattern
	lcall updLED			; Update display
	; Move 4	
	;lcall getchr
	lcall delay			; Wait or timeout
	lcall updPTN			; Advance pattern
	lcall updLED			; Update display
	; Move 5
	;lcall getchr
	lcall delay			; Wait or timeout
	lcall updPTN			; Advance pattern
	lcall updLED			; Update display
	; Move 6
	;lcall getchr
	lcall delay			; Wait or timeout
	lcall updPTN			; Advance pattern
	lcall updLED			; Update display
	; Move 7
	;lcall getchr
	lcall delay			; Wait or timeout
	lcall updPTN			; Advance pattern
	lcall updLED			; Update display

no_beats:
ret


;=================================================================
; subroutine fftseq_pattern
; sequences lights with beat triggered pattern shifting
;=================================================================
fftseq_pattern:
	mov R0, fftb
	;cjne fftb, #001h, no_pattern	; If there is no beat, skip

	jb fftptp.0, pattern1		; Play pattern 1
	jb fftptp.1, pattern2		; Play pattern 2
	jb fftptp.2, pattern3		; Play pattern 3
	jb fftptp.3, pattern4		; Play pattern 4
	sjmp no_pattern			; There is no pattern, so end

pattern1:
	mov ptpaddrH, #fftptH
	mov ptpaddrL, #fftpt0
ljmp no_pattern				; We are finished, so leave
	
pattern2:
	mov ptpaddrH, #fftptH
	mov ptpaddrL, #fftpt1
ljmp no_pattern				; We are finished, so leave
		
pattern3:
	mov ptpaddrH, #fftptH
	mov ptpaddrL, #fftpt2
ljmp no_pattern				; We are finished, so leave

pattern4:
	mov ptpaddrH, #fftptH
	mov ptpaddrL, #fftpt3
ljmp no_pattern				; We are finished, so leave

no_pattern:
ret


;=================================================================
; Subroutine updLED
; Updates the LEDs attached to the MAX7219 serial interface
;=================================================================
updLEDPtn:
	mov dph, ptpaddrH 	; Get location of pattern
	mov dpl, ptpaddrL 	; Get location of pattern
	mov R7, #008h		; Loop 7 times
	mov R6, #001h		; Address for MAX

updLEDPtnLoop:
	movx a, @dptr		; Copy the first value
	mov R1, a		; Place first value into R0
	mov R0, 006h		; Address
	lcall sndMAX		; Send to MAX
	lcall latchMax		; Latch the values

	inc dptr		; Move DPTR to next address 
	inc R6
	djnz R7, updLEDPTnLoop	; loop till finished
ret


;=================================================================
; Subroutine updLED
; Updates the LEDs attached to the MAX7219 serial interface
;=================================================================
updLED:
	mov dptr, #panel00
	movx a, @dptr
	mov R1, a
	mov R0, #001h
	lcall sndmax
	lcall latchMAX
	
	mov dptr, #panel01
	movx a, @dptr
	mov R1, a
	mov R0, #002h
	lcall sndmax
	lcall latchMAX
	
	mov dptr, #panel02
	movx a, @dptr
	mov R1, a
	mov R0, #003h
	lcall sndmax
	lcall latchMAX

	mov dptr, #panel03
	movx a, @dptr
	mov R1, a
	mov R0, #004h
	lcall sndmax
	lcall latchMAX

	mov dptr, #panel04
	movx a, @dptr
	mov R1, a
	mov R0, #005h
	lcall sndmax
	lcall latchMAX

	mov dptr, #panel05
	movx a, @dptr
	mov R1, a
	mov R0, #006h
	lcall sndmax
	lcall latchMAX

	mov dptr, #panel06
	movx a, @dptr
	mov R1, a
	mov R0, #007h
	lcall sndmax
	lcall latchMAX

	mov dptr, #panel07
	movx a, @dptr
	mov R1, a
	mov R0, #008h
	lcall sndmax
	lcall latchMAX
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
	clr P1.2		; Enable MAX
	setb P1.2		; Latch MAX
	;clr P1.2
	lcall delayMAX
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
; Subroutine delay
; This routine delays for some time
;=================================================================
delay:
	; load R0 and R1 with 255
	mov R0, #CNTH
	mov R1, #CNTL

	loop_internal:
		djnz R1, loop_internal	; decrement R1  

	mov R1, #CNTL	; reload R1 in case we need to loop again.
	djnz R0, loop_internal; decrement R0
ret


;=================================================================
; Subroutine delay
; This routine delays for some time
;=================================================================
delayMAX:
	; load R0 and R1 with 255
	mov R0, #CNTHMAX
	mov R1, #CNTLMAX

	loop_internal_max:
		djnz R1, loop_internal_max	; decrement R1  

	mov R1, #CNTLMAX	; reload R1 in case we need to loop again.
	djnz R0, loop_internal_max; decrement R0
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
	mov R0, sbuf
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


;=================================================================
; This routine serves as a lookup table for the sin wave values
; Place the sin tab address in ACC, then call
; this function to have the val_to_bar_low value placed in the ACC
;=================================================================
val_to_bar:
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


.end
