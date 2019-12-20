#include "stdio.h"
#include "Stack.h"


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

int main()
{
    Stack S = CreateStack(10);
    MakeEmpty(S);
    for(int i=1;i<=10;i++)
        Push(i,S);
    for(int i=1;i<=10;i++)
        printf("%d",TopAndPop(S));
    DisposeStack(S);
    

}