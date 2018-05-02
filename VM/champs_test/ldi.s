.name "ldi"
.comment "c'est du l(s)d ++"

ldi1:	ldi r1,r2,r3
		ldi r1,%420,r3
		ldi r1, %:ldi1,r2
ldi2:	ldi %420,r2,r3
		ldi %420, %464, r3
		ldi %420, %:ldi1, r3
		ldi %:ldi1,r1,r3
		ldi %:ldi1, %464, r2
		ldi %:ldi1, %:ldi2, r3
ldi3:	ldi 420, %464, r1
		ldi 420, %:ldi2, r1
		ldi :ldi1, %420, r1
		ldi :ldi2, %:ldi1, r1
		ldi 464,r1,r2
		ldi :ldi3, r1,r2
