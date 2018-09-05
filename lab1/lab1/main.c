#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	int position;

};

//function protos
int valueSort(const void *a, const void *b);
int removeDups(struct node * nArr, int nElements);

int main()
{
	printf("How many elements do you want?\n");
	int numElements;
	scanf("%d", &numElements);

	struct node *nodeArr = (struct node*) calloc(numElements, sizeof(struct node));

	int i = 0;
	for (; i < numElements; i++)
	{
		printf("Enter an integer\n");
		int num;
		scanf("%d", &num);
		nodeArr[i].value = num;
		nodeArr[i].position = i;
	}
	//initial value sort
	qsort((void*)nodeArr, numElements, sizeof(nodeArr[0]), valueSort);
	
	//after sorting
	printf("after sorting.\n\n");
	for (i = 0; i < numElements; i++)
	{
		printf("%d %d\n", nodeArr[i].value, nodeArr[i].position);
	}

	//remove extras
	removeDups(nodeArr, numElements);
	printf("remove extras\n\n");
	for (i = 0; i < numElements; i++)
	{
		printf("%d %d\n", nodeArr[i].value, nodeArr[i].position);
	}



	free(nodeArr);
	nodeArr = NULL;
	return 0;
}

int valueSort(const void * a, const void * b)
{
	int l = ((struct node*) a)->value;
	int r = ((struct node*) b)->value;
	int value = l - r;

	if (value == 0)//both a and b are equal
	{
		return ((struct node*) a)->position - ((struct node*) b)->position;
	}
	else
		return value;
}


int removeDups(struct node * nArr, int nElements)
{
	/*
	for i < nelements-1
		cmp j to j+1 value
		if != values
			a[i++] = a[j++]

		else if (== values
			a[i] = 1st value of dup
			
	*/



	int i = 0, j = 0;
	for (; i < nElements - 1; i++)
	{
		if (nElements == 1 || nElements == 0)
			return;


		else if (nArr[j].value != nArr[j+1].value)
		{
			nArr[i] = nArr[j++];
		}
		else//== values
		{
			nArr[i].value = nArr[j++].value;
		}
	}
	nArr[j++].value = nArr[nElements - 1].value;
}