#ifndef _QUEUE_HPP
#define _QUEUE_HPP
using namespace std;

struct Queue{
	vector<float> v;
	int tail;
	int head;
};
void init_queue(Queue & pq);
void enqueue(Queue & pq, float data);
float dequeue(Queue & pq);
float show(const Queue & pq);

#endif /* _QUEUE_HPP */