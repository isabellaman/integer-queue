/*
 * Test client for the IntegerQueue ADT
 */
#include<stdio.h>
#include<stdlib.h>
#include"IntegerQueue.h" 

int main(){
   char* test;

   IntegerQueue first = newIntegerQueue();
   enqueue(first, 1);
   enqueue(first, 2);
   enqueue(first, 3);
   enqueue(first, 4);
   enqueue(first, 5);
   enqueue(first, 6);
   enqueue(first, 7);
   enqueue(first, 8);
   
   test = IntegerQueueToString(first);
   printf("%s\n", test);
   free(test);

   IntegerQueue second = newIntegerQueue();
   enqueue(second, 234);

   printf("%s\n", equals(first, second)?"true":"false");

   dequeueAll(second);
   printf("%s\n", isEmpty(A)?"true":"false");

   test = IntegerQueueToString(second);
   printf("%s\n", test);
   free(test);

   freeIntegerQueue(&first);
   freeIntegerQueue(&second);

   return EXIT_SUCCESS;
}
