/*
 ============================================================================
 Name        : Uri1643.c
 Author      : Julio Santos
 Version     : 1.0
 Copyright   : none
 Description : URI Problem 1643 - Converter Quilômetros para Milhas
 Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1643
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// limits
#define MAX 25000
#define FN  24

// fibonacci numbers up to 23
const uint32_t FIB[FN]={0,    1,    1,    2,     3,    5,
			8,    13,   21,   34,    55,   89,
			144,  233,  377,  610,   987,  1597,
			2584, 4181, 6765, 10946, 17711, 28657
			};

// store the position of the conversion
uint32_t fib[FN]={};

// put the index on the vector
void find(uint32_t n)
{
	uint32_t i;

	for(i=0;i<FN;i++)  //search in the vector
	{
		if(n==FIB[i])	//exact number
			{
			fib[i-1]=1; // set the index shiffted by one
			n-=FIB[i];  // reduce the input
			break;
			}
		if(n<FIB[i])   // not exact number
			{
			fib[i-2]=1;	// set index shift by 2
			n -= FIB[i-1]; // reduce the input
			break;
			}
	}
	if(n>0) find(n); // still calling until n>0
}

int main(void)
{
uint32_t i=0,j=0,t;
uint32_t x[MAX]={};
uint32_t res=0;

	//get the inputs
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d", &j);
		x[i]=j;
	}

	//put the results
	for(i=0;i<t;i++)
		{
		memset(fib,0,sizeof(fib));
		res=0;
		find(x[i]); // get index
		for(j=0;j<FN;j++) if(fib[j]) res+=FIB[j]; // make conversion
		printf("%d\n",res); // print result
		}

	return EXIT_SUCCESS;
}
