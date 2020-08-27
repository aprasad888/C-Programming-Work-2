/**
 * CS 2110 - Fall 2019 - Homework #9
 *
 * @author Anusha Prasad
 *
 * list.c: Complete the functions!
 */

/**
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!-IMPORTANT-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * For any function that must use malloc, if malloc returns NULL, the function
 * itself should return NULL if needs to return something (or return 0 if
 * the function returns a int).
 */

// Do not add ANY additional includes!!!
#include "list.h"

/* You should NOT have any global variables. */

/* The create_node function is static because this is the only file that should
   have knowledge about the nodes backing the linked List. */
static inline Node *create_node(Pokemon *data);

/** create_node
  *
  * Helper function that creates a Node by allocating memory for it on the heap.
  * Be sure to set its next pointer to NULL.
  *
  * If malloc returns NULL, you should return NULL to indicate failure.
  *
  * @param data a void pointer to data the user wants to store in List
  * @return a Node
  */
static Node* create_node(Pokemon *data)
{
  //UNUSED_PARAMETER(data);

  Node *node = malloc(sizeof(Node)); //using malloc to allocate memory on heap

  if (node == NULL) { //check after allocating
    return NULL;
  }

  (node -> data) = data; //for pointer typedef
  (node -> next) = NULL; //for pointer typedef
  return node;
  //return NULL;
}

/** create_list
  *
  * Creates a struct linked_list by allocating memory for it on the heap.
  * Be sure to initialize size to zero and head and tail to NULL.
  *
  * If malloc returns NULL, you should return NULL to indicate failure.
  *
  * @return a pointer to a new struct list or NULL on failure
  */
LinkedList *create_list(void)
{
  LinkedList *list = malloc(sizeof(LinkedList));

  if (list == NULL) { //check after allocating
    return NULL;
  }

  (list -> size) = 0;
  (list -> head) = NULL;
  return list;
  //return NULL;
}

/** push_front
  *
  * Adds the element at the front of the struct linked_list.
  *
  * @param listToPrependTo a pointer to the struct linked_list structure.
  * @param data the data to add to the struct linked_list.
  * @return 0 if the struct linked_list is NULL, 1 if successful.
  */
int push_front(LinkedList *listToPrependTo, Pokemon *data)
{
  /*UNUSED_PARAMETER(listToPrependTo);
  UNUSED_PARAMETER(data);
  */

  if (listToPrependTo != NULL) {

    Node *front = create_node(data);

      if (front != NULL) {

      if (listToPrependTo -> head != NULL) {

        (front -> next) = (listToPrependTo -> head);
        (listToPrependTo -> head) = front;
        (listToPrependTo -> size)++;
        return 1;
      }

      (listToPrependTo -> head) = front;
      (listToPrependTo -> size)++;
      return 1;
      }
  }
  return 0;
  //return 1;
}

/** push_back
  *
  * Adds the element to the back of the LinkedList.
  *
  * @param listToAppendTo a pointer to the LinkedList structure.
  * @param data the data to add to the LinkedList.
  * @return 0 if the LinkedList is NULL, 1 if successful.
  */
int push_back(LinkedList *listToAppendTo, Pokemon *data)
{
  /*UNUSED_PARAMETER(listToAppendTo);
  UNUSED_PARAMETER(data);
  */

  if (listToAppendTo != NULL) {

    Node *back = create_node(data);

    if (back != NULL) {

    if (listToAppendTo -> head != NULL) {
      Node *currNode = (listToAppendTo -> head);

      while (currNode -> next != NULL) {
        currNode = (currNode -> next);
      }

      (currNode -> next) = back;
      (listToAppendTo -> size)++;
      return 1;
    }

    (listToAppendTo -> head) = back;
    (listToAppendTo -> size)++;
    return 1;
  }
  }
  return 0;
}

/** add_at_index
  *
  * Add the element at the specified index in the LinkedList. This index must lie in
  * the inclusive range [0,size].
  * For example, if you have no elements in the LinkedList,
  * you should be able to add to index 0 but no further.
  * If you have two elements in the LinkedList,
  * you should be able to add to index 2 but no further.
  *
  * @param listToAddTo a pointer to the LinkedList structure
  * @param index 0-based, starting from the head in the inclusive range
  *              [0,size]
  * @param data the data to add to the LinkedList
  * @return 0 if the index is out of bounds or the LinkedList is NULL
  *         (do not add the data in this case)
  *         otherwise return 1
  */
