#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binomial heap
struct Node {
    int key;
    int degree;
    struct Node* parent;
    struct Node* child;
    struct Node* sibling;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->degree = 0;
    newNode->parent = NULL;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Function to merge two binomial heaps
struct Node* mergeHeaps(struct Node* h1, struct Node* h2) {
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    struct Node* res = NULL;
    if (h1->degree <= h2->degree) {
        res = h1;
        res->sibling = mergeHeaps(h1->sibling, h2);
    } else {
        res = h2;
        res->sibling = mergeHeaps(h1, h2->sibling);
    }
    return res;
}

// Function to link two binomial trees
void link(struct Node* parent, struct Node* child) {
    child->parent = parent;
    child->sibling = parent->child;
    parent->child = child;
    parent->degree++;
}

// Function to merge two binomial heaps after merging trees of the same degree
struct Node* merge(struct Node* h1, struct Node* h2) {
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* prev = NULL;
    struct Node* curr1 = h1;
    struct Node* curr2 = h2;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->degree <= curr2->degree) {
            if (tail == NULL) {
                head = curr1;
            } else {
                tail->sibling = curr1;
            }
            tail = curr1;
            curr1 = curr1->sibling;
        } else {
            if (tail == NULL) {
                head = curr2;
            } else {
                tail->sibling = curr2;
            }
            tail = curr2;
            curr2 = curr2->sibling;
        }

        if (prev != NULL) {
            prev->sibling = tail;
        }
        prev = tail;
    }

    if (curr1 != NULL) {
        tail->sibling = curr1;
    } else {
        tail->sibling = curr2;
    }

    return head;
}

// Function to insert a node into a binomial heap
struct Node* insert(struct Node* head, int key) {
    struct Node* newNode = createNode(key);
    return merge(head, newNode);
}

// Function to reverse the sibling pointers of a binomial tree
struct Node* reverse(struct Node* node) {
    if (node == NULL || node->sibling == NULL)
        return node;

    struct Node* prev = NULL;
    struct Node* curr = node;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->sibling;
        curr->sibling = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Function to extract the node with the minimum key from a binomial heap
struct Node* extractMinNode(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* minNode = head;
    struct Node* prevMinNode = NULL;
    struct Node* curr = head;
    struct Node* next = curr->sibling;
    while (next != NULL) {
        if (next->key < minNode->key) {
            minNode = next;
            prevMinNode = curr;
        }
        curr = next;
        next = curr->sibling;
    }

    if (prevMinNode == NULL)
        head = minNode->sibling;
    else
        prevMinNode->sibling = minNode->sibling;

    struct Node* newHead = reverse(minNode->child);
    head = merge(head, newHead);

    // Clear parent and sibling pointers for the extracted node
    minNode->parent = NULL;
    minNode->sibling = NULL;

    free(minNode);
    return head;
}

// Function to print the keys of the nodes in a binomial heap
void printHeap(struct Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->key);
    printHeap(node->child);
    printHeap(node->sibling);
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the binomial heap
    head = insert(head, 5);
    head = insert(head, 10);
    head = insert(head, 7);
    head = insert(head, 3);
    head = insert(head, 1);

    printf("Heap: ");
    printHeap(head);

    // Extract the node with the minimum key
    struct Node* minNode = extractMinNode(head);
    printf("\nMinimum key extracted: %d\n", minNode->key);

    printf("Heap after extraction: ");
    printHeap(head);

    return 0;
}
