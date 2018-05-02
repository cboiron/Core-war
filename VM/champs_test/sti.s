.name "sti"
.comment "c'est du st-- (t'as cru c'était du ++ avoue)"

#sti1:	sti r1,r2,r3
#		sti r1,r2,%420
#		sti r1,r4,%:sti1
#sti2:	sti r1,%420,r3
#		sti r1,%:sti1, r3
#		sti r1, %420,%:sti2
#		sti r1, %420, %464
#		sti r1, %:sti2, %:sti3
#		sti r1, %:sti2, %464

sti3:	ld %45, r5
		sti r5, r5,%10
		sti r5,%10000,%-578187
		sti r5,350,%420
		sti r5,420,r3
		sti r5,150,%:sti3
		sti r5, :sti3, r1
		sti r5, :sti3, %420
		sti r5, :sti3, %:sti3
