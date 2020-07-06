void johnson ( int order[n], int const task, int h ) 
{
	int i = 0, j = 0; //used to keep track of where we are in G and D respectively
	int machine = 2;
	int j_temp[machine][task]; //used to work with the matrix d without having to modify it. task - h because we want to work without modifying the first h columns
	int min; 
	int G[task]; //the first taches to enter go here
	int D[task]; //the last taches to enter go here
	
	printf("\n\nh = %3d\n", h);
	
	for ( int i = 0 ; i < task ; i++ ) {
		G[i] = 0;
		D[i] = 0;
	}
	
	for ( int a = 0 ; a < machine ;  a++ ) { //initialize temp as d without the line for C
		for ( int b = 0 ; b < task ; b++ ) {
			j_temp[a][b] = d[a][b];
		}
	}

		
	for ( int l = 0 ; l < h ; l++ ) { //resets the first h rows (indexed by order[l] to INT_MAX so that it won't be considered by min
		for ( int k = 0 ; k < machine; k++ ) {
			j_temp[k][order[l]] = INT_MAX;
		}
	}
	
	
	
	for ( int l = h; l < task ; l++ ) 
	{
		min = min_d( machine, task, j_temp ); 
						
		if ( I == 0 ) { //if machine A, puts I in the following empty space in G
			G[i+h] = J;
			i++; //updates i
		}
		else if ( I == 1 )  { //if machine B puts I in the previous empty space in D
			D[task-j-1] = J;
			j++; //updates j
		}
		
		for ( int k = 0 ; k < machine; k++ ) { //resets the J-th row to INT_MAX so that it won't be considered by min
			j_temp[k][J] = INT_MAX;
		}
	}
	
	for ( int i = h ; i < task ; i++ ) { //finally calculates the best order
		order[i] = G[i]+D[i];
        }
}
