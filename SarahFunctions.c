#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct list_tag {
	int id;
	char password[51];
	struct list_tag * next;
} ListNode;

typedef struct {
	ListNode * first;
	ListNode * last;
} queue;

void queueInsert(queue * qp);
void queuePrint(queue q);
void queueInit(queue * qp);
int logIn(queue q, int ID, char pass[51]);

void main() {

	queue student_list;
	queue faculty_list;
	ListNode * n;
	int tempID;
	int total = 1;
	char tempPass[51];
	int decider; //log in decider
	int temp; // what you would like to do when you successfully log in
	queueInit(&student_list); //Initialize the queue as empty
	queueInit(&faculty_list);
	int adminID = 1;
	char adminPass[51] = "admin";
	while (total == 1)
	{
		printf("Please select the appropriate log in\n1.Student\n2.Faculty\n3.Admin\n4.Close Program\n");
		scanf("%d", &decider);
		printf("Please enter your ID:  ");
		scanf("%d", &tempID);
		printf("Please enter your password:  ");
		scanf("%s", tempPass);
		if (decider == 1)
		{
			if (logIn(student_list, tempID, tempPass) == 1)
			{
				printf("Good/n/n");

			}
			else
			{
				printf("You done fucked up");
			}

		}
		else if (decider == 2)
		{

		}
		else if (decider == 3)
		{
			if (adminID == tempID && strcmp(adminPass, tempPass) == 0)
			{

				int p;
				int r = 1;
				while (r == 1)
				{
					printf("Please choose what you would like to do: \n1.Add new students\n2. Add new teachers\n3. Log out\n");
					scanf("%d", &temp);
					if (temp == 1)
					{
						p = 1;
						while (p == 1)
						{
							queueInsert(&student_list);
							printf("Would you like to add another student?\n1.Yes\n2.No\n");
							scanf("%d", &p);
						}
					}
					else if (temp == 2)
					{
						p = 1;
						while (p == 1)
						{
							queueInsert(&faculty_list);
							printf("Would you like to add another faculty memeber?\n1.Yes\n2.No\n");
							scanf("%d", &p);
						}
					}
					else if (temp == 3)
						r = 0;
				}
			}
			else
			{
				printf("Scrub\n");
			}
		}
		else if (decider == 4)
			total = 0;
	}
	
	
	
}

void queueInit(queue * qp) {
	qp->first = NULL;
	qp->last = NULL;
}
int logIn(queue q, int ID, char pass[51]) {

	ListNode * n;
	for (n = q.first; n != NULL; n = n->next) {
		if (ID == n->id && strcmp(pass, n->password) == 0)
		{
			printf("Access Granted\n\n");
			return 1;
		}
	}
	return 0;
}

void queueInsert(queue * qp) {

	ListNode * n = (ListNode *)malloc(sizeof(ListNode));
	if (n == NULL) {
		printf("Out of memory\n");
		exit(1);
	}
	int t;
	char pass[51];
	printf("Please enter the new ID number:  ");
	scanf("%d", &t);
	printf("Please enter the new password:  ");
	scanf("%s", pass);
	n->id = t;
	strncpy(n->password, pass, 51);
	n->next = NULL;
	if (qp->last == NULL)
		qp->first = qp->last = n;
	else {
		qp->last->next = n;
		qp->last = n;
	}
}


void queuePrint(queue q) {

	printf("Now I will print the queue\n");
	ListNode * n;
	for (n = q.first; n != NULL; n = n->next) {
		printf("%d\n", n->id);
		printf("%s\n", n->password);
	}
