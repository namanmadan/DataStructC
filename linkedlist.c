#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *start = NULL;

//Insert into linked list

void insBeg(){
	int data;
	struct node *a=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data to add.\n");
	scanf("%d",&data);
	a->data=data;
	a->link=NULL;
	if(start == NULL){
		start = a;
	}else{
		a->link = start;
		start = a;
	}
	printf("WOW! Inserted\n");
}

void insEnd(){
	struct node *a=start;
	struct node *ne=(struct node *)malloc(sizeof(struct node));
	int data;
	printf("Enter the data to add.\n");
	scanf("%d",&data);
	ne->data = data;
	ne->link = NULL;
	if(start == NULL){
		start = ne;
	}else{
	
		while(a->link!= NULL){
			a=a->link;
		}
		a->link = ne;
	}
	printf("WOW! Inserted\n");
	
}

void insIndex(){
	int index,data;
	int check=0;
	printf("Enter the Index\n");
	scanf("%d",&index);
	if (index == 0){
		insBeg();
	}else{
		if(start == NULL){
			printf("Index Out of range.\n");
		}else{
			printf("Enter the data to add.\n");
			scanf("%d",&data);
			struct node *a=start,*ne=(struct node *)malloc(sizeof(struct node)),*prev;
			ne->data = data;
			ne->link = NULL;
			while(check != index && a->link!=NULL){
				prev=a;
				a=a->link;
				check++;
			}
			if(check == index){
				ne->link = prev->link;
				prev->link = ne;
				printf("WOW! Inserted\n");			
			}else{
				printf("Index Out of range.\n");
				free(ne);
			}
		
		}
	}
}
void insert(){
	system("cls");
	int check;
	printf("Choose where to insert: 1->Beg 2->End 3->By index\n");
	scanf("%d",&check);
	switch(check){
		case 1:insBeg();
			break;
		case 2:insEnd();
			break;
		case 3:insIndex();
			break;
		default: printf("What are you trying to do.\n");
	}
}

//Delete Elements from linked list
void deleteBeg(){
	if(start == NULL){
		printf("There is nothing to delete.\n");
	}else{
		struct node *temp=start;
		start=start->link;
		free(temp);
		printf("WOW! Deleted.\n");
	}	
	
}

void deleteEnd(){
	struct node *a=start,*prev;
	int flag = 0;
	if (start == NULL){
		printf("There is nothing to delete.\n");
	}else{
		while(a->link!=NULL){
			flag=1;
			prev=a;
			a=a->link;
		}
		if (flag == 0){
			start = NULL;
		}else{
			prev->link = NULL;
		}	
	 	free(a);
	 printf("WOW! Deleted.\n");
	}
}

void deleteValue(){
	if (start == NULL){
		printf("There is nothing to delete.\n");
	}else{
		int value,flag=0;
		printf("Enter the value to delete\n");
		scanf("%d",&value);
		struct node *a=start,*prev;
		while(a->data!=value && a->link!=NULL){
			flag = 1;
			prev = a;
			a=a->link;
		}
		if (flag == 0 && start->link == NULL){
			if(a->data == value){
				start = NULL;
				printf("WOW! Deleted.\n");
				free(a);
			}else{
				printf("Element is not present.\n");
			}
		}else{
			if (a->data == value){
				prev->link = a->link;
				printf("WOW! Deleted.\n");
				free(a);
			}else{
				printf("Element is not present.\n");
			}
			
		}
		
	}
}

void deleteIndex(){
	if (start == NULL){
		printf("There is nothing to delete.\n");
	}else{
		int index,count=0;
		printf("Enter the index of element to delete\n");
		scanf("%d",&index);
		if (index == 0){
			deleteBeg();
		}else{
			struct node *a=start,*prev;
			while(count != index && a->link != NULL){
				prev=a;
				a=a->link;
				count++;
			}
			if (count == index){
				prev->link = a->link;
				free(a);
				printf("WOW! Deleted.\n");
			}else{
				printf("Index is out of range.\n");
			}
		}
	}
}


void delet(){
	system("cls");
	int check;
	printf("Choose from where to delete: 1->beg 2->end 3->By value 4->By index\n");
	scanf("%d",&check);
	switch(check){
		case 1:deleteBeg();
			break;
		case 2:deleteEnd();
			break;
		case 3:deleteValue();
			break;
		case 4:deleteIndex();
			break;
		default: printf("What are you trying to do.\n");			
	}
}

//Show the linked list
void show(){
	system("cls");
	struct node *a=start;
	if(start == NULL){
		printf("No Elements Currently Present.\n");
	}else{
		printf("Elements in the linked list are: ");
		while(a!=NULL){
			printf("%d  ",a->data);
			a=a->link;
		}
		printf("\n");
	}
}

int main(){
	int check,cond=1;
	do{
		
		printf("Choose one 1->Insert 2->Delete 3->Show 4->Exit\n");
		scanf("%d",&check);
		switch(check){
			case 1:insert();
				break;
			case 2:delet();
				break;
			case 3:show();
				break;
			case 4:
				break;
			default:printf("Are you serious.\n");
		}
		printf("Do you want to continue. 1->Yes 0->NO\n");
		scanf("%d",&cond);
		system("cls");
	}while(cond);
	return 0;
}
