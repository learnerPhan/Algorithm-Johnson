#include<stdio.h>
#include<stdlib.h>
#include <limits.h>


#define m 3 //number of machines
#define n 8 //number of tasks

typedef struct node {
	int bornInf;
	int bornSup;
	int tskLeft[n];
	int height;
	struct node *father;
	int nbSons;
	struct node **sons;
	int rank; //rank of i means he is the i-th older son
} tNode;

int bSup;
int d[m][n] = { 0 }; //stores the d_i,j
int I, J; //I is used for taches being analized in Johnson and J is the the corrispondent manchine
int temp[m][n]; //temporary copies d and is update for the algo. temp describes at what time the i-th tache finishes in the j-th machine


#include "min_d.h"
#include "scan_d.h"
#include "johnson.h"
#include "calc_date.h"
#include "bInf.h"
#include "n_trees.h"

int main () 
{
	int date_j;
	int result[n];
	
	scan_d(d); 
	
	for ( int i = 0 ; i < n ; i++ ) {
		result[i] = i;
	}
	
	johnson( result, n, 0 ); 
	
	puts("");
	
	for ( int i = 0 ; i < n ; i++ ) { 
		printf("%d", result[i]+1);
	}
	
	puts("");
	puts("");
	
	bSup = calc_date( n, result, m-1 );
	
	printf( "final date is %d", bSup );
	puts( "" );
	
	
	tNode *root = create_root( n );
	
	create_tree( root, n );
	
	//read_tree( root, n );
	printf("\n\nit's okay1!\n");

	empty_sons ( root );
	printf("\n\nit's okay2!\n");

	free( root );
	printf("\n\nit's okay3!\n");
	
	printf("optimum is %d\n",array[k-1]);
	for ( int i = 0 ; i < k ; i++ ) {
		printf("%d ", array[i]);
	}
}
