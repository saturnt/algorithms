#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;	
};

int insert_node(struct node **node, int data){
		
	if(*node == NULL){
	   *node = malloc(sizeof(struct node));
           (*node)->data = data;		 			
	   (*node)->left = NULL;
	   (*node)->right = NULL;
	   return 0;	
	}
	
	struct node *curr_node = *node;
	struct node *parent_node = *node;
	while(curr_node != NULL){
	   parent_node = curr_node; 		
	   if(curr_node->data > data){
		curr_node = curr_node->left;
	   } else {
		curr_node = curr_node->right;
	   }	
	}

	//Now we found a place to insert.

	if(curr_node == NULL && parent_node){
		curr_node = malloc(sizeof(struct node));
		curr_node->data = data;				
		curr_node->left = NULL;
		curr_node->right = NULL;
		if(parent_node->data > data){
		  parent_node->left = curr_node;		   	
		} else {
		  parent_node->right = curr_node;
		}
	}	
 return 0;
}

int search_node(struct node *node, int data){
    	
    while(node != NULL){
	if(node->data == data){
	   printf("Found the node %d\n", data);	
	   return 0;	
	} else if(node->data > data){
	     node= node->left;		
	} else {
	     node = node->right;	
	}	
    }  
	
   printf("Node Data %d not found\n", data);
   return 0;	 	
}

int traverse_binary_tree(struct node *node){
   
    if(node == NULL){
	return 0;
    }	

    traverse_binary_tree(node->left);	
    printf("%d\n", node->data);	
    traverse_binary_tree(node->right);

} 

int search_and_ret_node(struct node *node, int data, struct node **parent, struct node **found_node){

    *parent = node;	
    while(node != NULL){

        if(node->data == data){
           printf("Found the node %d\n", data);
	   *found_node = node;	
           return 0;
        } 
	*parent = node;
	if(node->data > data){
             node= node->left;
        } else {
             node = node->right;
        }
    }
	
   printf("Node Data %d not found\n", data);
   return 0;
}

int find_smallest_in_right_subtree(struct node *node){

	while(node && (node->left != NULL)){
	  node = node->left;
	}
	
	return (node->data);
}

int delete_node(struct node **node, int data){
	
     // Search for the node data, and get the node and the parent.		
     struct node *parent = NULL;
     struct node *found_node = NULL;
     search_and_ret_node(*node, data, &parent, &found_node);		  	
     printf("parent = %p parent->data = %d node = %p found_node->data = %d\n", parent, parent->data, found_node, found_node->data);

     if((found_node->left == NULL) && (found_node->right == NULL)){
	if(parent->data > data){
	  // My node to be deleted would be on the left side.	
	  parent->left = NULL;	  
	} else {
	  parent->right = NULL;	
	}
	free(found_node);	
	return 0;	
     } else if(found_node->left == NULL){        
	if(parent->data > data){
          // My node to be deleted would be on the left side.   
          parent->left = found_node->right;
        } else {
          parent->right = found_node->right;
        }
	free(found_node);
	return 0;				
     } else if(found_node->right == NULL){
        if(parent->data > data){
          // My node to be deleted would be on the left side.   
          parent->left = found_node->left;
        } else {
          parent->right = found_node->left;
        }
        free(found_node);
	return 0;	
     }else {

	// This is a tricky case: Here we would need to find the smallest element in the right subtree.	
	int returned_data = find_smallest_in_right_subtree(found_node->right);	
	printf("Smallest in right subtree is %d\n", data);
	// Replace the found_node->data with the new data, We dont need to delete that node, Just override.	
	found_node->data = returned_data;
	// Now lets delete the node containing the returned_data.
	delete_node(&found_node->right, returned_data);
    }	

    return 0;	
}


int main(){
   struct node *root;
   insert_node(&root, 10);
   insert_node(&root, 15);
   insert_node(&root, 5);
   insert_node(&root, 25);
   insert_node(&root, 13);
   insert_node(&root, 12);
   insert_node(&root, 14);
   insert_node(&root, 29);
   insert_node(&root, 22);
   insert_node(&root, 24);
   search_node(root, 15);
   search_node(root, 50);
   traverse_binary_tree(root);	 
   delete_node(&root, 15);	
   traverse_binary_tree(root);	
   return 0;		
}