int add_at_index(LinkedList *listToAddTo, Pokemon *data, int index)
{
  /*UNUSED_PARAMETER(listToAddTo);
  UNUSED_PARAMETER(data);
  UNUSED_PARAMETER(index);
  */

  if (listToAddTo != NULL) {

    if (index >= 0 && index <= (listToAddTo -> size)) {

      if ((listToAddTo -> size) != 0) {
        Node *currNode = (listToAddTo -> head);

        int i = 0;
        while (i < index - 1) {
          currNode = (currNode -> next);
          i++;
        }

        Node *temp = create_node(data);
        (temp -> next) = (currNode -> next);
        (currNode -> next) = temp;
        (listToAddTo -> size)++;
        return 1;
      }

      Node *front = create_node(data);
      (listToAddTo -> head) = front;
      (listToAddTo -> size)++;
      return 1;
    }
  }
  return 0;
}

/** get
  *
  * Gets the data at the specified index in the LinkedList
  *
  * @param listToGetDataFrom a pointer to the LinkedList structure
  * @param index 0-based, starting from the head.
  * @param dataOut A pointer to a pointer used to return the data from the
  *        specified index in the LinkedList or NULL on failure.
  * @return 0 if dataOut is NULL or index is out of range of the LinkedList or
  *         the LinkedList is NULL, 1 otherwise
  */
int get(LinkedList *listToGetDataFrom, int index, Pokemon **dataOut)
{
  /*UNUSED_PARAMETER(listToGetDataFrom);
  UNUSED_PARAMETER(index);
  UNUSED_PARAMETER(dataOut);
  */

  if (listToGetDataFrom != NULL && (index >= 0
    && index < (listToGetDataFrom-> size)) && dataOut != NULL) {

    Node *currNode = (listToGetDataFrom -> head);

    int i = 0;
    while (i < index) {
      currNode = (currNode -> next);
      i++;
    }

    *dataOut = (currNode -> data);
    return 1;
  }
  return 0;
}

/** contains
  *
  * Traverses the LinkedList, trying to see if the LinkedList contains some
  * data. We will consider a node to contain the same data if the pokemon at that
  * node has the same name as the pokemon passed in.
  *
  * The "data" parameter may not necessarily point to the same address as the
  * equal data you are returning from this function, it's just data which the
  * comparator (pokemon_eq_name in this case) says is equal.
  *
  * If there are multiple pieces of data in the LinkedList which are equal to
  * the "data" parameter, return the one at the lowest index.
  *
  * Use pokemon_eq_name to compare pokemon structs. Be sure to take a look at that
  * function before you use it! Also be sure not to use pokemon_eq.
  *
  * @param listToSearch a pointer to the LinkedList structure
  * @param data The data, to see if it exists in the LinkedList
  * @param dataOut A pointer to a pointer used to return the data contained in
  *                the LinkedList or NULL on failure
  * @return int    0 if dataOut is NULL, the list is NULL, or the list
  *                does not contain data, else 1
  */
int contains(LinkedList *listToSearch, Pokemon *data, Pokemon **dataOut)
{
  /*
  UNUSED_PARAMETER(listToSearch);
  UNUSED_PARAMETER(data);
  UNUSED_PARAMETER(dataOut);
  */

  if (listToSearch != NULL && dataOut != NULL)
  {
    if ((listToSearch -> size) != 0) {
      Node *currNode = (listToSearch -> head);

      while ((currNode -> next) != NULL) {
        if (pokemon_eq_name((currNode -> data), data) == 0) {
          *dataOut = (currNode -> data);
          return 1;
        }
        currNode = (currNode -> next);
    }

    if (pokemon_eq_name((currNode -> data), data) == 0) {
        *dataOut = (currNode -> data);
        return 1;
    }
    }
    *dataOut = NULL;
  }
  return 0;
}

/** pop_front
  *
  * Removes the List_node at the front of the LinkedList, and returns its data to the user
  *
  * @param listToPopFrom a pointer to the LinkedList.
  * @param dataOut A pointer to a pointer used to return the data in the first
  *                List_node or NULL on failure
  * @return 0 if dataOut is NULL or the LinkedList is NULL or empty, else 1
  */
