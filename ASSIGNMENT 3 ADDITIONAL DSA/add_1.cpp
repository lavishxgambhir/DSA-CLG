Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = 0, lenB = 0;
    Node* a = headA;
    Node* b = headB;

    while (a) { lenA++; a = a->next; }
    while (b) { lenB++; b = b->next; }

    a = headA;
    b = headB;

    int diff = abs(lenA - lenB);

    if (lenA > lenB)
        while (diff--) a = a->next;
    else
        while (diff--) b = b->next;

    while (a && b) {
        if (a == b) return a;
        a = a->next;
        b = b->next;
    }
    return NULL;
}

