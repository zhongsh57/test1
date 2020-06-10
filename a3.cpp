#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;
#include <stddef.h>

typedef struct Node{
    Node* next;
    int ele;
}Node;
class Queue {
  public:
  	Queue() {
    	this->size = 0;
      this->tail = this->head = NULL;
    }
    void push(const int & ele);
    void pop();
    int front();
    int back();
    void clear();
  	int Size() {
      return this->size;
    }
  	~Queue() {
    	clear();
    }
  private:
    int size;
    Node* head;
    Node* tail;
};
void Queue::push(const int& ele){
    Node*a=new Node;
    a->ele=ele;
    a->next=NULL;
    if (head==NULL&&tail==NULL){
        head=tail=a;
        
    }else {
        tail->next=a;
        tail=a;
    }
    size++;
}
void Queue::pop()
{
	if (head==tail&&head!=NULL){
        delete head;
        head=tail=NULL;
		size--;
    }
    if (head!=NULL){
        Node *temp=head;
        head=head->next;
        delete temp;
        size--;
        return  ;
    }else {
        return ;
    }
}
int Queue::front(){
    if (head==NULL)return -1;
    return head->ele;
}

int Queue::back (){
    if (head==NULL)return -1;
    return tail->ele;
}
void  Queue::clear(){
     if (head==NULL&&tail==NULL)return ;
     while(head!=tail){
         Node*temp=head;
         head=head->next;
         delete temp;
     }
     delete head;
	 head=NULL;
     size=0;
	 
}
 int main() {
    Queue q1;

    int size;
    cin >> size;
    int ele;
    for (int i = 0; i < size; i++) {
        cin >> ele;
        q1.push(ele);
        cout << q1.back() << " ";
    }
    cout << endl;
    cout << "The size of Queue is : " << q1.Size() << endl;
    for (int i = 0; i < size; i++) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
    cout << "The size of Queue is : " << q1.Size() << endl;
    cout << q1.front() << endl;
    for (int i = 0; i < size; i++) {
        cin >> ele;
        q1.push(ele);
        cout << q1.back() << " ";
    }
    cout << endl;
    q1.clear();
    cout << q1.back() << endl;
    cout << "The size of Queue is : " << q1.Size() << endl;
    return 0;
}
