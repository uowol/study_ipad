/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, *arr;
        scanf("%d", &n);
	    
	        arr = (int*) malloc(sizeof(int) * n);
		    
		        srand(time(NULL));
			    
			        for(int i=0; i<n; i++){
				        arr[i] = rand() % 100;
					    }
					        
						    for(int i=0; i<n; i++){
						            printf("%d ", arr[i]);
							        }
								    printf("\n");
								        
									    int m, tmp1, tmp2, idx;
									        
										    scanf("%d", &m);    // 5
										        
											    scanf("%d", &idx);  // 3 8 0 9 3
											        tmp1 = arr[idx];    // [3]
												    
												        for(int i=0; i<m-1; i++){
													        scanf("%d", &idx);  // 8
														        tmp2 = arr[idx];    // [8]
															        arr[idx] = tmp1;
																        tmp1 = tmp2;
																	    }
																	        
																		    for(int i=0; i<n; i++){
																		            printf("%d ", arr[i]);
																			        }
																				    printf("\n");

																				        return 0;
																					}

