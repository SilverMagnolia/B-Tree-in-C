#include <stdio.h>
#include "BTree.h"


int InputElementsFromFile(BTreeNode ** pRoot);

int main()
{
	BTreeNode * btRoot;
	btRoot = BTree_Init();

	int choice, num;
	while (1)
	{
		fputs("1.insert\n2.delete\n3.search\n4.print\n9.get keys from file\n0.terminate\ninput: ", stdout);
		scanf("%d", &choice);
		puts("\n");

		if (choice == 0)
			break;

		switch (choice)
		{
		case 1:

			while (1)
			{
				fputs("input data to be inserted(exit -1): ", stdout);
				scanf("%d", &num);

				if (num == -1)
					break;

				if (BTree_Insert(&btRoot, num) == FALSE)
					puts("failed. the data already exists.");
			}
			break;

		case 2:

			while (1)
			{
				fputs("input data to be deleted(exit -1): ", stdout);
				scanf("%d", &num);

				if (num == -1)
					break;

				if (BTree_Delete(&btRoot, num) == FALSE)
					puts("failed. the data does not exist.");
			}
			break;

		case 3:

			while (1)
			{
				fputs("input data to be searched(exit -1): ", stdout);
				scanf("%d", &num);

				if (num == -1)
					break;

				fputs("\n<<the path>>\n\n", stdout);
				if (BTree_Search(&btRoot, num) == FALSE)
					puts("failed. the data does not exist.");
				puts("");
			}
			break;

		case 4:

			ShowAll(btRoot, 0);
			break;

		case 9:
			printf("<< print %d datas that were just inserted to tree. >>\n\n", InputElementsFromFile(&btRoot));
			ShowAll(btRoot, 0);
			break;

		} // end switch
	} // end while

	return 0;
}

int InputElementsFromFile(BTreeNode ** pRoot)
{

    
	FILE * fd = fopen("C:\\rand100.txt", "r");
	int data, count = 0;

	if (fd == NULL)
	{
		puts("open failed");
		return -1;
	}

	while (fscanf(fd, "%d", &data) != EOF) {
		BTree_Insert(pRoot, data);
		count++;
	}

	fclose(fd);

	return count;
}
