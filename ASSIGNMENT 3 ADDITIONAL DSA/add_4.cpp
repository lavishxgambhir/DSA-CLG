Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    tail->next = head;

    Node* curr = head;
    for (int i = 1; i < k; i++) curr = curr->next;

    Node* newHead = curr->next;
    curr->next = NULL;

    return newHead;
}

