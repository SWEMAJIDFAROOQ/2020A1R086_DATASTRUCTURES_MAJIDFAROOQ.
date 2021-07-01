#include <stdio.h>//standard input and output
#include <stdlib.h>//for dynamic allocation of memory
#include <conio.h>//for getch() and system cls()
//function to create a list and inserting items into it!  
int InsertElementsInList(int*arr, int size)     //This Function is used to insert items in the list.
{
    int i;
    for(i=0;i<size;i++)   //for loop for entering the items                   
    {
        scanf("%d",&arr[i]);
    }
    int newsizeoflist=size;
    return newsizeoflist;
}
//function for insertion of item into list 
int insertIntoListAt(int *list, int item, int size,int insertAt)
{
    if(size!=0){
        list = realloc(list,((size+1)*sizeof(int)));//reallocating memory
    }
    int current;// current is the current element in the array or list 
    current=list[insertAt];//list[insertAt] is insertAt where item is going to be inserted
    list[insertAt] = item;
    for(int i=insertAt+1;i<=size;i++){//shifting the elemnts 
        list[i+1] = current;//list[i+1] is the next value in the array or list
        list[i]=current;
        current = list[i+1];
    }
    int newsizeoflist=++size;//increament in the size of the list
    return newsizeoflist;
}
//function to search an item in the list
int search(int *list, int item, int size)
{
    int i, itemtofind = 0;//itemtofind is the item to search for in the list
    for (i = 0; i < size; ++i)
    {
        if (list[i] == item)//in this if statement, if item in the list found then  it will break
        {
            itemtofind = 1;
            break;
        }
    }
    if (itemtofind == 1)//if the searched element is in the insertAt then its will be return as i 
    {
        return i;
    }
    return -1;
}
//function to delete an item in the list
int deletionWithSearch(int *list, int item, int size)
{
    int result;//result is where the value after search is going to be stored
    result = search(list, item, size);//search function calls to search the element in the list
    if (result == -1)//we are taking result as -1 in if condition because we are comapring the insertAt as positive integer if it is in positive  then it performs deletionWithSearch or if it is in negative which is not possible for insertAt then it will return value as NEGATIVE which is not psooible in an array
    {
        return -1;
    }
    for (int i = result + 1; i < size; i++)//deleting the element
    {
        list[i - 1] = list[i];
    }
    int newsizeoflist=size;
    return newsizeoflist - 1;//new size of list after deletion
}
int deletion(int*list, int size, int insertAt){
    int newsizeoflist,i;
    for(i=insertAt ;i <= size-1; i++)
        list[i] = list[i+1];
    newsizeoflist = --size;// size of array decreased after deletion
    return newsizeoflist;
}
//function to display or print the list 
int printarray(int *arr, int size){
    int i;
    for (i=0; i<size; ++i){
        printf("\nlist[%d]=%d",i, *(arr+i)); //printing the list 
    }
    return (i+1);
}
int main()//main function
{
    int choice, sizeoflistA = 0, item, result,insertAt;
    int *listA =  (int *)calloc(1,sizeof(int));//allocating the memory
    do//do-while loop starts(do-while loop verifies the condition after the execution of the statements inside the loop is also called exit controlled loop)
    {
        printf("\nMAKING OF ListA\n\nchoose operation\n");
        printf("\n1. insertion of items in ListA\n2. Insert an item in ListA\n3. Delete and search an item in ListA\n4. Search An item in listA\n5. delete An Item In ListA\n6. View listA\n7. Exit \n");
        choice = (int)getch();//getch() is used to pause output until the key is pressed
        scanf("%d",&choice);
        switch (choice)// switch operator for selecting the operation of the choice
        {
        case 1:

            printf("Enter the size of listA ");
            scanf("%d",&sizeoflistA);
            printf("\nEnter %d items in listA:\n",sizeoflistA);
            sizeoflistA=InsertElementsInList(listA, sizeoflistA);//InsertElementsInList function calls to create a list first
            printarray(listA,sizeoflistA);//printarray function calls to display the list
            printf("\n");
            break;//break statement to terminate the case 
        case 2:
            printf("Enter the item you want to insert\n");
            scanf("%d", &item);
            printf("Enter  where you want to insert\n");
            scanf("%d", &insertAt);
            if(insertAt>sizeoflistA){//if the entered insertAt is greater than the sizeofistA then there is error!
                printf("INVALID INPUT!!!!!\n");
            }
            sizeoflistA = insertIntoListAt(listA, item, sizeoflistA,insertAt);//insertIntoListAt function calls
            printf("\nitem Added at : %d\n",insertAt);
            printf("new list is :\n");
            printarray(listA, sizeoflistA);//priintarray function calls to display the list
            break;
        case 3:
            printf("Enter the item you want to delete\n");
            printf("Current list is :\n");
            printarray(listA, sizeoflistA);//print array function calls to display the list before deletionWithSearch of an item
            printf("\n");
            scanf("%d", &item);
            result = deletionWithSearch(listA, item, sizeoflistA);//deletionWithSearch function calls to delete an item in the list
            if (result == -1 || sizeoflistA == 0)//if the searched value or sizeoflistA is empty then it will not execute
            if (result == -1 || sizeoflistA == 0)//if the searched value or sizeoflistA is empty then it will not execute 
            {
                printf("Element not found or list is empty\n");
                break;
            }
            else
            {
                sizeoflistA = result;
                printf("Element is deleted\n");
            }
            printf("new list is :\n");
            printarray(listA, sizeoflistA);//printarray function calls to display the list
            break;
        case 4:
            printf("Enter the item you want to search:");
            scanf("%d", &item);
            result = search(listA, item, sizeoflistA);//search function calls to search the item in the list
            if (result == -1 || sizeoflistA == 0)//if the searching element is not found then it will not execute 
                printf("Element not found or list is empty");
            else
                printf("Element found at insertAt : %d", result);
            break;
        case 5:
            printf("\nEnter the position of the element to be deleted :\n");
            scanf("%d",&insertAt);
            sizeoflistA = deletion(listA, sizeoflistA,insertAt);
            printarray(listA, sizeoflistA);
            printf("\n\nElement deleted successfully\n\n");
            break;    
        case 6:
            printarray(listA, sizeoflistA);//print array function calls to view the listA
            break;
        case 7:
            printf("press enter to exit the program");
            getch();//waiting for user to enter
            free(listA);//freeing the memory
            exit(0);//successful termination of program
            break;
        default:
            printf("Wrong input!!!!!!!!!");//if the default value is enter then program will be terminated
            break;
        }
        printf("\nPress Enter to continue");
        getch();
    } while (1);//do while loop ends
    return 0;
}