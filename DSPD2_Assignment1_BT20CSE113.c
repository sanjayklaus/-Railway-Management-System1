#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct DATES
{
    int day;
    int month;
    int year;
}DATES;

typedef struct passenger_tag
{
    char name[20];
    int id;
    char train[50];
    char station[50];
    char Class[10];
    char dest[50];
    DATES date;
    int train_id;
    int seat_no;
    int bogie_no;
    struct passenger_tag *next;
}passenger;
passenger *head=NULL;

void insert(passenger** head,int id,char train[],char station[],char Class[],char dest[],DATES date,int train_id,int seat_no,int bogie_no)
{
    passenger *temp,*temp1;
    temp=(passenger*)malloc(sizeof(passenger));
    temp->id=id;
    strcpy(temp->train,train);
    strcpy(temp->station,station);
    strcpy(temp->Class,Class);
    strcpy(temp->dest,dest);
    temp->date=date;
    temp->train_id=train_id;
    temp->seat_no=seat_no;
    temp->bogie_no=bogie_no;
    if(*head==NULL)
        {
            *head=temp;
        }
        else
        {
            temp1=*head;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            temp1->next=temp;
        }
}
void display(passenger* head)
{
    passenger *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("Name: %s\n",temp->name);
        printf("Id: %d\n",temp->id);
        printf("Train: %s\n",temp->train);
        printf("Date: %s\n",temp->date);
        printf("Station: %s\n",temp->station);
        printf("Class: %s\n",temp->Class);
        printf("Destination: %s\n",temp->dest);
        printf("Train id: %s\n",temp->train_id);
        printf("Seat number: %d\n",temp->seat_no);
        printf("Bogie number: %d\n",temp->bogie_no);
        temp=temp->next;
    }
}
void delete(passenger** head,int id)
{
    passenger *temp,*temp1;
    temp=*head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            if(temp==*head)
            {
                *head=temp->next;
                free(temp);
                break;
            }
            else
            {
                temp1=*head;
                while(temp1->next!=temp)
                {
                    temp1=temp1->next;
                }
                temp1->next=temp->next;
                free(temp);
                break;
            }
            printf("\nDeleted Successfully\n");
        }
        else
        {
            temp=temp->next;
            printf("\nNo such id found\n");
        }
    }
}
void getListDestination(passenger** head,char dest[],int train_id)
{
    passenger *temp;
    temp=*head;
    if(*head==NULL)
    {
        printf("\nNo passengers found\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(strcmp(temp->dest,dest)==0 && temp->train_id==train_id)
            {
                printf("\nName: %s\n",temp->name);
                printf("Id: %d\n",temp->id);
                printf("Train: %s\n",temp->train);
                printf("Date: %s\n",temp->date);
                printf("Station: %s\n",temp->station);
                printf("Class: %s\n",temp->Class);
                printf("Destination: %s\n",temp->dest);
                printf("Train id: %s\n",temp->train_id);
                printf("Seat number: %d\n",temp->seat_no);
                printf("Bogie number: %d\n",temp->bogie_no);
            }
            temp=temp->next;
        }
    }
}
void swap(passenger* current, passenger* index)
{
    char* char_temp=(char*)malloc(sizeof(char)*100);
	int int_temp ;
     //	// passeneegr id 
    int_temp = current->id;  
    current->id = index->id;  
    index->id = int_temp;
    	// train id
    int_temp = current->train_id;  
    current->train_id = index->train_id;  
    index->train_id = int_temp; 
    //    // destination 
    strcpy(char_temp,current->dest);
    strcpy(current->dest,index->dest);
    strcpy(index->dest,char_temp);
    // date
       int_temp = current->date.day;  
       current->date.day = index->date.day;  
       index->date.day = int_temp;
       
       int_temp = current->date.month;  
       current->date.month = index->date.month;  
       index->date.month = int_temp;
       
       int_temp = current->date.year;  
       current->date.year = index->date.year;  
       index->date.year = int_temp;
}
int compare_date(DATES D1,DATES D2)
{
    if (D1.year < D2.year)
       return -1;

    else if (D1.year > D2.year)
       return 1;

    if (D1.year == D2.year)
    {    
         if (D1.month<D2.month)
              return -1;
         else if (D1.month>D2.month)
              return 1;
         else if (D1.day<D2.day)
              return -1;
         else if(D1.day>D2.day)
              return 1;
         else
              return 0;
    }
}
void SortByTravelDate(passenger** head)
{
    passenger *temp,*temp1;
    temp=*head;
    temp1=NULL;
    if(*head==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            temp1=temp->next;
            if(temp1!=NULL)
            {
                while(temp1!=NULL)
                {
                    if(compare_date(temp->date,temp1->date)==1)
                    {
                        swap(temp,temp1);
                    }
                    temp1=temp1->next;
                }
            }
            temp=temp->next;
        }
    }
}
void SortTrains(passenger *head,int train_id)
{
    passenger *temp,*temp1;
    temp=head;
    temp1=NULL;
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            temp1=temp->next;
            if(temp1!=NULL)
            {
                while(temp1!=NULL)
                {
                    if(temp->train_id<temp1->train_id)
                    {
                        swap(temp,temp1);
                    }
                    temp1=temp1->next;
                }
            }
            temp=temp->next;
        }
    }
}
void promotePassengers(passenger** head,int train_id,DATES date,char dest[])
{
    passenger *temp,*temp1;
    temp=*head;
    if(*head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        while(temp!=NULL)
       {
            temp1=temp->next;
            while(temp1!=NULL)
            {
                if((temp->train_id = temp1->train_id) && compare_date(temp->date,temp1->date)==0)
                {
                    if(strcmp(temp->Class,"Sleeper")==0 && strcmp(temp->dest,dest)==0)
                    {
                        if(temp->seat_no<=3 && temp1->seat_no<=3)
                        {
                            strcpy(temp->Class,"3AC");
                            temp->seat_no=temp1->seat_no;
                            temp->bogie_no=temp1->bogie_no;
                        }
                    }
                    else if(strcmp(temp->Class,"3AC")==0 && strcmp(temp->dest,dest)==0)
                    {
                        if(temp->seat_no<=2 && temp1->seat_no<=2)
                        {
                            strcpy(temp->Class,"2AC");
                            temp->seat_no=temp1->seat_no;
                            temp->bogie_no=temp1->bogie_no;
                        }
                    }
                    else if(strcmp(temp->Class,"2AC")==0 && strcmp(temp->dest,dest)==0)
                    {
                        if(temp->seat_no<=1 && temp1->seat_no<=1)
                        {
                            strcpy(temp->Class,"1AC");
                            temp->seat_no=temp1->seat_no;
                            temp->bogie_no=temp1->bogie_no;
                        }
                    }
                }
                temp1=temp1->next;
            }   
            temp=temp->next;
        }
    }    
    
}

