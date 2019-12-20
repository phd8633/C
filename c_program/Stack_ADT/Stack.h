#ifndef Stack_h
#define Stack_h

#define EmptyToS (-1)
#define MinStackSize (5)
#define FullToS (1000-1)
#define Error printf
#define ElementType int 

struct StackRecord;
typedef struct StackRecord * Stack;
int IsEmpty( Stack S);
int IsFull( Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType x, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);


#endif  /****__stack_h***/

/**********************************************************
/*Palce in implementation file */
/*Stack implementation is a dynamically allocated array*/
/*Modification time : 2019-11-1 */
/*Author :863315351@qq.com,phd1998.wicp.vip*/
/**********************************************************

#define EmptyToS (-1)
#define MinStackSize (5)
#define FullToS (1000-1)
#define Error printf
#define ElementType int 

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
	Stack S;

	if(MaxElements<MinStackSize)
		Error( "Stack size is too small");

	S = malloc(sizeof(struct StackRecord));
	if(S==NULL)
		FatalError( "Out of space!!!");
	
	S->Array = malloc(sizeof(ElementType)* MaxElements);
	if(S->Array==NULL)
		FatalError( "Out of space!!!");

	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void DisposeStack(Stack S)
{
	if(S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyToS;
}
int IsFull(Stack S)
{
	return S->TopOfStack == FullToS;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyToS;
}

void Push(ElementType x,Stack S)
{
	if(IsFull(S))
		Error("Full stack");
	else 
		S->Array[++S->TopOfStack] = x;
}

ElementType Top(Stack S)
{
	if(IsEmpty(S))
		Error("Empty stack");
	else
		return S->Array[S->TopOfStack];
	return 0;	
}
void Pop(Stack S)
{
	if(IsEmpty(S))
		Error("Empty stack");
	else
		S->TopOfStack--;
}
ElementType TopAndPop(Stack S)
{
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	Error("Empty stack");
	return 0;
}


***************************************************/