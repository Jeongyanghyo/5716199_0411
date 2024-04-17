#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element;
typedef struct Stacktype {
	//element stack[];
	element* sptr;
	element* data;
	int capacity;
	int top;
}Stacktype;

Stacktype s1;
Stacktype s2;


// create : 이미 만들었음, Stacktype의 변수를 선언하면 만들어짐
//delete: 할 수 없음
//init
void init(Stacktype *sptr, int nos) {
	sptr->data = (element*)malloc(sizeof(Stacktype) * nos);
	sptr->top = -1;
	sptr->capacity = nos;
}
// 
//is_full 함수
int is_full(Stacktype *sptr) {
	if (sptr->top == sptr->capacity - 1) {
		sptr->capacity = sptr->capacity * 2;
		sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));

	}

}

//push 함수
void push(Stacktype *sptr, element item) {
	if (is_full(sptr)) {
		fprintf(stderr, "");
		return;
	}

	else {
		sptr->top = sptr->top + 1;
		sptr->data[sptr->top] = item;
	}
}

int is_empty(Stacktype* sptr) {

	return(sptr->top == -1);
}

//pop 함수
element pop(Stacktype *sptr) {
	element r;
	if (is_empty(sptr)) {
		printf(stderr, "stack is empty\n");
		return -1;

	}
	else {
		/*r =sptr-> stack[sptr->top];
		sptr->top = sptr->top - 1;
		return r;*/
		return (sptr->data[(sptr->top)--]);//위 세줄을 한줄로 줄인 것
	}
}

element peek(Stacktype *sptr) {

	element r;
	if (is_empty(sptr)) {
		printf(stderr, "stack is empty\n");
		return -1;

	}
	else {
		/*r = stack[top];
		return r;*/
		return (sptr->data[sptr->top]);
	}
}

int main() {

	Stacktype s;
	int rand_num;
	int numOFStack;
	srand(time(NULL));

	printf("How Many element Stack has?");
	scanf_s("%d", &numOFStack);

	init(&s, numOFStack);

	for (int i = 0; i < 30; i++) {
		rand_num = (rand() % 100) + 1;
		printf("%d \n", rand_num);
		if (rand_num % 2 == 0) {
			push(&s, rand_num);
			printf("Current rand_sum: %d | Even\npush: %d  \n", rand_num, rand_num);
		}
		else {
			rand_num = pop(&s);
			printf("Current rand_sum: %d | Odd\npop: %d  \n", rand_num, rand_num);
		}
	}
	
}
