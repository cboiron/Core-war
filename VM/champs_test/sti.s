.name "sti"
.comment "c'est du st-- (t'as cru c'était du ++ avoue)"

sti1:	sti r1,r2,r3
		sti r1,r2,%420
		sti r1,r4,%:sti1
sti2:	sti r1,%420,r3
		sti r1,%:sti1, r3
		sti r1, %420,%:sti2
		sti r1, %420, %464
		sti r1, %:sti2, %:sti3
		sti r1, %:sti2, %464
sti3:	sti r1,420,r3
		sti r1,420,%420
		sti r1,420,%:sti2
		sti r1, :sti1, r1
		sti r1, :sti1, %420
		sti r1, :sti1, %:sti3
