#include<iostream>
using namespace std;


class Node{
    public:
    int value;
    Node *next;
};
 
class List: private Node{
    private:
        //we shall keep the access to head and sensitive members: private, and share them through Abstraction.
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
            //The pointer here would be the address of the first node.
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

        

    public:
    //The constructor for the list.
        List(){
            this->_head = new Node;
            //Initialize the linked list header with basic values.
            this->_head->value = 0;
            this->_head->next= NULL;

            this->_totalNodes = 0;
        }

        int getTotalNumberOfNodes(){
            return this->_totalNodes;
        }
        

        Node* createNewNode(int x){
            Node* newNode = new Node;
            newNode->next = NULL;
            newNode->value = x;
            this->increaseNodeCount();
            return newNode;
        }

        bool addNodeAtFront(int valueToBeAdded){
            /*
            The idea is to,
            1. Create a new pointer to a new node from our previous method.
            2. Store the address of the newly created node.
            3. Add it at the front by redirecting the header node.
            */

           try{
             Node* temporaryPointer = this->createNewNode(valueToBeAdded);

             if(this->isHeadEmpty()){
                this->setHeadTo(temporaryPointer);
             }
             else{
                temporaryPointer->next = this->getHeader();
                this->setHeadTo(temporaryPointer);
             }
             return true;

           }
           catch(bool status){
                return false;
           }
        }

        bool addNodeAtAPosition(int valueToBeAdded, int position){
            /*The idea is to,
            1. Validate the user input i.e. the POSITION provided.
            2. If the position is invalid, throw an exception.
            3. Else, try and insert the value at the specified position.
            4. If the user enters 0, we will add the node at front.
            5. If the user enters exact count of nodes available, we shall enter the node at the very end.
            */
           try{
            if(position<0 || position>this->getTotalNumberOfNodes()){
                throw (string)"[Exception]: Invalid input given, please try again by providing valid input!\n";
            }
            else if(position == 0){
                return this->addNodeAtFront(valueToBeAdded);
            }
            else if(position == this->getTotalNumberOfNodes()){
                return this->addNodeAtEnd(valueToBeAdded);
            }
            else{
                Node* prev;
                Node* curr = this->getHeader();
                Node* temporaryPointer = this->createNewNode(valueToBeAdded);
                int countt=0;
                while(position!=countt){
                    prev = curr;
                    curr = curr->next;
                    countt++;
                }
                temporaryPointer->next = prev->next;
                prev->next = temporaryPointer;
            }
            return true;
           }
           catch(string e){
             cout<<e;
             return false;
           }
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
            3-> If yes , then iterate and print all the values as we go along the list->
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
            
            case 2: cout<<"\nPlease enter the value you want to store: "<<endl;
                    cin>> valueToBeAdded;
                    if(singlyLinkedList->addNodeAtFront(valueToBeAdded)){
                        cout<<"The element '"<<valueToBeAdded<<"' has been added to the end of the List successfully."<<endl;
                    }
                    else{
                        cout<<"Sorry, the element could not be added to the end of the list, something went wrong.";
                    }
                    break;
            
            case 3: int position;
                    cout<<"\nPlease enter the value you want to store: "<<endl;
                    cin>> valueToBeAdded;
                    cout<<"Please enter the position at which the value should be added: "<<endl;
                    cout<<"[NOTE] Please enter a value between 0 to "<<singlyLinkedList->getTotalNumberOfNodes()<<endl;
                    cin>>position;
                    if(singlyLinkedList->addNodeAtAPosition(valueToBeAdded, position)){
                        cout<<"The element '"<<valueToBeAdded<<"' has been added to the List successfully at position: "<<position<<endl;
                    }
                    else{
                        cout<<"Sorry, the element could not be added to the list."<<endl;
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
