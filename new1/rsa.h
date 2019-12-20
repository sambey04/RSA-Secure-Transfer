// C program for RSA asymmetric cryptographic 
// algorithm. For demonstration values are 
// relatively small compared to practical 
// application 
#include<stdio.h> 
#include<math.h> 

// Returns gcd of a and b 
int gcd(int a, int h) 
{ 
	int temp; 
	while (1) 
	{ 
		temp = a%h; 
		if (temp == 0) 
		return h; 
		a = h; 
		h = temp; 
	} 
return 0;
} 

// Code to demonstrate RSA algorithm 
int rsa(char msg) 
{ 
	int msg1=(int)msg;
	printf("message 1=%d\n",msg1);
    //long long msg=(long long)msg1;
	//printf("messagelong long==%llu\n",msg);
	//printf("messagechar==%c\n",msg1);
	// Two random prime numbers 
	long long p = 53; 
	long long q = 59; 

	// First part of public key: 
	long long n = p*q; 

	// Finding other part of public key. 
	// e stands for encrypt 
	long long e = 3; 
	long long phi = (p-1)*(q-1); 
	while (e < phi) 
	{ 
		// e must be co-prime to phi and 
		// smaller than phi. 
		if (gcd(e, phi)==1) 
			break; 
		else
			e++; 
	} 

	// Private key (d stands for decrypt) 
	// choosing d such that it satisfies 
	// d*e = 1 + k * totient 
	int k = 2; // A constant value 
	long long d = (1 + (k*phi))/e; 

	// Message to be encrypted 
	//long long msg ; 
    //scanf("%llu",&msg);
	printf("Message data = %llu", msg); 

	// Encryption c = (msg ^ e) % n 
	long long c = pow(msg, e); 
	c = fmod(c, n); 
	printf("\nEncrypted data = %llu", c); 

	// Decryption m = (c ^ d) % n 
	long long m = pow(c, d); 
	m = fmod(m, n); 
	printf("\nOriginal Message Sent = %llu", m); 

	return m; 
} 
// This code is contributed by Shivam Dogra. 
