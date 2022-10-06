#include<iostream>
using namespace std;


class Node{
    public:
    int value;
    Node *next;
};
 
class List: private Node{
    private:
        //we shall keep the access to head private. And share them through Abstraction.
        Node *_head;

        bool isHeadEmpty(){
            if(this._head == NULL){
                return true;
            }
            else{
                return false;
            }
        }

    public:
    //The constructor.
        List(){
            //Initialize the linked list header with basic values.
            this._head->value = 0;
            this._head->next = NULL;
        }

        void setHeadTo(Node *pointer){
            //we the pointer here would be the address of the first node.
            this._head = pointer;
        }

        Node* getHeader(){
            return this._head;
        }

        Node* createNewNode(int x){
            Node* newNode = new Node;
            newNode->next = NULL;
            newNode->value = x;
            return newNode;
        }

        bool addNodeAtEnd(int valueToBeAdded){
            /*
            The idea is to,
            1. Create a new pointer to a new node from our previous method.
            2. Store the address of the newly created node.
            3. Add it at the end by iterating.
            */
        try{
            Node* temporaryPointer = this.createNewNode(valueToBeAdded);

            if(this.isHeadEmpty()){
                this.setHeadTo(temporaryPointer);
                return true;
            }
            else{
                //Since we already have some data we have to iterate.
                    Node* temp = this.getHeader();

                    while(temp->next != NULL){
                        temp = temp->next;
                    }
                    //after the above loop we are currently at the last node.
                    temp->next = temporaryPointer;
                    delete temp;
                    return true;

            }
            delete temporaryPointer;
        }
        catch(){
            return false;
        }
        }

        void printLinkedList(void){
            /* Objective of this method is to print all elements in the linked list.
            1. Check if we have any valid nodes that contain any info at all.
            2. If no, then print a statement saying that we don't have any nodes.
            3. If yes, then iterate and print all the values as we go along the list.
            */

            if(this.isHeadEmpty()){
                cout<<"Sorry, the Linked List is currently empty.";
            }
            else{
                Node* temp = this.getHeader();
                
                cout<<"The elements in the Linked List are: "<<endl;
                while(temp-> next != NULL){
                    cout<<temp->value<<" ";
                    temp = temp->next;
                }
                cout<<temp->value<<endl;

                delete temp;
            }
            
        }
};


int main(void){
    //lets create the listy
    List singlyLinkedList = new List;

    int x =5;
    singlyLinkedList.printLinkedList();


}
