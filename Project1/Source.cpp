#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;


};
int index = 1;
void pushAtFront(Node** head_ref, char newData) {
    Node* new_node = new Node();
    new_node->data = newData;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}

bool isBalanced(string str) {
    Node* head = NULL;



    char x=NULL;

    if (str.size() == 1) {

        index =  1;
        return false;
    }

    unsigned int i = 0;
    while (i < str.size()) {

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {

            pushAtFront(&head, str[i]);

        }

 




        switch (str[i]) {
        case ')': 
            if (i != 0) {
                x = head->data;
                head = head->next;
            }
            if (x == '{' || x == '[' )
            {
                index = i + 1;
                return false;
            }
            break;

        case '}':
            if (i != 0) {
                x = head->data;
                head = head->next;
            }
            if (x == '(' || x == '[' ) {
                index = i + 1;
                return false;
            }
           
            break;

        case ']':
            if (i != 0) {
                x = head->data;
                head = head->next;
            }
            if (x == '(' || x == '{' ) {
                index = i + 1;
                return false;
            }
            break;


    

        }


        i++;

    }

    if (head == NULL)
        return true;
    else return false;
}

int main() {
    string x;


    cin >> x;


    if (isBalanced(x)) {

        cout << "Success" << endl;
    }
    else {


        cout << index << endl;
    }

    return 0;
}