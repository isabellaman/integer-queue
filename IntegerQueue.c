/*
 * Linked List implementation of Integer Queue ADT in C
 */
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include"IntegerQueue.h"

// Exported type --------------------------------------------------------------

// NodeObj type
typedef struct NodeObj {
   int item;
   struct NodeObj* next;
} NodeObj;

// Node type
typedef NodeObj* Node;

// IntegerQueue
// Exported reference type
typedef struct IntegerQueueObj* IntegerQueue;

// IntegerQueueObj
typedef struct IntegerQueueObj{
   int numItems;      // number of items in this IntegerQueue
   Node front; 
   Node back;
} IntegerQueueObj;

// newNode()
// constructor for the Node type
Node newNode(int x) {
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   N->item = x;
   N->next = NULL;
   return N;
}

// destructor for the Node type
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// freeAllNodes()
// uses recursion to free all the Nodes in list headed by H
void freeAllNodes(Node H){
   if( H!=NULL ){
      freeAllNodes(H->next);
      freeNode(&H);
   }
}

// Constructors-Destructors ---------------------------------------------------

// newIntegerQueue()
// Constructor for the IntegerQueue ADT
IntegerQueue newIntegerQueue() {
   IntegerQueue Q = malloc(sizeof(IntegerQueueObj));
   Q->numItems = 0;
   Q->front = NULL;
   Q->back = NULL;
   return Q;
}

// freeIntegerQueue()
// Destructor for the Queue ADT
void freeIntegerQueue(IntegerQueue* pQ){
   if( pQ != NULL && *pQ != NULL ){
      //dequeueAll(pQ);
      free(*pQ);
      *pQ = NULL;
   }
}

// ADT operations -------------------------------------------------------------

// isEmpty()
// Returns 1 (true) if Queue Q is empty, 0 (false) otherwise.
int isEmpty(IntegerQueue Q) {
   if( Q==NULL ){
      fprintf(stderr, "IntegerQueue Error: isEmpty() called on NULL "\
                      "IntegerQueue reference");
      exit(EXIT_FAILURE);
   }
   if(Q->numItems == 0) {
      return 1;
   }
   else {
      return 0;
   }
}

// length()
// Returns the number of elements in Q
int length(IntegerQueue Q) {
   if( Q==NULL ){
      fprintf(stderr, "IntegerQueue Error: length() called on NULL "\
                      "IntegerQueue reference");
      exit(EXIT_FAILURE);
   }

   return Q->numItems;
}


// enqueue()
// Inserts x at back of Q.
void enqueue(IntegerQueue Q, int x){
   Node B = newNode(x);

   if (Q->front == NULL) {	//Queue is empty
      Q->front = Q->back = B;
   }
   else {			         //Queue is non-empty
      Q->back->next = B;
      Q->back = B;
   }

   Q->numItems++;
}

// dequeue()
// Deletes and returns the item at front of Q.
// Pre: !isEmpty()
int dequeue(IntegerQueue Q) {
   int x;
   Node N;
   if (Q->front == NULL) {
      fprintf(stderr, "cannot dequeue() empty queue\n");
      exit(EXIT_FAILURE);
   }
   
   x = Q->front->item;
   N = Q->front;
   if (Q->front == Q->back) {
      Q->front = Q->back = NULL;
   }
   else {
      Q->front = Q->front->next;
   }
   freeIntegerQueue(&N);
   Q->numItems--;
   return x;
}

// peek()
// Returns the item at front of Q.
// Pre: !isEmpty()
int peek(IntegerQueue Q) {
   if(Q == NULL){
      fprintf(stderr, "IntegerQueue Error: peek() called on NULL "\
                      "IntegerQueue reference");
      exit(EXIT_FAILURE);
   }
   if (isEmpty != 1) { 
      Node N = Q->front;
      return N->item;
   }
}

// dequeueAll()
// Resets Q to the empty state.
void dequeueAll(IntegerQueue Q) {
   if( Q==NULL ){
      fprintf(stderr, "IntegerQueue Error: dequeueAll() called on NULL "\
                      "IntegerQueue reference");
      exit(EXIT_FAILURE);
   }

   freeAllNodes(Q->front);
   Q->front = NULL;
   Q->back = NULL;
   Q->numItems = 0;
}


// Other Operations -----------------------------------------------------------
// IntegerQueueToString()
char* IntegerQueueToString(IntegerQueue Q) {
   char* str;
   if (Q == NULL) {
      fprintf(stderr,
         "IntegerList Error: IntegerQueueToString() called on NULL IntegerList reference\n");
      exit(EXIT_FAILURE);
   }

   int length = 0;
   if (Q->front != NULL) {
      str = malloc((Q->numItems * 2) * sizeof(int));
      Node T;
      T = Q->front;

      while(T->next != NULL) {
         int val = T->item;
         length += sprintf(str+length, "%d ", val);
         T = T->next;
      }
      int val = T->item;
      length += sprintf(str+length, "%d", val);
   }

   return str;
}

// equals()
// Returns true (1) if Q and R are matching sequences of integers, false (0)
// otherwise.
int equals(IntegerQueue Q, IntegerQueue R) {
   int eq;
   Node N;
   Node M;
   if(Q == NULL ||R == NULL){
      fprintf(stderr, 
         "IntegerList Error: equals() called on NULL IntegerList reference\n");
      exit(EXIT_FAILURE);
   }

   eq = ( (Q->numItems)==(R->numItems) );
   N = Q->front;
   M = R->front;
   while( eq && N!=NULL ){
      eq = ( (N->item)==(M->item) );
      N = N->next;
      M = M->next;
   }
   return eq;
}