int pop_front(LinkedList *listToPopFrom, Pokemon **dataOut)
{
  /*UNUSED_PARAMETER(listToPopFrom);
  UNUSED_PARAMETER(dataOut);
  */

  if (listToPopFrom != NULL && ((listToPopFrom -> size) != 0)
    && (dataOut != NULL)) {

    //head *temp = listToPopFrom -> head;
    *dataOut = (listToPopFrom -> head) -> data;

    Node *nHead = (listToPopFrom -> head);
    (listToPopFrom -> head) = (nHead) -> next;
    free(nHead);
    (listToPopFrom -> size)--;
    return 1;
  }
  return 0;
}

/** pop_back
  *
  * Removes the ListNode at the back of the LinkedList, and returns its data to the user
  *
  * @param listToPopFrom a pointer to the LinkedList.
  * @param dataOut A pointer to a pointer used to return the data in the last
  *                ListNode or NULL on failure
  * @return 0 if dataOut is NULL or the LinkedList is NULL or empty, else 1
  */
int pop_back(LinkedList *listToPopFrom, Pokemon **dataOut)
{

  /*UNUSED_PARAMETER(listToPopFrom);
  UNUSED_PARAMETER(dataOut);
  */

  if (listToPopFrom != NULL && (listToPopFrom -> size != 0)
    && dataOut != NULL) {

    if ((listToPopFrom -> size) != 1) {
      Node *currNode = (listToPopFrom -> head);
      //Node *next = currNode -> next;
      while ((currNode -> next) -> next != NULL) {
        currNode = (currNode -> next);
      }

      Node *temp = (currNode -> next);
      *dataOut = (temp -> data);
      (currNode -> next) = (currNode -> next) -> next;
      free(temp);
      (listToPopFrom -> size)--;
      return 1;
    }

    *dataOut = (listToPopFrom -> head) -> data;
    Node *temp2 = (listToPopFrom -> head);
    (listToPopFrom -> head) = (listToPopFrom -> head) -> next;
    free(temp2);
    (listToPopFrom -> size)--;
    return 1;
  }
  return 0;
}


/** remove_at_index
  *
  * Remove the element at the specified index in the LinkedList.
  *
  * @param listToAddTo a pointer to the LinkedList structure
  * @param index 0-based, starting from the head in the inclusive range
  *              [0,size]
  * @param data the data to add to the LinkedList
  * @return 0 if the index is out of bounds, the LinkedList is NULL or
  *         the dataOut is NULL
  *         otherwise return 1
  */
int remove_at_index(LinkedList * listToRemoveFrom, Pokemon ** dataOut, int index)
{
  /*UNUSED_PARAMETER(listToRemoveFrom);
  UNUSED_PARAMETER(dataOut);
  UNUSED_PARAMETER(index);
  */

  if (listToRemoveFrom != NULL &&
    (index >= 0 && index < listToRemoveFrom -> size)
    && ((listToRemoveFrom -> size) != 0) && dataOut != NULL) {

    if (index != 0) {

      if (index != (listToRemoveFrom -> size-1)) {
        Node *currNode = (listToRemoveFrom -> head);

        int i = 0;
        while ((i + 1) < index) {
          currNode = (currNode -> next);
          i++;
        }

        *dataOut = (currNode -> next) -> data;
        Node *temp = (currNode -> next);
        currNode -> next = (currNode -> next) -> next;
        free(temp);
        (listToRemoveFrom -> size)--;
        return 1;
      }
      return pop_back(listToRemoveFrom, dataOut);
    }
    return pop_front(listToRemoveFrom, dataOut);
  }
  return 0;
}

/** empty_list
  *
  * Empties the LinkedList. After this is called, the LinkedList should be
  * empty. This does not free the LinkedList struct itself, just all nodes and
  * data within. Make sure to check that listToEmpty is not NULL before
  * using it.
  *
  * Call pokemon_free to free a pokemon struct.
  *
  * @param listToEmpty a pointer to the LinkedList structure
  */
