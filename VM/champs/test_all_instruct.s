.name           "42"
.comment        "Just a basic Winner Program"

	live	%42		# entree
	ld	%0,r5
	st	r5,r2
	add	r4,r5,r4
	sub	r2,r4,r2
	and	r2,r2,r2	# selection vers les modules
	or	r2,r2,r2	# selection vers les modules
	xor	r10,r10,r10	# pour rien
	zjmp	%0
	ldi r1,%0,r3
	sti	r10,%-510,%0
	fork	%0
	lld %0,r3
	lldi r1,%0,r3
	lfork %0