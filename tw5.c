#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

typedef struct
{
	int custid;
	char custname[30];
	int custphno;
	int empty;
}CUST;



int HashFn(int key)
{
	return (key % SIZE);
}

int Search(int key, CUST custs[])
{
	int count, pos;
    pos = HashFn(key);

	for(count = 1; count <= SIZE ; count++)
	{
		if(custs[pos].empty == 1)
			return -1;

		if(custs[pos].custid == key)
			return pos;

		pos = (pos + 1) % SIZE;
	}
	return -1;
}

void InsHT_LP(CUST cust, CUST custs[])
{
	int count, pos, flag=0;
	int key = cust.custid;
	pos = HashFn(key);

	for(count = 1; count <= SIZE; count++)
	{
		if(custs[pos].empty == 1)
		{
		    if(flag==1)
                printf("\nCollision resolved, new pos = %d", pos);

			custs[pos].custid = cust.custid;
			strcpy(custs[pos].custname,cust.custname);
            custs[pos].custphno = cust.custphno;
			custs[pos].empty = -1;
			printf("\nRecord Inserted into Hash Table\n");
			return;
		}
		if(custs[pos].empty==-1)
		{
			printf("\nCollision Detected\n");
			flag=1;
		}
        pos = (pos + 1) % SIZE;
	}
	printf("\nHash Table is full\n");
}

void Display(CUST custs[])
{
	int count;
	printf("\nHash Table");
	for(count = 0; count < SIZE; count++)
	{
		printf("\n[%d]:\t", count);
		if(custs[count].empty == -1)
			printf("\nCustomer - ID: %d Name: %s Phone: %d",custs[count].custid, custs[count].custname, custs[count].custphno);
		else
			printf("No Hash Entry\n");
    }
}



int main()
{
	int count, key, option;
	CUST custs[SIZE], cust;
	for(count = 0; count < SIZE ; count++)
		custs[count].empty=1;

	while(1)
	{
		printf("\n\n1. Insert a Record\n");
		printf("2. Search a Record\n");
		printf("3. Display All Records\n");
		printf("4. Exit\n");
		printf("\n Enter Your Option:");
		scanf("%d", &option);
		switch(option)
		{
			case 1: printf("\nEnter Customer id, name, ph:");
				scanf("%d%s%d", &cust.custid,cust.custname,&cust.custphno);
				InsHT_LP(cust, custs);
				break;

			case 2: printf("\nEnter the Key to Search:");
				scanf("%d", &key);
				count = Search(key, custs);
				if(count == -1)
					printf("\nRecord Not Found\n");
				else
					printf("\nRecord Found at Index pos:%d\n", count);
				break;
			case 3:	Display(custs);
				break;

			case 4:	exit(1);
		}
	}
	return 0;
}
