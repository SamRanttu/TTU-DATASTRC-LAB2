#include <stdio.h>

typedef struct {
    int ar[100];
    int front;
    int rear;
    int cnt;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    obj->front = 0;
    obj->rear = 0;
    obj->cnt = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj == NULL) return;
    obj->cnt++;
    obj->ar[obj->rear] = x;
    obj->rear = (obj->rear +1)%100;
}

int myQueuePop(MyQueue* obj) {
    if (obj == NULL) return 0;
    obj->cnt--;
    obj->front = (obj->front +1)%100;
    return (obj->ar[(obj->front-1)%100]);
}

int myQueuePeek(MyQueue* obj) {
    if (obj == NULL) return 0;

    return obj->ar[obj->front];
}

bool myQueueEmpty(MyQueue* obj) {
    if (obj == NULL) return false;

    return (obj->cnt?false:true);
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return;
    free(obj);
}

int main() {
  MyQueue* obj = myQueueCreate();
  
  for (int i = 0; i < 5; i++){
    myQueuePush(obj, i);
  }

  for (int i = 0; i < 5; i++) {
    printf("%d\n", myQueuePop(obj));
  }
  myQueueFree(obj);
}
