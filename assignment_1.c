// C program for finding the cheapest walnut in Raghunath bazaar of Jammu
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Shop
{
    int price;
    int shopNumber;
    struct Shop *next;
};
struct Shop *head = NULL;

// Function to traverse the linked list
void printList() // Function to print the linked list
{
    struct Shop *temp = (struct Shop *)malloc(sizeof(struct Shop ));

    // condition for empty list
    if (head == NULL) // condition to check if the list is empty or not
        printf("\nList is empty\n");

    // Else print the LL
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("Shop Number --> %d Shop Price -->  %d -------> ",temp->shopNumber, temp->price);
            temp = temp->next;
        }
        printf("NULL");
    }
}
int linearSearch(int searchElement) // function for searching an element in the LL
{
    struct Shop *temp = head;
    int position = INT_MIN, i = 1;
    while (temp != NULL)
    {
        if (temp->shopNumber == searchElement)
        {
            position = i;
        }
        i++;
        temp = temp->next;
    }
    return position;
}
void insertShop(int element, int shopNumber)
{
    struct Shop *temp;
    temp = (struct Shop *)malloc(sizeof(struct Shop));

    temp->price = element;
    temp->shopNumber = shopNumber;
    temp->next = head;
    head = temp;
}

int deleteShop(int shopNumber)
{
    struct Shop *ptr, *temp;
    int i = 1, pos, removedElement;

    if (head == NULL) // condition to check if the list is empty or not
    {
        printf("\nList is empty\n");
    }

    else
    {
        pos = linearSearch(shopNumber);
        if (pos == INT_MIN)
        {
            return INT_MIN;
        }
        else
        {
            temp = (struct Shop *)malloc(sizeof(struct Shop));

            if (pos == 1)
            {
                // deleteFirst(element);
                temp = head;
                head = head->next;
                removedElement = temp->shopNumber;
                free(temp);
            }
            else
            {
                ptr = head;
                while (i < pos - 1)
                {
                    ptr = ptr->next;
                    i++;
                }
                temp = ptr->next;
                ptr->next = temp->next;
                removedElement = temp->shopNumber;
                free(temp);
            }
            return removedElement;
        }
    }
}
// Function to sort LinkedList the linked list in ascending order
void sortLinkedList()
{
    struct Shop *ptr = head;
    struct Shop *index = NULL;
    int temp,tempShop;

    // If LL is empty
    if (head == NULL)
    {
        printf("The list is empty\n");
    }

    // Else
    else
    {

        // Traverse the LL
        while (ptr != NULL)
        {
            index = ptr->next;

            // Traverse the LL nestedly and find the minimum element
            while (index != NULL)
            {

                // Swap with it the value at ptr
                if (ptr->price > index->price)
                {
                    temp = ptr->price;
                    ptr->price = index->price;
                    index->price = temp;
                    tempShop = ptr->shopNumber;
                    ptr->shopNumber = index->shopNumber;
                    index->shopNumber = tempShop;

                }
                index = index->next;
            }

            // Update the ptr
            ptr = ptr->next;
        }
    }
}
void cheapestWalnuts()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        sortLinkedList();
        printf("The cheapest rate of the almonds is %d available at the Shop Number %d ", head->price,head->shopNumber);
    }
}
int main()
{
    int choice, shopPrice, deleteElement, temp,shopNumber;
    do
    {
        printf("\nEnter the operation you want to perform\nPress 1 For inserting the Shop Details\nPress 2 For deleting Shop Details\nPress 3 For printing the details of the registered Shops\nPress 4 For getting the cheapest walnuts\nPress 5 to exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Shop Number\n");
            scanf("%d",&shopNumber);
            printf("Enter the price of Walnuts\n");
            scanf("%d", &shopPrice);
            insertShop(shopPrice,shopNumber);

            break;
        case 2:
            if (head == NULL)
            {
                printf("The list is empty\n");
            }
            else
            {
                printf("Enter the Shop Number you want to delete\n");
                scanf("%d", &deleteElement);
                temp = deleteShop(deleteElement);
                if (temp == INT_MIN)
                {
                    printf("Shop Number %d is not registered yet and cannot be deleted\n", deleteElement);
                }
                else
                {
                    printf("Details of Shop Number %d was deleted successfully\n", temp);
                }
            }

            break;
        case 3:
            printList();
            break;
        case 4:
            cheapestWalnuts();
            break;
        case 5:
            printf("Quitting the program\n");
            break;
        default:
            printf("Please enter from the above options\n");
        }
    } while (choice != 5);
    return 0;
}