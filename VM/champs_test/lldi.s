.name "lldi"
.comment "c'est du l(s)d lourd"

lldi1:	
		ld %15, r5
		ld %15, r11
		st r2, -500
		lldi r11, %70,r2
		st r2, -500
lldi2:	#lldi %:lldi1, %464, r2 
		st r2, -500
		lldi %420,r2,r3
		lldi %420, %464, r3
		lldi %420, %:lldi1, r3
		lldi %:lldi1,r5,r3
		lldi %:lldi1, %464, r2 #R2=0
		lldi %:lldi1, %:lldi2, r3
lldi3:	lldi 420, %464, r5
		lldi 420, %:lldi2, r5
		lldi :lldi1, %420, r5
		lldi :lldi2, %:lldi1, r5
		lldi 464,r5,r2
		lldi :lldi3, r5,r2
