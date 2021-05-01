import time;

WARMUP = 5
SECONDS = 10

def IsPrime(i):
	for j in range(2, i):
		if i % j == 0:
			return False

	return True

def GetPrimesUnderN(n):
	primes = 0

	for i in range(2, n):
		if IsPrime(i):
			primes += 1

	return primes

def main():
	passes = 0
	tick = time.time()

	while time.time() - tick < WARMUP:
		t = GetPrimesUnderN(10000 - (passes % 10000))
		if t > 1229:
			print("Incorrect number of primes.")

	tick = time.time()

	while time.time() - tick < SECONDS:
		t = GetPrimesUnderN(10000 - (passes % 10000))
		if t > 1229:
			print("Incorrect number of primes.")
		passes += 1

	print("Passed " + str(passes) + " runs in " + str(time.time() - tick) + " seconds.")

main()