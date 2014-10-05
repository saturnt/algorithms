#include<stdio.h>
#include<stdlib.h>

int max_sub_array_n(int a[], int sub_array_n[], int n, int m){
  int i = 0;
  for(i = 0; i < m; i++){
     sub_array_n[m - 1] += a[i];
  }
  
  for(i = m; i < n; i++){
    sub_array_n[i] = sub_array_n[i - 1] + a[i] - a[i - m] ;
  }		
  return 0;
}

int max_sum_subarray(int a[], int maximum_sum_subarray[], int n){
 	int i = 0;	
	maximum_sum_subarray[0] = a[0];
	for(i = 1; i < n; i++){
	   maximum_sum_subarray[i] = (maximum_sum_subarray[i-1] + a[i]) > 0 ? (maximum_sum_subarray[i-1] + a[i]) : 0;	
	}		
  return 0;	
}

int main(){
 int a[] = { -5, 0 , -4, 1, 4, 3, -2, -1, 2, -3, 98 };
 int maximum_sum_subarray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int i = 0;
 int n = 11;
 max_sum_subarray(a, maximum_sum_subarray, n);
 int max_value = 0;
 for(i = 0; i < n; i++){
   printf("Subarray %d = %d\n", i, maximum_sum_subarray[i]);	
   if(max_value < maximum_sum_subarray[i]){	
	max_value = maximum_sum_subarray[i];
   }	 	
 }
 printf("Maximum Sum subarray = %d\n", max_value);

 int m = 3;
 int sub_array_n[] = {0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 max_sub_array_n(a, sub_array_n, n, m);
 max_value = 0;
 
  for(i = 0; i < n; i++){
   printf("Subarray %d = %d\n", i, sub_array_n[i]); 
   if(max_value < sub_array_n[i]){ 
        max_value = sub_array_n[i];
   } 
 }
 printf("Maximum Sum subarray of m= %d\n", max_value); 		
}
