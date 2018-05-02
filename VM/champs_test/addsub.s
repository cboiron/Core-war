.name "add&sub"
.comment "addiction & subbition"

label:	ld %38, r2
ld %22, r3
add1:	add r1,r2,r3
sub1:	sub r1,r3,r12
st r3, 30
st r12, 60
