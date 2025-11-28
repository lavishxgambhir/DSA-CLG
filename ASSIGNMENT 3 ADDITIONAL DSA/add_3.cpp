Node* removeLoop(Node* head) {
    if (!head) return head;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (slow != fast) return head;

    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    while (fast->next != slow) {
        fast = fast->next;
    }

    fast->next = NULL;
    return head;
}

