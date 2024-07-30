#include <memory>
#include <iostream>
using namespace std;

class MyLinkedList {
private:
struct Node {
    Node(int _val) : val(_val), next(nullptr), prev(nullptr) {}
    Node(int _val, unique_ptr<Node>& _next, Node* _prev) : 
        val(_val), next(std::move(_next)), prev(_prev) {}
    Node(Node& other) {
        this->val = other.val;
        this->next = std::move(other.next);
        this->prev = other.prev;
    }
    Node& operator=(Node& other) {
        this->val = other.val;
        this->next = std::move(other.next);
        this->prev = other.prev;
        return *this;
    }

    int val;
    unique_ptr<Node> next;
    Node* prev;
};
public:
    MyLinkedList() {
        size_ = 0;        
    }
    
    int get(int index) {
        Node* cur = findByIndex(index);
        if (!cur)
            return -1;
        return cur->val;
    }
    
    void addAtHead(int val) {
        if (size_ == 0) {
            head_ = make_unique<Node>(val);
            tail_ = head_.get();
        } else {
            head_ = make_unique<Node>(val, head_, nullptr);
            Node* nxt = head_->next.get();
            nxt->prev = head_.get();
        }

        size_++;
    }
    
    void addAtTail(int val) {
        if (size_ == 0) {
            head_ = make_unique<Node>(val);
            tail_ = head_.get();
        } else {
            /*tail0 -> tail1 -> []*/
            tail_->next = make_unique<Node>(val);
            Node* new_tail = tail_->next.get();
            new_tail->prev = tail_;
            tail_ = new_tail;
        }

        size_++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size_ || index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size_) {
            addAtTail(val);
            return;
        }

        /*prev -> "new Cur" -> old_cur*/
        Node* prev = findByIndex(index - 1);
        unique_ptr<Node> new_cur = make_unique<Node>(val, prev->next, prev);
        prev->next = std::move(new_cur);
        
        if (new_cur) {
            Node* nxt = new_cur->next.get();
            nxt->prev = new_cur.get();
        }

        size_++;
    }
    
    void deleteAtIndex(int index) {
        if (size_ == 0 || index >= size_ || index < 0)
            return;
        if (index == 0) {
            head_ = std::move(head_->next);
        } else {
            Node* prev = findByIndex(index - 1);
            Node* rm_node = prev->next.get();
            prev->next = std::move(rm_node->next);
            Node* nxt = prev->next.get();
            if (nxt) nxt->prev = prev;

            /*tail*/
            if (index == size_ - 1) {
                tail_ = prev;
            }
        }

        size_--;
    }
private:
    Node* findByIndex(int index) {
        if (index >= size_ || index < 0)
            return nullptr;
        
        Node* cur = head_.get();
        while (index-- > 0) {
            cur = cur->next.get();
        }
        return cur;
    }

    size_t size_;
    unique_ptr<Node> head_;
    Node* tail_;
};

int main(int argc, char const* argv[]) {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(0); /*0*/
    obj->addAtIndex(1, 4); /*0->4*/
    obj->addAtTail(8); /*0->4->8*/
    obj->addAtHead(5); /*5->0->4->8*/
    obj->addAtIndex(4, 3); /*5->0->4->8->3*/
    obj->addAtTail(0); /*5->0->4->8->3->0*/
    obj->addAtTail(5); /*5->0->4->8->3->0->5*/
    obj->addAtIndex(6, 3); /*5->0->4->8->3->0->3->5*/
    obj->deleteAtIndex(7); /*5->0->4->8->3->0->3->[]*/
    obj->deleteAtIndex(5); /*5->0->4->8->3->3->[]*/
    obj->addAtTail(4); /*5->0->4->8->3->3->4->[]*/
    delete obj;
    return 0;
}