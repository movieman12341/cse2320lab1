#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	int position;

};

//function protos
int valueSort(const void *a, const void *b);
int positionSort(const void *a, const void *b);
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
	qsort((void*)nodeArr, numElements, sizeof(nodeArr[0]), valueSort);

	int newNumElements = removeDups(nodeArr, numElements);
	
	qsort((void*)nodeArr, newNumElements, sizeof(nodeArr[0]), positionSort);


	//output
	printf("\n\n%d\n", newNumElements);
	for (i = 0; i < newNumElements; i++)
	{
		printf("%d\n", nodeArr[i].value);
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

int positionSort(const void * a, const void * b)
{
	int l = ((struct node*) a)->position;
	int r = ((struct node*) b)->position;
	return l - r;
}

int removeDups(struct node * nArr, int nElements)
{
	int i = 0, j = 1, index = 0;
	for (; i < nElements; i++)
	{
		if (nElements == 1 || nElements == 0)//already sorted
			return;


		else if (nArr[j].value != nArr[index].value)//j value != value of last array element in correct position
		{
			index++;
			nArr[index].value = nArr[j].value;
			nArr[index].position = nArr[j].position;
			j++;
			
		}
		else
		{
			j++;
		}
	}

	return index;
}