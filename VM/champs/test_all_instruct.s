.name           "42"
.comment        "Just a basic Winner Program"

	live	%42		# entree
	ld	%0,r5
	ld	%0,r5
	st	r5,r2
	st	r5,r6
	add	r4,r5,r4
	add	r3,r4,r3
	sub	r2,r4,r2
	sub	r2,r4,r2
	and	r6,%2147483648,r8
	and	r2,r2,r2	# selection vers les modules
	or	r2,r2,r2	# selection vers les modules
	or	r2,r2,r2	# selection vers les modules
	xor	r10,r10,r10	# pour rien
	xor	r10,r10,r10	# pour rien
	zjmp	%0
	zjmp	%0
	sti	r10,%-510,%0
	sti	r10,%-510,r3
	sti	r10,%-510,%0
	sti	r10,%-510,r3
	fork	%0
	fork	%0
