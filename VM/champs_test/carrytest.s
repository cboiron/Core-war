.name	"testcarry"
.comment	"je teste les carry qui doivent faire 0"

ld	%0, r2
zjmp %-150
add r4,r3,r5
zjmp %-100
sub r4,r3,r5
zjmp %-125
and r4, %0,r6
zjmp %-200
or r3, %0,r7
zjmp %-200
xor r2, %0,r3
zjmp %-200
lld %0,r2
zjmp %-200
lldi %10,%85,r3
zjmp %-200




#zjmp %-250 # test zjmp = 1
