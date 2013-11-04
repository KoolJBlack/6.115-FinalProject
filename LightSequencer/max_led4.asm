;=================================================================
; Memory and Constants Setup
;=================================================================
.equ STACK, 040h		; Bottom of the stack

.equ CNTH, 001h			; Delay high byte count
.equ CNTL, 040h			; Delay low byte count

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
.equ panel00, 4000h		; First byte containnig LED panel0 data 
.equ panel01, 4001h		; First byte containnig LED panel0 data 
.equ panel02, 4002h		; First byte containnig LED panel0 data 
.equ panel03, 4003h		; First byte containnig LED panel0 data 
.equ panel04, 4004h		; First byte containnig LED panel0 data 
.equ panel05, 4005h		; First byte containnig LED panel0 data 
.equ panel06, 4006h		; First byte containnig LED panel0 data 
.equ panel07, 4007h		; First byte containnig LED panel0 data 

.equ panel10, 4008h		; First byte contianing LED panel1 data
.equ panel11, 4009h		; First byte contianing LED panel1 data
.equ panel12, 400Ah		; First byte contianing LED panel1 data
.equ panel13, 400Bh		; First byte contianing LED panel1 data
.equ panel14, 400Ch		; First byte contianing LED panel1 data
.equ panel15, 400Dh		; First byte contianing LED panel1 data
.equ panel16, 400Eh		; First byte contianing LED panel1 data
.equ panel17, 400Fh		; First byte contianing LED panel1 data

.equ panel20, 4010h		; First byte containing LED panel2 data
.equ panel21, 4011h		; First byte containing LED panel2 data
.equ panel22, 4012h		; First byte containing LED panel2 data
.equ panel23, 4013h		; First byte containing LED panel2 data
.equ panel24, 4014h		; First byte containing LED panel2 data
.equ panel25, 4015h		; First byte containing LED panel2 data
.equ panel26, 4016h		; First byte containing LED panel2 data
.equ panel27, 4017h		; First byte containing LED panel2 data

.equ panel30, 4018h		; First byte containing LED panel3 data
.equ panel31, 4019h		; First byte containing LED panel3 data
.equ panel32, 401Ah		; First byte containing LED panel3 data
.equ panel33, 401Bh		; First byte containing LED panel3 data
.equ panel34, 401Ch		; First byte containing LED panel3 data
.equ panel35, 401Dh		; First byte containing LED panel3 data
.equ panel36, 401Eh		; First byte containing LED panel3 data
.equ panel37, 401Fh		; First byte containing LED panel3 data


.equ PTNADR, 4000h		; Location of the LED patternin memory


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
	;cjne R0, #0FFh, main	; Loop until recieve FFh
	;cjne R0, #'j', main	; Loop until recieve FFh
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
	;lcall updPTN
	;lcall updLED			; Push pattern out to LEDs
	;lcall delay			; Delay so that pattern frame is seen
	sjmp main

;.org 100h
;start:
	;ljmp init		; Initialize program

;main:

;loop:
	;lcall updPTN		; Update the LED pattern
	;lcall getchr

	;lcall updLED2		; Update the LEDs with new pattern
	;lcall delay		; Wait a bit
	;sjmp loop


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

	;lcall initfft		; Init all fft params
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

	mov R0, #00Fh		; Display test register
	mov R1, #000h		; No display test
	lcall sndMAX
	mov R0, #00Fh		; Display test register
	mov R1, #000h		; No display test
	lcall sndMAX
	mov R0, #00Fh		; Display test register
	mov R1, #000h		; No display test
	lcall sndMAX
	mov R0, #00Fh		; Display test register
	mov R1, #000h		; No display test
	lcall sndMAX
	lcall latchMAX

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
	mov R0, #011h
ret
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
	mov R0, #088h
