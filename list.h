/* list.h   ADT: sigle linked list (with header:dummy node)
*/

#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType; 

List MakeEmpty( List L);
int IsEmpty( List L);
int IsLast( Position P, List L);
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
Position FindPrevious( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void DeleteList( List L);
Position Header( List L);
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );
int printNode( List L);
int printSll( List L );

struct Node{
	ElementType Element;
	Position Next;
};

#endif