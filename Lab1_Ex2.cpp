/*  Author: Jovani Benavides
 *  Course: CSCI-115
 *  
 */
#include <iostream>
using namespace std;

//node structure
struct Node {
    int data;
    Node* next;
};

class LinkedList {
  private:
    Node* head;
  public:
    LinkedList(){
      head = NULL;
    }
 
    //Add new element at the end of the list
    void insert(int newElement) {
      Node* newNode = new Node();
      newNode->data = newElement;
      newNode->next = NULL; 
      if(head == NULL) {
        head = newNode;
      } else {
        Node* temp = head;
        while(temp->next != NULL)
          temp = temp->next;
        temp->next = newNode;
      }    
    }

    //Delete first node of the list
    void frontDelete() {
      if(head != NULL) {
        Node* temp = head;
        head = head->next; 
        free(temp); 
      }
    }

   //Delete last node of the list
    void endDelete() {
      if(head != NULL) {
        if(head->next == NULL) {
          head = NULL;
        } else {
          Node* temp = head;
          while(temp->next->next != NULL)
            temp = temp->next;
          Node* lastNode = temp->next;
          temp->next = NULL;
          free(lastNode); 
        }
      }
    }
    //display the content of the list
    void PrintList() {
      Node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(temp != NULL) {
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    }    
};

int main(){
    LinkedList List;
    //Initial Linked List 
    List.insert(20);
    List.insert(40);
    List.insert(60);
    List.PrintList();
    // Linked list after front deletion 
    List.frontDelete();
    List.PrintList();
    // Linked list after end Deletion
    List.endDelete();
    List.PrintList();
}