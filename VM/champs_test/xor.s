.name "xor"
.comment "xelophoniquement ordonné résultat"

xor1:	xor r11,r12,r13
xor %5, %2, r5
xor2:	xor r11,%420,r12
		xor r11,%:xor1,r13
xor3:	xor r11,420,r12
		xor r11,:xor2,r13
xor4:	xor %420,r11,r12
		xor %:xor3,r12,r13
xor5:	xor %420, %420, r12
		xor %420, %:xor4, r12
		xor %:xor4, %420, r12
		xor %:xor5, %:xor4, r12
xor6:	xor %420, 420, r11
		xor %:xor4, 420, r12
		xor %420, :xor5, r13
		xor %:xor6, :xor4, r11
xor7:	xor 420,r11,r12
		xor :xor3,r12,r13
xor8:	xor 420, %420, r12
		xor 420, %:xor8, r12
		xor :xor4, %420, r12
		xor :xor5, %:xor4, r12
xor9:	xor 420, 420, r11
		xor :xor5, 420, r12
		xor 420, :xor5, r13
		xor :xor6, :xor4, r11

