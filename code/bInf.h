int b_inf_A ( tNode * person ) 
{
	int bA = 0;
	int pi = person->height;
	int sum = d[1][person->tskLeft[pi]-1]+d[2][person->tskLeft[pi]-1];
	
	for ( int i = 0 ; i < n ; i++ ) {
		bA += d[0][person->tskLeft[i]-1];
		
		if ( i > pi && d[1][person->tskLeft[i]-1]+d[2][person->tskLeft[i]-1] < sum ) {
			sum = d[1][person->tskLeft[i]-1]+d[2][person->tskLeft[i]-1];
		}
	}
	
	bA += sum;
	
	return bA;
}

int b_inf_B ( tNode * person ) {
	int pi = person->height;
	int bB = 0; 
	int sum = d[2][person->tskLeft[pi]-1];
	int a[n];
	
	for ( int i = 0; i < n ; i++ ) {
		a[i] = person->tskLeft[i] - 1;
	}
	
	if ( pi != 0 ) { // if pi = 0, dim is 0 in calc_date 
		bB = calc_date( pi, a, 1);
		printf("this is in bB\n");
	}
	
	for ( int i = pi ; i < n ; i++ ) {
		bB += d[1][person->tskLeft[i]-1];
		
		if ( d[2][person->tskLeft[i]-1] < sum ) {
			sum = d[2][person->tskLeft[i]-1];
		}
	}
	
	bB += sum;
	
	return bB;
}

int b_inf_C ( tNode * person  ) 
{
	int pi = person->height;
	int bC = 0;
	int a[n];
	
	for ( int i = 0; i < n ; i++ ) {
		a[i] = person->tskLeft[i] - 1;
	}
	
	if ( pi != 0 ) {
		bC = calc_date( pi, a, 2);
		printf("calc_date()=%2d\n",bC);
	}
	
	for ( int i = pi ; i < n ; i++ ) {
		bC += d[2][person->tskLeft[i]-1];
		printf("bC = %2d in i = %2d\n", bC, i);
	}

	return bC;
}


int  b_inf_1 ( tNode * person ) 
{
	int bA = b_inf_A ( person );
	int bB = b_inf_B ( person );
	int bC = b_inf_C ( person );
	
	int max = bA;
	
	if ( bB > max ) {
		max = bB;
	}
	
	if ( bC > max ) {
		max = bC;
	}
	return max;
}