ret
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
	mov a, R0
	mov dptr, #panel00
	movx @dptr, a
	mov dptr, #panel01
	movx @dptr, a

	mov R0, fft1
	lcall cvt_fft_to_bar_high
	mov a, R0
	mov dptr, #panel02
	movx @dptr, a
	mov dptr, #panel03
	movx @dptr, a

	mov R0, fft2
	lcall cvt_fft_to_bar_high
	mov a, R0
	mov dptr, #panel04
	movx @dptr, a
	mov dptr, #panel05
	movx @dptr, a

	mov R0, fft3
	lcall cvt_fft_to_bar_high
	mov a, R0
	mov dptr, #panel06
	movx @dptr, a
	mov dptr, #panel07
	movx @dptr, a

	; Panel1
	mov R0, fft0
	lcall cvt_fft_to_bar_low
	mov a, R0
	mov dptr, #panel10
	movx @dptr, a
	mov dptr, #panel11
	movx @dptr, a

	mov R0, fft1
	lcall cvt_fft_to_bar_low
	mov a, R0
	mov dptr, #panel12
	movx @dptr, a
	mov dptr, #panel13
	movx @dptr, a

	mov R0, fft2
	lcall cvt_fft_to_bar_low
	mov a, R0
	mov dptr, #panel14
	movx @dptr, a
	mov dptr, #panel15
	movx @dptr, a

	mov R0, fft3
	lcall cvt_fft_to_bar_low
	mov a, R0
	mov dptr, #panel16
	movx @dptr, a
	mov dptr, #panel17
	movx @dptr, a

	; Panel2
	mov R0, fft4
	lcall cvt_fft_to_bar_high
	mov a, R0
	mov dptr, #panel20
	movx @dptr, a
	mov dptr, #panel21
	movx @dptr, a

	mov R0, fft5
	lcall cvt_fft_to_bar_high
	mov a, R0
	mov dptr, #panel22
	movx @dptr, a
	mov dptr, #panel23
	movx @dptr, a

	mov R0, fft6
	lcall cvt_fft_to_bar_high
	mov a, R0
	mov dptr, #panel24
	movx @dptr, a
	mov dptr, #panel25
	movx @dptr, a

	mov R0, fft7
	lcall cvt_fft_to_bar_high
	mov a, R0
	mov dptr, #panel26
	movx @dptr, a
	mov dptr, #panel27
	movx @dptr, a

	; Panel3
	mov R0, fft4
	lcall cvt_fft_to_bar_low
	mov a, R0
	mov dptr, #panel30
	movx @dptr, a
	mov dptr, #panel31
	movx @dptr, a

	mov R0, fft5
	lcall cvt_fft_to_bar_low
	mov a, R0
	mov dptr, #panel32
	movx @dptr, a
	mov dptr, #panel33
	movx @dptr, a

	mov R0, fft6
	lcall cvt_fft_to_bar_low
	mov a, R0
	mov dptr, #panel34
	movx @dptr, a
	mov dptr, #panel35
	movx @dptr, a

	mov R0, fft7
	lcall cvt_fft_to_bar_low
	mov a, R0
	mov dptr, #panel36
	movx @dptr, a
	mov dptr, #panel37
	movx @dptr, a
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
	clr P1.2		; Enable MAX
	setb P1.2		; Latch MAX
	;clr P1.2
	lcall delay
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
	mov dptr, #panel10
	movx a, @dptr
	mov R1, a
	mov R0, #001h
	lcall sndmax
	mov dptr, #panel20
	movx a, @dptr
	mov R1, a
	mov R0, #001h
	lcall sndmax
	mov dptr, #panel30
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
	mov dptr, #panel11
	movx a, @dptr
	mov R1, a
	mov R0, #002h
	lcall sndmax
	mov dptr, #panel21
	movx a, @dptr
	mov R1, a
	mov R0, #002h
	lcall sndmax
	mov dptr, #panel31
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
	mov dptr, #panel12
	movx a, @dptr
	mov R1, a
	mov R0, #003h
	lcall sndmax
	mov dptr, #panel22
	movx a, @dptr
	mov R1, a
	mov R0, #003h
	lcall sndmax
	mov dptr, #panel32
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
	mov dptr, #panel13
	movx a, @dptr
	mov R1, a
	mov R0, #004h
	lcall sndmax
	mov dptr, #panel23
	movx a, @dptr
	mov R1, a
	mov R0, #004h
	lcall sndmax
	mov dptr, #panel33
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
	mov dptr, #panel14
	movx a, @dptr
	mov R1, a
	mov R0, #005h
	lcall sndmax
	mov dptr, #panel24
	movx a, @dptr
	mov R1, a
	mov R0, #005h
	lcall sndmax
	mov dptr, #panel34
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
	mov dptr, #panel15
	movx a, @dptr
	mov R1, a
	mov R0, #006h
	lcall sndmax
	mov dptr, #panel25
	movx a, @dptr
	mov R1, a
	mov R0, #006h
	lcall sndmax
	mov dptr, #panel35
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
	mov dptr, #panel16
	movx a, @dptr
	mov R1, a
	mov R0, #007h
	lcall sndmax
	mov dptr, #panel26
	movx a, @dptr
	mov R1, a
	mov R0, #007h
	lcall sndmax
	mov dptr, #panel36
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
	mov dptr, #panel17
	movx a, @dptr
	mov R1, a
	mov R0, #008h
	lcall sndmax
	mov dptr, #panel27
	movx a, @dptr
	mov R1, a
	mov R0, #008h
	lcall sndmax
	mov dptr, #panel37
	movx a, @dptr
	mov R1, a
	mov R0, #008h
	lcall sndmax
	lcall latchMAX

ret



;=================================================================
; Subroutine updLED2
; Updates the LEDs attached to the MAX7219 serial interface
;=================================================================
updLED2:
	mov R7, #008h		; Use R7 as countdown, loop 8 times
	mov R6, #007h
updLEDLoop2:
	mov dptr, #panel00	; Get locaiton of pattern 0	
	;push 006h
	mov a, dpl
	add a, R6		; Add location offset
	mov dpl, a
	;pop 006h
	movx a, @dptr		; Get data from memory
	mov R1, a		; Place value into R1
	mov R0, 007h		; Use table pos as address
	lcall sndMAX		; Send data out to serial

	mov dptr, #panel10	; Get locaiton of pattern 0	
	;push 006h
	mov a, dpl
	add a, R6		; Add location offset
	mov dpl, a
	;pop 006h
	movx a, @dptr		; Get data from memory
	mov R1, a		; Place value into R1
	mov R0, 007h		; Use table pos as address
	lcall sndMAX		; Send data out to serial

	mov dptr, #panel20	; Get locaiton of pattern 0	
	;push 006h
	mov a, dpl
	add a, R6		; Add location offset
	mov dpl, a
	;pop 006h
	mov R0, a		; Move into R0 for indirect address
	movx a, @dptr		; Get data from memory
	mov R1, a		; Place value into R1
	mov R0, 007h		; Use table pos as address
	lcall sndMAX		; Send data out to serial

	mov dptr, #panel30		; Get locaiton of pattern 0	
	;push 006h
	mov a, dpl
	add a, R6		; Add location offset
	mov dpl, a
	;pop 006h
	movx a, @dptr		; Get data from memory
	mov R1, a		; Place value into R1
	mov R0, 007h		; Use table pos as address
	lcall sndMAX		; Send data out to serial

	lcall latchMAX		; Latch values into MAX

	dec R6
	djnz R7, updLEDLoop2	; Loop till reach end
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
