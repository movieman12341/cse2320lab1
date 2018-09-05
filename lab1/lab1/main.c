#include<stdio.h>

struct node
{
	int value;
	int position;

};

//function protos



int main()
{
	
	struct node nodeArr[5000];

	//input
	int repeat = 1;
	int index = 0;
	while (repeat)
	{
		printf("enter an integer to put in array. Enter     -1     to stop inputting numbers\n");
		int num;
		scanf("%d", &num);

		if (num == -1)
			repeat = 0;//stop loop
		else
		{
			nodeArr[index].value = num;
			nodeArr[index].position = index;
			index++;
		}
	}

	//???????????????????????????????? 5000 ok?		can't find a way to make qsort stable.
	//sort values
	

	

	return 0;
}

