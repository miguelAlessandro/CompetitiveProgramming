'''
	@name COCI 2017 ceste
	@author Miguel Mini
	@tag dp, memory_compression
	@idea:
			- we can make two simple 
			dps, dp[pos]: sum of values
			processed with the elements 
			of s[0:pos+1], cnt[pos]: 
			numbers of elements in the
			same range.
'''
s = input()
dp = [0] * 2
cnt = [0] * 2
dp[0] = 1
cnt[0] = 1
for i in range(len(s)):
	dp[(i+1)&1] = 2 * dp[i&1]
	cnt[(i+1)&1] = cnt[i&1]
	if s[i] == 'R': 
		dp[(i+1)&1] += cnt[i&1]
	if s[i] == '*': 
		dp[(i+1)&1] += 3 * dp[i&1] + cnt[i&1]
		cnt[(i+1)&1] += 2 * cnt[i&1]
	if s[i] == 'P':
		dp[(i+1)&1] -= dp[i&1]

print(dp[len(s)&1])

