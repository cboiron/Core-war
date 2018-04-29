.name	"testst"
.comment	"many test for st"

start:
	live %9
	live %9
	live %9
	zjmp	%:part1

part1:
	st r1, r2
	ld %5000, r1
	st r2, r3
	ld %6000, r2
	st r3, r4
	ld %7000, r3
	st r4, r5
	ld %8000, r4
	st r5, r6
	ld %9000, r5
	st r6, r7
	ld %10000, r6
	st r7, r8
	ld %11000, r7
	st r8, r9
	ld %12000, r8
	st r9, r10
	ld %13000, r9
	st r10, r11
	ld %14000, r10
	st r11, r12
	ld %15000, r11
	st r12, r13
	ld %16000, r12
	st r13, r14
	ld %17000, r13
	st r14, r15
	ld %18000, r14
	st r15, r16
	ld %19000, r15
	st r16, r1
	ld %20000, r16
	zjmp %:part1

part2:
	st r1, r2
	ld %-5000, r1
	st r2, r3
	ld %-6000, r2
	st r3, r4
	ld %-7000, r3
	st r4, r5
	ld %-8000, r4
	st r5, r6
	ld %-9000, r5
	st r6, r7
	ld %-10000, r6
	st r7, r8
	ld %-11000, r7
	st r8, r9
	ld %-12000, r8
	st r9, r10
	ld %-13000, r9
	st r10, r11
	ld %-14000, r10
	st r11, r12
	ld %-15000, r11
	st r12, r13
	ld %-16000, r12
	st r13, r14
	ld %-17000, r13
	st r14, r15
	ld %-18000, r14
	st r15, r16
	ld %-19000, r15
	st r16, r1
	ld %-2000, r16
	zjmp %:def

def:
	st r1, -1200
	st r2, -600
	st r3, -2000
	st r4, -400
	zjmp %:start
