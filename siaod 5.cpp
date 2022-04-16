#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(int _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void insert(int pos, int new_elem) {
        Node* p = new Node(new_elem);
        Node* prev = first;
        for (int i = 0; i < pos-1; i++) {
            prev = prev->next;
        }
        Node* newp = prev->next;
        prev->next = p;
        p->next = newp;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(int _val) {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(int _val) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast != last) {
            if (fast->val == _val) {
                slow->next = fast->next;
                delete fast;
                if (slow->next == last) return;
            }
            slow = slow->next;
            fast = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
    }

    void reverse() {
        if (first->next == NULL) return;

        Node* curr, * next, * prev = NULL;
        curr = first;


        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        first = prev;
    }

    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};

int main()
{
    list l;
    cout << l.is_empty() << endl;
    l.push_back(3);
    l.push_back(123);
    l.push_back(8);
    l.push_back(123);
    l.push_back(1);
    l.print();
    cout << "---------------\n";
    l.insert(3, 5644);
    l.print();
    l.reverse();
    l.print();
    return 0;
}
