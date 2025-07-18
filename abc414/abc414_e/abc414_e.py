MOD = 998244353
N = int(input())

ans = ((1 + N) * N // 2)

i = 1
while (i <= N):
  q = N // i
  j = N // q
  c = j - i + 1
  ans -= c * q
  i = j + 1
 
print(ans % MOD)