#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class List {
   public:
    List(std::vector<int>& data);
    ~List();
    void traversePrint();
    void reverse();

   private:
    Node* head;
};

List::List(std::vector<int>& data) {
    if (data.empty()) {
        std::cerr << "empty input" << std::endl;
        return;
    }

    head = new Node(data[0]);
    Node* cur_node = head;
    for (size_t i = 1; i < data.size(); i++) {
        cur_node->next = new Node(data[i]);
        cur_node = cur_node->next;
    }
}
List::~List() {
    Node* vir_head = new Node;
    vir_head->next = head;

    Node* next_node = vir_head->next;
    while (next_node) {
        Node* cur_node = next_node;
        next_node = next_node->next;
        delete cur_node;
    }
    std::cout << "all free list nodes" << std::endl;
}

void List::traversePrint() {
    for (Node* cur_node = head; cur_node != nullptr; cur_node = cur_node->next) {
        std::cout << cur_node->val << ", ";
    }
    std::cout << std::endl;
    std::cout << "finish" << std::endl;
}

void List::reverse() {
    Node* vir_node = new Node();
    vir_node->next = head;
    Node* prev_node = vir_node;
    Node* cur_node = head;
    while (cur_node) {
        // save
        Node* next_node = cur_node->next;
        
        // redirect
        cur_node->next = prev_node;

        // update
        prev_node = cur_node;
        cur_node = next_node;
    }
    
    // assign tailed node
    head->next = nullptr;
    head = prev_node;
}

int main(int argc, char const* argv[]) {
    std::cout << "test it" << std::endl;
    std::vector<int> l1_input = {1, 2, 3, 4};
    List l1(l1_input);
    l1.traversePrint();
    
    l1.reverse();
    l1.traversePrint();

    return 0;
}
