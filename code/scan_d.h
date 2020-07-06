/*
 *  scan_d.h
 *  
 *
 *  Created by Federico Canale on 05/10/15.
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

void scan_d (int d[m][n]) 
{
		
	for ( int i = 0 ; i < m ; i++ )
		for ( int j = 0 ; j < n ; j++ ) {
			printf("d[%d][%d] is: ", i+1, j+1);
			scanf("%d", &d[i][j]);
		}
	puts("");
}