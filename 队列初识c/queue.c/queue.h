#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class MyQueue
{
public:
	MyQueue(int queueCapacity);
	virtual ~MyQueue();
	void ClearQueue();
	bool QueueEmpty() const;
	bool QueueFull() const;
	int QueueLength() const;
	bool EnQueue(int element);
	bool DeQueue(int &element);
	void QueueTraverse();
private:
	int *m_pQueue;
	int m_iQueueLen;
	int m_iQueueCapacity;
	int m_iHead;
	int m_iTail;
};

#endif // QUEUE_H_INCLUDED
