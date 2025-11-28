Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    int count = 0;
    Node* temp = head;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    if (count < k) return head;

    count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    head->next = reverseKGroup(curr, k);
    return prev;
}

