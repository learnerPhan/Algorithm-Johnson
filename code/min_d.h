#include<stdio.h>

int min_d ( int row, int column, int a[row][column])
{
	int i,j;
	int min = a[0][0];
	
	if ( row != 2 ) {
		puts("invalid dimension of array.");
	}
	
	for ( i = 0 ; i < row ; i++ ) { 
		for ( j = 0 ; j < column ; j++ ) {
			if ( a[i][j] < min ) { 
				min = a[i][j];
				I = i;
				J = j;
			}
			
			else if ( a[0][0] == min ) {  
				I = 0;
				J = 0;
			}
		}
	}
	
	//printf(" min is %d, I is%d, J is %d\n", min, I, J );
	return min;
}
