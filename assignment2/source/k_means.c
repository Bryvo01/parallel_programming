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
  double x_sum = 0;
  double y_sum = 0;
  double min_dist;
  double distance;
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
  // do the iterations
  for(b = 0; b < iters; b++) {
    // loop through the points
    for(a = 0; a < m; a++) {
      min_dist = INFINITY;
      // loop through the centers
      for(j = 0; j < k; j++) {
        // get the distance
        distance = pow((p[a].x - u[j].x), 2) + pow((p[a].y - u[j].y), 2);
        // check if smaller than the prev
        if(distance < min_dist) {
          c[a] = j;
          min_dist = distance;
        }
      }
    }
    for(j = 0; j < k; j++) {
      // get the sums
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
      if(count > 0) {
        // get the new center
        u[j].x = x_sum/count;
        u[j].y = y_sum/count;
      } else {
        // reset the lonely boi
        u[j] = random_center();
      }
    }
  }
  return;
}
