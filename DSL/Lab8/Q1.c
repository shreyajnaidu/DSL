#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // Maximum size of the queue

// Structure to represent a print task
typedef struct {
    int id;
    char name[50];
} PrintJob;

// Queue structure
typedef struct {
    PrintJob jobs[MAX];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Enqueue a new print job
void enqueue(Queue *q, PrintJob job) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot add more print jobs.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->jobs[q->rear] = job;
    printf("Enqueued: Document ID=%d, Name=%s\n", job.id, job.name);
}

// Dequeue a print job
PrintJob dequeue(Queue *q) {
    PrintJob job;
    if (isEmpty(q)) {
        printf("Queue Underflow! No jobs to print.\n");
        job.id = -1;
        strcpy(job.name, "None");
        return job;
    }

    job = q->jobs[q->front];

    if (q->front == q->rear) { // Only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    printf("Printing: Document ID=%d, Name=%s\n", job.id, job.name);
    return job;
}

// Function to create a print job
PrintJob createJob(int id) {
    PrintJob job;
    job.id = id;
    sprintf(job.name, "Document_%d", id);
    return job;
}

int main() {
    Queue printerQueue;
    initQueue(&printerQueue);

    int totalJobs;

    printf("Enter number of print jobs to simulate (max %d): ", MAX);
    scanf("%d", &totalJobs);
    if (totalJobs > MAX) totalJobs = MAX;

    // Enqueue jobs (user-input simulation)
    for (int i = 1; i <= totalJobs; i++) {
        PrintJob job = createJob(i);
        enqueue(&printerQueue, job);
    }

    printf("\nProcessing print jobs in FIFO order:\n");
    // Dequeue and process all jobs
    while (!isEmpty(&printerQueue)) {
        dequeue(&printerQueue);
    }

    return 0;
}
