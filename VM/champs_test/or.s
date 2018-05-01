.name "or"
.comment "or you die"

or1:	or r11,r12,r13
or2:	or r11,%420,r12
		or r11,%:or1,r13
or3:	or r11,420,r12
		or r11,:or2,r13
or4:	or %420,r11,r12
		or %:or3,r12,r13
or5:	or %420, %420, r12
		or %420, %:or4, r12
		or %:or4, %420, r12
		or %:or5, %:or4, r12
or6:	or %420, 420, r11
		or %:or5, 420, r12
		or %420, :or5, r13
		or %:or6, :or4, r11
or7:	or 420,r11,r12
		or :or3,r12,r13
or8:	or 420, %420, r12
		or 420, %:or2, r12
		or :or1, %420, r12
		or :or2, %:or4, r12
or9:	or 420, 420, r11
		or :or5, 420, r12
		or 420, :or5, r13
		or :or6, :or4, r11

