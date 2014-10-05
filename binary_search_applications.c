#include<stdio.h>
#include<stdlib.h>


int binary_search_circular(int a[], int low, int high, int search){
  
  while(high >= low){
   int mid = (high + low)/2;

   if(a[mid] == search){
	printf("Found %d at index %d\n", a[mid], mid);
	return 0;
   } else if((a[mid] < a[mid - 1]) && (a[mid + 1] > a[mid])){
	if((a[mid] < search) && a[low] <= search){
	  high = mid + 1;
	} else {
	  low = mid - 1;	
	}
  } else if((a[mid] > a[mid - 1]) && (a[mid] > a[mid + 1])){
        if((a[mid] > search) && a[low] <= search){
          high = mid - 1;
        } else {
          low = mid + 1;
        }		
 } else{
	if((a[mid] < search) && (a[low] <= search)) {
	  low = mid + 1;	
	} else {
	  high = mid - 1;
	}
  }
 }	
}

int orig_binary_search(int a[], int low, int high, int search){

  int mid;

 while(high >= low){
   mid = (low + high)/2;		
   if(a[mid] == search){
     printf("Found %d at index %d\n", a[mid], mid);	
     orig_binary_search(a, mid + 1, high, 3);
     orig_binary_search(a, low, mid - 1, 3);
     return 0;	 
   } else if(a[mid] > search){
	// Swing to the left side.
	high = mid - 1;
   } else {
	low = mid + 1;
   }
 }	
}

int binary_search(int a[], int low, int high){

   if(high == low){
     return 0;		
   }
   
   int mid;
   
   mid = (high + low)/2;


 while(high >= low){ 				
   printf("%d %d %d\n",a[mid - 1], a[mid], a[mid + 1]);
   mid = (high + low)/2;	
   if((a[mid] > a[mid - 1]) && (a[mid] > a[mid + 1])){
	printf("Cool! The num is %d at index %d\n", a[mid], mid);	
	return 0;
   } else if((a[mid] > a[mid - 1]) && (a[mid] < a[mid + 1])){
	      low = mid + 1;  	
   } else {
		high = mid - 1;
   }
 }   	
}

int main(){

 int a[] = { 1, 3, 5, 9, 11, 4, 2 };
 int low = 0;
 int high = 6;	
 binary_search(a, low, high); 	
 int b[] = { 2, 3, 3, 3, 3, 4, 4, 5};
 orig_binary_search(b, low, high, 3);
 int c[] = {6, 7, 8, 3, 4, 5 };
 
 binary_search_circular(c, low, 5, 6);
 binary_search_circular(c, low, 5, 7);
 binary_search_circular(c, low, 5, 8);
 binary_search_circular(c, low, 5, 3);
 binary_search_circular(c, low, 5, 4);
 binary_search_circular(c, low, 5, 5);

}