void empty_list(LinkedList *listToEmpty)
{
  //UNUSED_PARAMETER(listToEmpty);
  /*if (listToEmpty != NULL && (listToEmpty -> size != 0)) {
    Node *currNode = listToEmpty -> head;
    //Node *temp;
    while ((currNode -> next) != NULL) {
  */
  if (listToEmpty != NULL && (listToEmpty -> size) != 0) {
    Node* currNode = (listToEmpty -> head);
    while (currNode != NULL) {
      Node *temp = currNode;
      currNode = (currNode -> next);
      pokemon_free(temp -> data);
      free(temp);
  }
  (listToEmpty -> size) = 0;
  }
  return;
}

/** swap_pokemon
  *
  *
  * Swaps two nodes in the LinkedList. After this is called, the nodes containing the
  * this Pokemon data should be swapped. Make sure you swap the nodes themselves
  * and NOT just the data!
  * Consider all cases! (nodes being side by side, one of the nodes being the head, etc.)
  *
  *     LinkedList *A: A1 -> A2 -> A3 -> A4 -> A5 -> NULL
  *     swap_pokemon(A, A2, A4);
  *     LinkedList *A: A1 -> A4 -> A3 -> A2 -> A5 -> NULL
  *
  * @param poke1 first node to swap
  * @param poke2 second node to swap
  * @return 0 if Pokemon not in list or are NULL or if list is NULL, 1 on successful swap
  */
int swap_pokemon(LinkedList *list, Node *poke1, Node *poke2)
{
  /*
  UNUSED_PARAMETER(list);
  UNUSED_PARAMETER(poke1);
  UNUSED_PARAMETER(poke2);
  */

  if (list == NULL || poke1 == NULL || poke2 == NULL || (list -> size) == 0 || (list -> size) == 1) {
    return 0;
  }

  Pokemon *check1;
  Pokemon *check2;

  if (contains(list, (poke1 -> data), &check1) == 0 || contains(list, (poke2 -> data), &check2) == 0) {
    return 0;
  }

  if (list -> size == 2) {

    Node *temp = (list -> head);
    Node *tempNext = (list -> head) -> next;
    (temp -> next) = NULL;
    (tempNext -> next) = temp;
    (list -> head) = tempNext;
    return 1;
  }

  Node *currNode = (list -> head);
  Node *bef = NULL;
  Node *bef1 = NULL;

  while (currNode != NULL && pokemon_eq_name(currNode -> data, poke1 -> data) != 0) {
    bef = currNode;
    currNode = (currNode -> next);
  }

  Node *fNode = currNode;
  currNode = (list -> head);

  while ((currNode != NULL) && pokemon_eq_name(currNode -> data, poke2 -> data) != 0) {
    bef1 = currNode;
    currNode = (currNode -> next);
  }

  Node *lNode = currNode;

  if (fNode == bef1) {

    if (bef == NULL) {

      Node *var = (lNode -> next);
      (lNode -> next) = fNode;
      (fNode -> next) = var;
      return 1;
    } else {
      Node *var1 = (lNode -> next);
      (lNode -> next) = fNode;
      (fNode -> next) = var1;
      (bef -> next) = lNode;
      return 1;
    }
  }
  if (lNode == bef) {
    if (bef1 == NULL) {
      Node *var2 = (fNode -> next);
      (fNode -> next) = lNode;
      (lNode -> next) = var2;
      return 1;
    } else {
      Node *var3 = (fNode -> next);
      (fNode -> next) = lNode;
      (lNode -> next) = var3;
      (bef1 -> next) = fNode;
      return 1;
    }
  }
  /*
  if (list != NULL && poke2 != NULL && poke1 != NULL
    && (list -> size) != 0 && (list -> size) != 1) {

    Pokemon *check1;
    Pokemon *check2;

    if (contains(list, (poke1 -> data), &check1) != 0
      && contains(list, (poke2 -> data), &check2) != 0) {

      if ((list -> size) != 2) {

        Node *currNode = (list -> head);

        if (pokemon_eq_name((list -> head) -> data, (poke1 -> data)) == 0) {

          while (pokemon_eq_name((currNode -> data), (poke1 -> data)) != 0) {
            currNode = currNode -> next;
          }

          (list -> head) -> next = (currNode -> next);
          (currNode -> next) = (list -> head);
          (list -> head) = currNode;
          return 1;

        Node *currNode1 = list->head;
        if (pokemon_eq_name((list -> head) -> data, (poke2 -> data)) == 0) {

          while (pokemon_eq_name((currNode -> data), (poke1 -> data)) != 0) {
            currNode = currNode -> next;
          }

          (list -> head) -> next = (currNode -> next);
          (currNode -> next) = (list -> head);
          (list -> head) = currNode;
          return 1;
        }

        Node *temp1 = (list -> head);
        Node *temp2 = (list -> head);

        while (pokemon_eq_name(((temp1 -> next)) -> data,
          (poke1 -> data)) != 0) {
          temp1 = (temp1 -> next);
        }

        while (pokemon_eq_name(((temp2 -> next)) -> data,
          (poke2 -> data) != 0) {
          temp2 = (temp2 -> next);
        }

        if (pokemon_eq_name((temp2 -> data),
          ((temp2 -> next) -> next) -> data)) {
            ((temp2 -> next) -> next) = (temp1 -> next);
            (temp1 -> next) = (temp2 -> next);
            (temp2 -> next) = temp1;
            return 1;
        }

        if (pokemon_eq_name((temp2 -> data),
          ((temp1 -> next) -> next) -> data)) {
            ((temp1 -> next) -> next) = (temp2 -> next);
            (temp2 -> next) = (temp1 -> next);
            (temp1 -> next) = temp2;
            return 1;
        }
      }
      */
  Node *var = (lNode -> next);
  (lNode -> next) = (fNode -> next);
  (fNode -> next) = var;

  if (bef != NULL && bef1 != NULL) {
    (bef -> next) = lNode;
    (bef1 -> next) = fNode;
    return 1;
  }
  if (bef == NULL && bef1 != NULL) {
    (list -> head) = lNode;
    (bef1 -> next) = fNode;
    return 1;
  }
  if (bef == NULL && bef1 != NULL) {
    (list -> head) = fNode;
    (bef -> next) = lNode;
    return 1;
  }

  return 0;

}

