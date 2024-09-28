class MyCircularDeque {
public:
    int size;
    vector<int> dq;
    int front, rear;
    int count;

    MyCircularDeque(int k) {
        size = k;
        dq.assign(k, -1);
        front = 0;
        rear = 0;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + size) % size;
        dq[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        dq[rear] = value;
        rear = (rear + 1) % size;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        dq[front] = -1;
        front = (front + 1) % size;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + size) % size;
        dq[rear] = -1;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return dq[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return dq[(rear - 1 + size) % size];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};