int main()
{
    passenger *head=NULL;
    int choice,num;
    char name[20],train[50],station[50],Class[10],dest[50];
    int id,train_id,seat_no,bogie_no;
    DATES date;
    while(1)
    {
        printf("\n1.Add passenger\n2.Delete passenger\n3.Display passenger\n4.Sort by travel date\n5.Sort by train id\n6.Promote passengers\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter No.of passengers : ");
                scanf("%d",&num);
                for(int i=0;i<num;i++)
                {
                    printf("\nEnter passenger Id: ");
                    scanf("%d",&id);
                    printf("\nEnter passenger name: ");
                    scanf("%s",name);
                    printf("\nEnter train id: ");
                    scanf("%s",train_id);
                    printf("\nEnter the train name: ");
                    scanf("%s",train);
                    printf("\nEnter the station: ");
                    scanf("%s",station);
                    printf("\nEnter destination: ");
                    scanf("%s",dest);
                    printf("\nEnter date(dd/mm/yyyy): ");
                    scanf("%d/%d/%d",&date.day,&date.month,&date.year);
                    printf("\nEnter seat number: ");
                    scanf("%d",&seat_no);
                    printf("\nEnter bogie number: ");
                    scanf("%d",&bogie_no);
                    printf("\nEnter class: ");
                    scanf("%s",Class);
                    insert(&head,id,train,station,Class,dest,date,train_id,seat_no,bogie_no);
                }
                break;
            case 2:
                printf("\nEnter passenger id:");
                scanf("%d",&id);
                delete(&head,id);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("\n        Inside the Sort by travel date          ");
                SortByTravelDate(&head);
                break;
            case 5:
                printf("Enter train id: ");
                scanf("%d",train_id);
                SortTrains(head,train_id);
                break;
            case 6:
                printf("Enter train id: ");
                scanf("%d",train_id);
                printf("Enter date(dd/mm/yyyy): ");
                scanf("%d/%d/%d",&date.day,&date.month,&date.year);
                printf("Enter destination: ");
                scanf("%s",dest);
                promotePassengers(&head,train_id,date,dest);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }
}