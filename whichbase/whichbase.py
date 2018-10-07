def is_pos(num, base):
	
	try:
		num = int(num, base)
		return num
	except:
		return False

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		k, n = map(str, input().split())
		base8 = 0 if not is_pos(n, 8) else is_pos(n, 8)
		base10 = 0 if not is_pos(n, 10) else is_pos(n, 10)
		base16 = 0 if not is_pos(n, 16) else is_pos(n, 16)
		print(k, base8, base10, base16)
		
	