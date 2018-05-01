.name "lldi"
.comment "c'est du l(s)d lourd"

lldi1:	lldi r1,r2,r3
		lldi r1,%420,r3
		lldi r1, %:lldi1,r2
lldi2:	lldi %420,r2,r3
		lldi %420, %464, r3
		lldi %420, %:lldi1, r3
		lldi %:lldi1,r1,r3
		lldi %:lldi1, %464, r2
		lldi %:lldi1, %:lldi2, r3
lldi3:	lldi 420, %464, r1
		lldi 420, %:lldi2, r1
		lldi :lldi1, %420, r1
		lldi :lldi2, %:lldi1, r1
		lldi 464,r1,r2
		lldi :lldi3, r1,r2
