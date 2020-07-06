int k = 1; //counter for keeping track of the new minimums;
int array[100000] = { 0 };
int counter;

//creates the root with an array of all the tasks
tNode * create_root ( int tasks );
//creates nbSons children pointed by root (i.e. sons of root).
void create_sons( tNode *person, int nb );
//creates a tree of height h
void create_tree( tNode *root, int h );
//reads tree of height h, reads tree->tskLeft and after goes higher
void read_tree( tNode *root, int h );
//empties sons of root
void empty_sons( tNode *person );
int find_in_array ( int a, int array[n], int dim );


tNode * create_root ( int tasks )
{
	tNode *root = malloc( sizeof( tNode ) );
	
	for ( int i = 0 ; i < tasks ; i++ ) {
		root->tskLeft[i] = i + 1;
	}
		
	root->bornInf = b_inf_1(root);
	root->bornSup = bSup;
	root->height = 0;
	root->sons = NULL;
	root->nbSons = 0;
	root->father = NULL;
	root->rank = 1;
	return root;
}


void create_sons( tNode *person, int nb )
{
	int a[n]; 
	int j = 0; 
	int k; 
	tNode* current;
	
	person->nbSons = nb;
		
	if ( nb > 0 ) {
		person->sons = malloc( nb*sizeof( tNode ) );
	}
	
	for ( int i = 0 ; i < nb ; i++ ) {
		current = malloc ( sizeof ( tNode ) );
		
		k = n-nb+1;
		
		if ( current != NULL ) {
			person->sons[i] = current;
			
			current->bornInf = 0;
			current->bornSup = 0; 
			current->height = person->height + 1;
			current->father = person;
			current->nbSons = nb - 1;
			current->sons = NULL;
			current->rank = i;
			
			for ( int b = 0 ; b < n ; b++)
				current->tskLeft[b] = 0;
		
			
			for ( int j = 0 ; j <= 2*n - nb ; j++ ) {
				if ( j < n - nb ) {
					current->tskLeft[j] = person->tskLeft[j];
			        }
				
				if ( j == n - nb ) {
					current->tskLeft[j] = person->tskLeft[current->rank + person->height];
					
				}
				
				if ( j > n - nb ) {
					if ( !find_in_array( j-n+nb, current->tskLeft, n ) ) { 
						current->tskLeft[k] = j-n+nb;
						k++;
					}
				}
				
				
			}
			
		}
		else {
			puts("ERROR: not enough memory.");
		}
	}
	for ( int i = 0 ; i < n ; i++ ) {
		a[i] = person->tskLeft[i]-1;
	}
	
	if ( nb > 1 ) {
		person->bornInf = b_inf_1(person);
		person->bornSup = bSup;
	}
	else {
		person->bornInf = calc_date(n, a, m-1); 
		person->bornSup = person->bornInf;

	}
	
	printf("bA = %2d, bB = %2d, bC = %2d, bInf = %2d, bSup = %d\n", b_inf_A(person), b_inf_B(person), b_inf_C(person), person->bornInf, person->bornSup);
}


void create_tree( tNode *root, int nb )
{
	array[0] = INT_MAX;

	if ( nb > 0 ) {
		for ( int i = 0 ; i < n ; i++ ) {
			printf("%3d ", root->tskLeft[i]);
		}
		
		create_sons(root, nb);
		
		printf("bSup = %4d , bInf = %4d", root->bornSup, root->bornInf);
		puts("");
		

		if ( root->bornInf <= array[k-1] ) {
			if ( root->bornInf != root->bornSup ) {
				for ( int i = 0; i < nb; i++ ) {
					create_tree( root->sons[i], nb-1) ;
					puts("/");
				}
			}
			else {
				array[k] = root->bornInf;
				k++;
			}
		}
	}
}


void read_tree( tNode *root, int nb )
{
	
	for ( int i = 0 ; i < n ; i++ ) {
		printf("%3d ", root->tskLeft[i]);
	}
	
	printf("bSup = %4d , bInf = %4d", root->bornSup, root->bornInf);
	puts("");
	
	array[0] = INT_MAX;

	if ( nb > 0 ) {
		if ( root->bornInf <= array[k-1] ) {
			if ( root->bornInf != root->bornSup ) {
				for ( int i = 0; i < nb; i++ ) {
					read_tree( root->sons[i], nb-1) ;
					puts("/");
					free( root->sons[i] );
				}
			}
			else {
				array[k] = root->bornInf;
				k++;
			}
		}
	}
}


void empty_sons( tNode *person )
{	
	for ( int i=0; i < person->nbSons && person->sons != NULL ; i++ )
	{
		printf("I've been here\n");
		empty_sons( person->sons[i] ); // empties all sons of person
		free( person->sons[i] ); //empties person
	}
	
	//frees everything
	free(person->sons);
	person->nbSons = 0;
	person->sons = NULL;
}

int find_in_array ( int a, int array[n], int dim ) 
{
	int i;
	
	for ( i = 0 ; i < dim ; i++ ) {
		if ( array[i] == a ) {
			return 1;
		}
	}
	
	return 0;
}
