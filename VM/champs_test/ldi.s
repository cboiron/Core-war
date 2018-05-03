.name "ldi"
.comment "c'est du l(s)d ++"

ldi1:	ld %45, r5
ldi2: ldi %420,r8,r3
		ldi %420, %464, r3
		ldi %420, %:ldi1, r3
		ldi %:ldi1,r5,r3
		ldi %:ldi1, %464, r2
		ldi %:ldi3, %:ldi2, r3
		st	r5, -100
ldi3:	ldi 420, %464, r5
		st	r5, -100
		ldi 420, %:ldi2, r5
		ldi :ldi1, %420, r5
	ldi :ldi2, %:ldi3, r5
		ldi 464,r5,r2
		ldi :ldi3, r5,r2
