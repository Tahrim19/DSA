#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove() {
        if (!head) {
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    std::vector<int> getTrump() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        std::vector<int> result;
        if (fast) {
            result.push_back(slow->data);
        } else {
            result.push_back(slow->data);
            result.push_back(slow->next->data);
        }

        return result;
    }
};

int main() {
    LinkedList linkedList;

    while (true) {
        std::cout << "Enter command (ADD, DELETE, END): ";
        std::string command;
        std::cin >> command;

        if (command == "ADD") {
            int number;
            std::cout << "Enter number to add: ";
            std::cin >> number;
            linkedList.add(number);
        } else if (command == "DELETE") {
            linkedList.remove();
        } else if (command == "END") {
            std::vector<int> result = linkedList.getTrump();
            for (int num : result) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            break;
        }
    }

    return 0;
}

