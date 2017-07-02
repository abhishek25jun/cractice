#include "include.h"
#include <stdio.h>

unsigned int count_set_bits1(unsigned int num)
{
	unsigned int tmp;
	unsigned int n;
	n = 0;
	tmp = num;

	while(tmp) {
		n++;
		tmp = tmp & (tmp -1);
	}
	printf("method1> input:%d num of set bits: %d\n", num, n);
	return n;
}

unsigned int count_set_bits2(unsigned int num)
{
	unsigned int temp;
	unsigned int count;
	temp = num;
	count = 0;

	for(;temp!=0;temp>>=1) {
		if(temp&1)
			count++;
	}
	printf("method2> input:%d num of set bits: %d\n",num, count);
	return count;
}

unsigned int reverse_bits(unsigned int num)
{
	unsigned int tmp;
	unsigned int tmp1;
	int i;

	tmp = tmp1 = num;

	for(i = (sizeof(num)*8 - 1); i; i--) {
		tmp = tmp | (num & 1);
		tmp <<= 1;
		num >>= 1;
	}

	tmp = tmp | (num & 1);
	printf("input in hex:%x num after reversed bits in hex: %x\n",tmp1, tmp);
	return tmp;
}

unsigned int check_nth_bit(unsigned int num, unsigned char n)
{
	unsigned int tmp;
	unsigned char pos;
	pos = sizeof(num)*8 - n;
	
	printf("%dth bit of %x is:", n, num);
	for(tmp = 1; pos; pos--) {
		tmp <<= 1; 
	}
	if (num & tmp) {
		printf("ON\n");
		return 1;
	} else {
		printf("OFF\n");
		return 0;
	}
}


