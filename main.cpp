/*
EXAMPLE OF THE CIRCULAR QUEUE

This program is the basic example of a circular queue. It is an example of how the circular queue is emplemented. A basic queue is an example
of a data structure that accept components and execute that one by one. The First element that was added to the queue is the first element
that is executed from that queue. But each queue must have a maximum size, which on this one is 30. What happens when the queue reaches
maximum or it reaches the last index? Even though there are elements that have been removed from the Front indices but when the Rear
(the position of the last added element) reaches the last index, the basic queue is referred as full. This is where a circular queue
intervenes. This queue is full if and only if all the indices are occupied. When the Rear reaches the last index it checks if the 1st index is
occupied or not, if it occupied, then the queue is full, but if it empty, then the rear moves to that index and it will keep moving along the queue
again until it reaches the position behind the Front(index position of the element that was first added to the queue), that is when the queue
will be full again.

User inputs:
1. options: There are number of options that the user can choose from of what action they want to perform with this circular queue. They can
               add elements to the queue, execute elements from the queue, display the queue elements, check if it empty, check if it full,
               clear the screen or check the size of the queue, which is the number of elements that are in the queue.
2. elements: The queue receives the elements(in a form of integers) from the user.
*/
#include <iostream>

using namespace std;
class circularQueue{     //New class was created for the circular queue
private:    //Parameters of the queue class
    int Front;
    int Rear;
    int arrQ[30];
    int QCount;
    public:
        circularQueue(){
            Front=0;
            Rear=-1;
            QCount=0;
            for (int i=0; i<30; i++){
                arrQ[i]=0;     //initialising all the queue indexes
            }
        }
        //Queue functions:

        bool isEmpty(){
            if (Rear==-1){    //Circular queue is empty if and only if the Rear position is -1
                    Front=0;    //When it empty, Front must be 0, Rear decides if the queue is  empty or not
                return true;
            }else return false;
        }

        bool isFull(){
            if ((Rear==Front-1) && (Front!=0)){    //This is when the last added element is at the back of the first added element meaning there is no more space for another element and in this condition the Front should not be 0 because that will mean that Rear is -1 which suggests that the queue is empty
                return true;
            }else if ((Rear==29) && (Front==0)){    //This is when the last added element is at the last positon of the queue and Front occupied the 1st position which means there is no space at the front position of the queue
                return true;
            }else return false;
        }

        int QueueSize(){
            return QCount;    //QCount is the count that was kept when you add or execute elements on a queue
        }

        void addQueue(int value){
            if (isFull()){
                cout << "Queue is full" << endl;   //You cannot add element to a full queue
            }else if (Rear==29){
                arrQ[0]=value;    //We getting the value from the user and we add it on the from position, it will be added because the queue is not full which means this position is not occupied
                Rear=0;   //Rear moves to this position
                QCount++;   //QCount is the number of elements on a queue
                cout << "Value added successfully" << endl;
            }else{    //No special conditions are there at this moment
                arrQ[Rear+1]=value;    //Value is added to the index position next to Rear position
                Rear++;   //Rear position moves to the next element
                QCount++;
                cout << "Value added successfully" << endl;
            }
        }

        int deleteQ(){
            int x;
            if (isEmpty()){
                cout << "Queue is empty" << endl;
                //Conditions for empty queue will be ignored on the next lines because on the next lines are considered if and only if the queue is not empty
            }else if (Front==Rear){  //one element remaining
                x=arrQ[Front];
                arrQ[Front]=0;
                Rear=-1;   //emptying the queue
                Front=0;
                QCount=0;
                cout << x << " was executed from the queue, the queue is now empty" << endl;
            }else if (Front==29){   //Front is on the last position
                x=arrQ[Front];
                arrQ[Front]=0;    //The element in this position is executed
                Front=0;    //Front moves to the 1st index position
                QCount--;    //QCount decrements when the element was executed
                cout << x << " was executed from the queue, " << QCount << " elements remaining in the queue" << endl;
            }else{    //No special conditions are present to avoid normal execution of an element at this moment
                x=arrQ[Front];
                arrQ[Front]=0;
                Front++;
                QCount--;
                cout << x << " was executed from the queue, " << QCount << " elements remaining in the queue" << endl;
            }

        }

        void DisplayQueue(){
            int i;

            if (Rear>Front){   //Either Front is 0 or there are no elements from index position 0 to index position Front-1, Rear is on the last index or there are no elements from index position Rear+1 to the last index
                for (i=Front; i<Rear+1; i++){
                    cout << arrQ[i] << "  ";
                }
                 cout << endl;
            }
             if (Front>Rear){   //There are elements present only from the Front position to the last index position of an array, and from the first index position to the position Rear
                for (i=Front; i<30; i++){
                    cout << arrQ[i] << "  ";
                }
                for (i=0; i<Rear+1; i++){
                    cout << arrQ[i] << "  ";
                }
                cout << endl;
             }
             if (Front==Rear){
                cout << arrQ[Front] << endl;
             }
        }

        int QueuSize(){    //Only one element is present on an array
            return QCount;
        }
};
int main()
{
    circularQueue myQueue;
    int inputValue, option=1;    //Option is 1 only to allow the display of information

    do {
            if ((option==1) || (option==8)){
                 cout << "***Welcome to your queue***" << endl;
                 cout << "Integers only allowed\nMaximum size=30\nUse wisely" << endl;
                 cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
                 cout << "You have options of actions you can perform with your Queue" << endl;
                 cout << "1=Clear screen    2=Display queue    3=Add elemant    4=Delete front element\n5=Is Empty?    6=Is Full?    7=Queue size    8=Clear screen" << endl;
                 cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
                 cout << endl;
            }
        cout << "Press the number corresponding to action you want(Press '0' to end the program): ";
        cin >> option;   //This is where the user choose what action they want to perform with the queue
        switch (option){
            case 1: system("cls");break;
            case 2:
                {
                    if (myQueue.isEmpty()){   //This returns True/False
                        cout << "The queue is empty" << endl;
                    }else{
                    cout << "Your Queue currently displays : ";
                    myQueue.DisplayQueue();    //Queue will display if and only if it is not empty
                    }
                }break;
            case 3:    //Add the element at the Rear+1 position and increment Rear
                {
                    cout << "Enter the value you want to add: ";
                    cin >> inputValue;
                    myQueue.addQueue(inputValue);   //This function takes care of every conditions if they are present and perform neccessary actions
                }break;
            case 4:    //Execute the element in the Front position
                {
                    myQueue.deleteQ();    //This function takes care of every conditions if they are present and perform neccessary actions
                }break;
            case 5:    //Is the queue empty or not
                {
                    if (myQueue.isEmpty()){
                        cout << "The queue is empty" << endl;
                    }else cout << "The queue is not empty" << endl;
                }break;
            case 6:    //Is the queue Full or not
                {
                    if (myQueue.isFull()){
                        cout << "The queue is full" << endl;
                    }else cout << "The queue is not full" << endl;
                }break;
            case 7:
                {
                    cout << "Queue size is currently " << myQueue.QueueSize() << " elements" << endl;   //QueueSize funtion returns the number of elements present on the queue at that moment as specified by the QCount parameter
                }break;
            case 8:
                {
                    system("cls");    //Clears a screen BUT the default messages/info will be restored
                }
        }
    } while (option!=0);   //In a case where the user enter 0 as an option, the while loop termonates and the program terminates immediately



    return 0;
}
