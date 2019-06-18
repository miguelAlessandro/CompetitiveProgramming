N = 500
prime = []
composite = [0] * N
for i in range(2, N):
	if not composite[i]:
		prime += [i]
	for p in prime:
		if p * i >= N: break
		composite[p * i] = 1
		if i % p == 0: break
for _ in range(20):
	n = int(input())
	m = 1
	for p in prime:
		if m <= n // p:
			m *= p
	print(m)
