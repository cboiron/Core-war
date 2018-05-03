.name "lldi"
.comment "c'est du l(s)d lourd"

lldi1:	
		ld %15, r5
		lldi r5,r2,r3
		lldi r5,%420,r3
		lldi r5, %:lldi1,r2
		st r2, -400
lldi2:	lldi %:lldi1, %464, r2 
		lldi %420,r2,r3
		st r2, -300
		lldi %420, %464, r3
		lldi %420, %:lldi1, r3
		lldi %:lldi1,r5,r3
		st r2, -100
		lldi %:lldi1, %464, r2 ##NTM remet a 0 le r2
		st r2, -200
		lldi %:lldi1, %:lldi2, r3
lldi3:	lldi 420, %464, r5
		lldi 420, %:lldi2, r5
		lldi :lldi1, %420, r5
		lldi :lldi2, %:lldi1, r5
		lldi 464,r5,r2
		lldi :lldi3, r5,r2
