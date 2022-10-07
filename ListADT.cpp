#include<iostream>
using namespace std;


class Node{
    public:
    int value;
    Node *next;
};
 
class List: private Node{
    private:
        //we shall keep the access to head private-> And share them through Abstraction->
        Node *_head;
        int _totalNodes;

        bool isHeadEmpty(){
            if(this->_head->next == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        void setHeadTo(Node *pointer){
            //we the pointer here would be the address of the first node->
            this->_head->next = pointer;
        }

        Node* getHeader(){
            return this->_head->next;
        }

        void increaseNodeCount(){
            this->_totalNodes++;
        }

        void decreaseNodeCount(){
            this->_totalNodes--;
        }

        int getTotalNumberOfNodes(){
            return this->_totalNodes;
        }

    public:
    //The constructor->
        List(){
            this->_head = new Node;
            //Initialize the linked list header with basic values->
            this->_head->value = 0;
            this->_head->next= NULL;

            this->_totalNodes = 0;
        }

        

        Node* createNewNode(int x){
            Node* newNode = new Node;
            newNode->next = NULL;
            newNode->value = x;
            this->increaseNodeCount();
            return newNode;
        }

        bool addNodeAtEnd(int valueToBeAdded){
            /*
            The idea is to,
            1-> Create a new pointer to a new node from our previous method->
            2-> Store the address of the newly created node->
            3-> Add it at the end by iterating->
            */
        try{
            Node* temporaryPointer = this->createNewNode(valueToBeAdded);

            if(this->isHeadEmpty()){
                this->setHeadTo(temporaryPointer);
                return true;
            }
            else{
                //Since we already have some data we have to iterate->
                    Node* temp = this->getHeader();

                    while(temp->next != NULL){
                        temp = temp->next;
                    }
                    //after the above loop we are currently at the last node->
                    temp->next = temporaryPointer;
                    
                    return true;

            }
            delete temporaryPointer;
        }
        catch(bool status){
            return false;
        }
        }

        void printLinkedList(void){
            /* Objective of this method is to print all elements in the linked list->
            1-> Check if we have any valid nodes that contain any info at all->
            2-> If no, then print a statement saying that we don't have any nodes->
            3-> If yes, then iterate and print all the values as we go along the list->
            */

            if(this->isHeadEmpty()){
                cout<<"Sorry, the Linked List is currently empty.";
            }
            else{
                Node* temp = this->getHeader();
                
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
    List* singlyLinkedList = new List;
    int choice = 0;
    
    //here is the menu.
    while(true){
        //Provide the options to the user.
        cout<<"\n--------------------------------------\n";
        cout<<"Please choose from the following operations available:"<<endl;
        cout<<"1. Add a value to the List at the end."<<endl;
        cout<<"2. Add a value to the List at the front."<<endl;
        cout<<"3. Add a value to the List at a position."<<endl;
        cout<<"4. Delete a value from the List."<<endl;
        cout<<"5. Delete at a position in the List."<<endl;
        cout<<"6. Search for a element in the List."<<endl;
        cout<<"7. Show the elements stored in the List."<<endl;
        cout<<"8. Exit."<<endl;
        cout<<"\n--------------------------------------\n";
        cout<<"Please enter your choice of operation: ";
        cin >> choice;

        //validate and execute user choice.
        switch(choice){

            case 1: int valueToBeAdded;
                    cout<<"\nPlease enter the value you want to store: "<<endl;
                    cin>> valueToBeAdded;
                    if(singlyLinkedList->addNodeAtEnd(valueToBeAdded)){
                        cout<<"The element '"<<valueToBeAdded<<"' has been added to the end of the List successfully."<<endl;
                    }
                    else{
                        cout<<"Sorry, the element could not be added to the end of the list, something went wrong.";
                    }
                    break;

            case 7: singlyLinkedList->printLinkedList();
                    break;
            
            case 8: exit(0);

            default: cout<<"Sorry invalid operation! Please try again."<<endl;
                     break;
        }
    }


}
