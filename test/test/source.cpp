cal a^n mod p

while(n) {
	if (n&1) r=r*a%p
	n >>= 1, a = a*a%p
}