/** zip
  *
  *
  * Zips two Lists together. After this is called, the first list should
  * have the elements from both lists and the second list should be empty.
  * Do not free the second list. Both Lists might be empty. If either list
  * is NULL, just return.
  *
  *     LinkedList *A: A1 -> A2 -> A3 -> A4 -> A5 -> NULL
  *
  *     LinkedList *B: B1 -> B2 -> B3 -> NULL
  *
  *     zip(A, B): A1 -> B1 -> A2 -> B2 -> A3 -> B3 -> A4 -> A5 -> NULL
  *
  * @param team1 first LinkedList to zip together
  * @param team2 second LinkedList to zip together
  */
void zip(LinkedList *team1, LinkedList *team2)
{
  /*UNUSED_PARAMETER(team1);
  UNUSED_PARAMETER(team2);
  */

  if (team1 == NULL || team2 == NULL) {
    return;
  }
  if ((team1 -> size) == 0 && (team2 -> size) == 0) {
    return;
  }
  if ((team1 -> size) != 0 && (team2 -> size) == 0) {
    return;
  }
    if (team1 -> size == 0 && team2 -> size != 0) {
      (team1 -> size) = (team2 -> size);
      (team1 -> head) = (team2 -> head);
      (team2 -> size) = 0;
      (team2 -> head) = NULL;
      return;
    }
    Node *currNode = (team1 -> head);
    Node *temp = (team2 -> head);

       int i = 0;
       while (i < (team1 -> size)) {
           if ((temp -> next) != NULL) {
            Node *var = temp;
            temp = (temp -> next);
            (var -> next) = (currNode -> next);
            (currNode -> next) = var;
            (currNode) = (currNode -> next) -> next;
          } else if (temp != NULL) {
            Node *var = temp;
            temp = NULL;
            (var -> next) = (currNode -> next);
            (currNode -> next) = var;
          }
          i++;
        //(currNode -> next) = temp;
        }
        /*
        Node *var = (currNode -> next);
        Node *var2 = (temp -> next);
        (temp -> next) = (currNode -> next);
        (currNode -> next) = temp;
        currNode = var;
        temp = var2;
        */
        (team1 -> size) = (team2 -> size) + (team1 -> size);
        (team2 -> size) = 0;
        (team2 -> head) = NULL;
}
