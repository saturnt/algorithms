#include<stdio.h>
#include<stdlib.h>

int permutations(int a[], int n, int curr_n, int temp[]){

  if(n == curr_n){
    int i;	
    for(i = 0; i < n; i++){
	  printf("%d", temp[i]);	
    }
  printf("\n");
  return 0;	
  }	   		

  int aux_temp;
  temp[curr_n] = a[curr_n]; 
  permutations(a, n, curr_n + 1, temp);
  temp[curr_n] = -1;  	
  permutations(a, n, curr_n + 1, temp);
}

int main(){
 
 int a[] = { 1, 2, 3, 4};
 int temp[] = {-1, -1, -1, -1};
 permutations(a, 4, 0, temp);
	
}
