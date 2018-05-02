.name "and"
.comment "and the demon dies."

and5:	and %2, %2, r12
and1:	and r11,r12,r13
and2:	and r11,%420,r12
		and r11,%:and1,r13
and3:	and r11,420,r12
		and r11,:and2,r13
and4:	and %420,r11,r12
		and %:and3,r12,r13
and5:	and %420, %420, r12
		and %420, %:and4, r12
		and %:and4, %420, r12
		and %:and5, %:and4, r12
and6:	and %420, 420, r11
		and %:and5, 420, r12
		and %420, :and5, r13
		and %:and6, :and4, r11
and7:	and 420,r11,r12
		and :and3,r12,r13
and8:	and 420, %420, r12
		and 420, %:and8, r12
		and :and4, %420, r12
		and :and5, %:and4, r12
and9:	and 420, 420, r11
		and :and5, 420, r12
		and 420, :and5, r13
		and :and6, :and4, r11

