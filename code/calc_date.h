void init_temp ( int machine, int task, int d_temp[machine][task] );
int date_machine ( int machine , int task, int d_temp[m][task] );

int calc_date ( int dim, int order[n] , int machine )
{
	int d_temp[m][dim];
	
	//printf("\norder: %d %d %d %d\n", order[0], order[1], order[2], order[3]);
	
	for ( int i = 0 ; i < m ; i++ ) {
		for ( int j = 0 ; j < dim ; j++ ) {
			d_temp[i][j] = d[i][order[j]];
		}
	}
	/*printf("first of all:\n");
	
	for ( int i = 0 ; i < m ; i++ ) {
		for ( int j = 0 ; j < dim ; j++ ) {
			printf("%d ", d_temp[i][j]);
		}
		puts("");
	}*/
	
	init_temp( m, dim, d_temp );
	
	/*printf("before date_machine\n");
	
	for ( int i = 0 ; i < m ; i++ ) {
		for ( int j = 0 ; j < dim ; j++ ) {
			printf("%d ", d_temp[i][j]);
		}
		puts("");
	}*/
	
	for ( int i = 1 ; i < m ; i++ ) { //The first machine j=0 is not important because the durations in A are not affected by anything
		date_machine( i, dim, d_temp);
	}
	
	printf("after date_machine\n");

	for ( int i = 0 ; i < m ; i++ ) {
		for ( int j = 0 ; j < dim ; j++ ) {
			printf("%d ", d_temp[i][j]);
		}
		puts("");
	}
	
	return d_temp[machine][dim-1];
}

/* init_temp initialize temp in order to have 
 temp[i][j] = the time passed when i 0 finishes with
 the j-th machine, with the i+1 tache entering j
 without waiting times in between (if i = 0 it still 
 has to wait to finish with the first j-1 machines),
 as though as each machine worked with a different
 set of i-1 taches and one (the first) in common
 In other words, the i-th tache enters the j-th machine
 as soon as tache i-1 has finished with j with only one
 condition. They do not begin at time zero: each machine
 j begins as soon as it could begin in the "original
 problem", i.e. as soon as the first tache has been done
 by the j-1 machine.
*/
void init_temp ( int machine, int task, int d_temp[machine][task] ) {
	
	for ( int i = 0 ; i < machine ;  i++ ) { //initialize temp as d and adds up to all of them the "beginning time"
		for ( int j = 0 ; j < task ; j++ ) {
			if ( j == 0 && i != 0 ) {
				d_temp[i][j] += d_temp[i-1][j];
			}
			else {
				if ( j != 0 ) {
					d_temp[i][j] += d_temp[i][j-1];
				}
			}			
		}
	}
}


/* for each machine j after the first, date_machine
 adds the waiting time for the i-th tache to enter 
 the j-th machine even though j is ready (i.e. i+1
 has finished in j but i has yet to be finished with j-1)
 or the waiting time for the i-th tache to enter 
 the j-th machine because j is not ready (i.e. i+1 is
 being done in j).
*/

int date_machine ( int i, int task, int d_temp[m][n]) 
{
	int sum = 0; //keeps track for each i that has to wait before the machine is ready
	if ( task == 1 ) {
		return d_temp[i][task-1];
	}
	
	printf(" in date_machine with i = %d\n", i);
	
	for ( int j = 1 ; j < task ; j++ ) { //the first task is not affected either
		if ( d_temp[i-1][j] > d_temp[i][j-1] ) { 
			/* (*) if the j-th tache finishes in the i-1 machine after the tache j-1 machine finishes
			 with the i-th, there is a waiting time of temp[result[i-1]][j] - temp[result[i]][j-1],
			 that adds up to the findal date */

			sum += d_temp[i-1][j] - d_temp[i][j-1]; 
		}
		
		d_temp[i][j] += sum;
		
		printf("%4d, %4d  ", d_temp[i][j], sum );
	}
	
	puts("");
	return d_temp[i][task-1];
}
