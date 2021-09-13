#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct Stack
{
   char *data;
   int maxSize; // maximum size of the stack.
   int top; //initially size of of the stack is 0.
};
// creating a function to check whether the stack is empty or not.
int isEmpty(struct Stack *stack)
{
   if(stack->top == -1){
      return 1;
   }
   else{
      return 0;
   }
}
// creating a function to check whether the stack is full or not.
int isFull(struct Stack *stack)
{
   if(stack->top == stack->maxSize - 1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
// creating a function to push element into the stack.
char push(struct Stack *stack, char value)
{
   if(isFull(stack))
   {
      printf("\nStack Overflow\n");
   }
   else
   {
      stack->top++;
      stack->data[stack->top] = value;
   }
}
// creating a function to pop top element from the stack.
char pop(struct Stack *stack, char value)
{
   if(isEmpty(stack))
   {
      printf("\nStack Underflow\n");
      return '\0';
   }
   else
   {
      value = stack->data[stack->top];
      stack->top--;
      return value;
   }
}
// creating a function to display the top element of the stack.
int topStack(struct Stack *stack)
{
   int top;
   if (isEmpty(stack))
   {
      printf("\nStack is empty! \n");
   }
   else{
      return top = stack->data[stack->top];
   }
}
int main()
{
   int expressionSize;
   char expression[100];
   struct Stack stackA;
   stackA.top = -1;
   printf("\t\t\t\tWelcome back\n");
   printf("\nEnter the expression : \n");
   gets(expression);
   expressionSize = strlen(expression); // strlen signifies the length of the sring
   stackA.maxSize = expressionSize;     // keeping the size of the stack equal to the expression size
   stackA.data = (char *)malloc(stackA.maxSize * sizeof(char));
   for (int i = 0; i < expressionSize; i++)
   {
      if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
      {
         push(&stackA, expression[i]);
      }
      if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
      {
         if ((stackA.data[stackA.top] == '(' && expression[i] == ')') || (stackA.data[stackA.top] == '{' && expression[i] == '}') || (stackA.data[stackA.top] == '[' && expression[i] == ']'))
         {
            int temp = pop(&stackA, expression[i]);
         }
         else
         {
            return 0;
         }
      }
   }
   if (isEmpty(&stackA))
   {
      printf("\nParenthesis is balanced. \n");
   }
   else
   {
      printf("\nParenthesis is not balanced. \n");
   }
   return 0;
}