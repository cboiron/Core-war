.name	"Warrior"
.comment	"Deathbringer"

	ld %0,r3
label: zjmp %:avantdebt
	zjmp %0;
code: live %1
	sti r15,%0,r14
	zjmp %-200
	live %1
	sti r15,%0,r14
	zjmp %-200


avantdebt: sti r1,%:code,%1
			sti r1,%:code,%15
			sti r1,%:code,%29
level0: fork %:level10
level10: live %1 
		fork%:level100
		level100: live %1
			ldi %4,%:code,r15
			ld %-190,r14
			ld %0,r2
			zjmp %:label
