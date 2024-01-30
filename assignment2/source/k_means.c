/*
 * Skeleton function for Parallel Processing, 
 * Assignment 2: K-Means Algorithm (Sequential)
 *
 * To students: You should finish the implementation of k_means function
 * 
 * Author:
 *     Wei Wang <wei.wang@utsa.edu>
 */
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>

#include "k_means.h"

/*
 * k_means: k_means clustering algorithm implementation.
 *
 * Input parameters:
 *     struct point p[]: array of data points
 *     int m           : number of data points in p[]
 *     int k           : number of clusters to find
 *     int iters       : number of clustering iterations to run
 *
 * Output parameters:   
 *     struct point u[]: array of cluster centers
 *     int c[]         : cluster id for each data points
 */
void k_means(struct point p[MAX_POINTS], 
	    int m, 
	    int k,
	    int iters,
	    struct point u[MAX_CENTERS],
	    int c[MAX_POINTS])
{
	int j;
	int a;
	int b;
	int count;
	float x_sum = 0;
	float y_sum = 0;
	float closest[m];
	float distance;
	/* To Students: add your local variables */

	/* randomly initialized the centers */
	for(j = 0; j < k; j++)
		u[j] = random_center(); /* DO NOT change this random generator! */
	/* 
	 * To students: please implment K-Means algorithm here 
	 * Your K-means implementation should do "iters" rounds of clustering. After 
	 * all iterations finish, array u[MAX_CENTERS] should have the coordinations 
	 * of your centers, and array c[MAX_POINTS] should have the cluster assignment
	 * for each point.
	 */
	//float min = fminf(a, fminf(b, c));
	//float max = fmaxf(a, fmaxf(b, c));
	
	//initialze min[] to infinity
	for(a = 0; a < m; a++) {
		closest[a] = INFINITY;
	}
	for(b = 0; b < iters; b++) {
		for(a = 0; a < m; a++) {
			for(j = 0; j < k; j++) {
				distance = pow(u[j].x - p[a].x, 2) + pow(u[j].y - p[a].y, 2);
				if(distance < closest[a]) {
					c[a] = j;
					closest[a] = distance;
				}
			}
		}
		for(j = 0; j < k; j++) {
			count = 0;
			x_sum = 0;
			y_sum = 0;
			for(a = 0; a < m; a++) {
				if(c[a] == j) {
					count++;
					x_sum += p[a].x;
					y_sum += p[a].y;
				}
			}
			u[j].x = x_sum/count;
			u[j].y = y_sum/count;
		}
	}
	//iterate through each point
	/*for(j = 0; j < k; j++) {
		//calculate the difference between a point and the center(s)
		for(a = 0; a < m; a++) {
			//printf("%d   xdiff: %.3lf\n", j, x_diff);
			x_diff = pow(u[j].x - p[a].x, 2) + pow(u[j].y - p[a].y, 2);
			y_diff = pow(u[j].y - p[a].y, 2);
			printf("xdiff: %.3lf     min[%d]: %.3lf\n", x_diff, a, min[a]);
			if (x_diff < min[a]) {
				min[a] = x_diff;
				point_cluster[a] = j;
				printf("changed min[%d] to: %.3lf    min[%d]: %.3lf\n",a, x_diff, a, min[a]);
			}
			//printf("x_diff: %.3lf\n", x_diff);
		}
	}
	for (a = 0; a < m; a++) {
		printf("%d   ", point_cluster[a]);
	}
	//printf("number of points: %d\n", m);
	//printf("points: %.3lf, %.3lf\n", p[0].x, p[0].y);	
	*/
	return;
}
