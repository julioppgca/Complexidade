/*
 ============================================================================
 Name        : Uri1946.c
 Author      : Julio Santos
 Version     : 1.0
 Copyright   : none
 Description : Uri's problem 1946 - Piramide da Sorte
 Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1946
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX 2501

float matrix[MAX][MAX]={};

uint32_t calc(uint32_t lin, uint32_t lim)
{
	static uint32_t line=0;
	uint32_t i;

	line=lin;
	matrix[lin][0]=matrix[lin-1][1];
	for(i=1;i<=lim;i++)
	{
		matrix[lin][i]=(matrix[lin][i-1]+matrix[lin-1][i+1])/2;
		//printf(" [%d][%d] %.2f",lin,i,matrix[lin][i]);
	}
	//puts("\n");
	if(lim--) calc(++lin,lim);

	return line-1;
}


int main(void)
{
	uint32_t b;

	memset(matrix,0,sizeof(matrix));
	matrix[0][1]=100;

	scanf("%d",&b);

	printf("%.2f\n", matrix[calc(1,b/2)][1]);

	return EXIT_SUCCESS;
}
