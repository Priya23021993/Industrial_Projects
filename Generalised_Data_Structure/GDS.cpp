////////////////////////////////////////////////////////////////
///Generalised Data Structure Library
///////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------------------------------
Type                   Name of class for node                 Name of class for Functionality
-----------------------------------------------------------------------------------------------------------
Singly Linear              SinglyLLLnode                            SinglyLLL             Done
Singly Circular            SinglyCLLnode                            SinglyCLL
Doubly Linear              DoublyLLLnode                            DoublyLLL             Done
Doubly Circular            DoublyCLLnode                            DoublyCLL
Stack                      Stacknode                                Stack                 Done
Queue                      Queuenode                                Queue                 Done
------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Singly Linear List using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data= no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:                          
         SinglyLLLnode<T> *first;
         int iCount;

    public:     
         SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
        void Set(int,T);
        bool Search(T);
        int Frequency(T);
         
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
  cout<<"Object of SinglyLL gets Created.\n";
  this -> first = NULL;
  this -> iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : InsertFirst
//    Input         : Data of node
///   OutPut        : Nothing
//    Description   : Used to insert node at first position
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)                
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn -> next = (this ->first);
    (this ->first) = newn;
     this -> iCount++;    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : InsertLast
//    Input         : Data of node
///   OutPut        : Nothing
//    Description   : Used to insert node at last position
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
SinglyLLLnode<T> * newn = NULL;
SinglyLLLnode<T> * temp = NULL;

newn = new SinglyLLLnode<T>(no);

if(this ->iCount == 0)                       
{
    (this ->first) = newn;
}
else
{ 
    temp = this ->first;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
        
    }
    temp -> next = newn;
    
}
this ->iCount++;
} 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : DeleteFirst
//    Input         : Data of node
///   OutPut        : Nothing
//    Description   : Used to delete node at first position
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

   if(this ->first == NULL)
   {
    return;
   }
else if(this ->first -> next ==NULL)                      
{
    delete(this ->first);
    this ->first = NULL;
}
else
{
        temp = this ->first;
        this ->first = this ->first -> next;
        delete temp;
}

this ->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : DeleteLast
//    Input         : Data of node
///   OutPut        : Nothing
//    Description   : Used to delete node at Last position
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLLL<T> :: DeleteLast()
{
SinglyLLLnode<T> * temp = NULL;

if(this ->first == NULL)
{
    return;
}
else if(this ->first -> next ==NULL)                      
{
    delete(this ->first);
    this ->first = NULL;
}
else
{
        temp = this ->first;

        while(temp -> next -> next != NULL)
        {
        temp = temp -> next;
        }
        delete (temp-> next);
        temp -> next = NULL;
}

this ->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : Display
//    Input         : Data of node
///   OutPut        : LinkedList
//    Description   : Used to display linklist
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLLL<T> :: Display()
{
   SinglyLLLnode<T> * temp =NULL;
    int iCnt = 0;

  temp = this ->first;

for(iCnt= 1; iCnt <= this ->iCount; iCnt++)         
{
    cout<<" | " <<temp -> data<<" | ->";
    temp = temp -> next;
}
cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : Count
//    Input         : Data of node
///   OutPut        : Count of number of node
//    Description   : Used to Counting nodes
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
int SinglyLLL<T> :: Count()
{
return this ->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : InsertATPos
//    Input         : Data of node
///   OutPut        : Nothing
//    Description   : Used to insert node at given position
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
   SinglyLLLnode<T> * newn = NULL;
   SinglyLLLnode<T> * temp = NULL;

   int iCnt = 0; 

if(pos < 1 || pos >this -> iCount +1)
{
    cout<<"Invalid Position\n";
    return;
}

if(pos ==1)
{
    this ->InsertFirst(no);
}
else if(pos == this ->iCount + 1)
{
    this -> InsertLast(no);
}
else
{
    newn = new SinglyLLLnode<T>(no);

    temp = this ->first;

    for(iCnt = 1; iCnt < pos -1; iCnt++)
    {
        temp = temp -> next;
    }

    newn -> next = temp -> next;
    temp -> next = newn;

    this -> iCount++;
}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : DeleteAtPos
//    Input         : Data of node
///   OutPut        : Nothing
//    Description   : Used to delete node at given position
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
   SinglyLLLnode<T> * temp = NULL;
   SinglyLLLnode<T> * target = NULL;

    int iCnt = 0; 

if(pos < 1 || pos > this ->iCount)
{
    cout<<"Invalid Position\n";
    return;
}

if(pos ==1)
{
    this ->DeleteFirst();
}
else if(pos == this ->iCount)
{
    this ->DeleteLast();
}
else
{

    temp = this ->first;

    for(iCnt = 1; iCnt < pos -1; iCnt++)
    {
        temp = temp -> next;
    }
    
    target = temp -> next;
    temp -> next = target -> next;
    delete target;

    this ->iCount--;
}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : Set
//    Input         : Data of node
///   OutPut        : LinkedList
//    Description   : Used to replace the values of given positin in linklist
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Set(int pos, T Value)
{
    int i = 0;
    SinglyLLLnode<T>*temp = NULL;
    if(pos <= 0 || pos >iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    temp = first;
    for(i = 1; i < pos; i++)
    {
        temp = temp ->next;
    }
    temp -> data = Value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : Search
//    Input         : Data of node
///   OutPut        : Nothing
//    Description   : Used to search element present or not
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SinglyLLL<T> :: Search(T no)
{
    SinglyLLLnode<T> *temp = NULL;

    temp = first;
    while(temp != NULL)
    {
        if(temp -> data == no)
        {
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name : Frequency
//    Input         : Data of node
///   OutPut        : Nothing
//    Description   : Used to count the Frequency of particular element
//    Author        : Priyanka Vikas Bhor
//    Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>

int SinglyLLL<T> :: Frequency(T no)
{
    int iCount = 0;

    SinglyLLLnode<T> *temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        if(temp -> data == no)
        {
            iCount++;
        }
        temp = temp -> next;
    }
    return iCount;

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Singly Circular linked List using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyCLLnode
{
    public:
          T data;
          SinglyCLLnode<T>* next;

    SinglyCLLnode(T no)
    {
        this->data= no;
        this->next= NULL;
    }
};

template<class T>
class SinglyCLL
{
    private:
         SinglyCLLnode<T> *first;
         SinglyCLLnode<T> *last;
         int iCount;

        public:
            SinglyCLL();
            void InsertFirst(T );
            void InsertLast(T);
            void InsertAtPos(T, int);
            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);
            void Display();
            int Count();
};

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
   cout<<"Object of SinglyCL gets Created.\n";
    this ->first = NULL;
    this ->last =NULL;
    this ->iCount = 0;

}

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
  SinglyCLLnode<T> *newn = NULL;

  newn = new SinglyCLLnode<T>(no);

if(this->first == NULL && this->last == NULL)
{
    (this->first) = newn;
    this->last =newn;
}
else                              //Lineked list contains atleast one node.
{
    newn -> next = (this->first);
    this->first=newn;
}
   this->last->next=this->first;
    this->iCount++;    

}

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
   SinglyCLLnode<T> *newn = NULL;

   newn = new SinglyCLLnode<T>(no);

if(first == NULL)
{
    (this->first) = newn;
    this->last = newn;
}
else
{
    this->last->next=newn;
    this->last=newn;
}
   this->last->next = this->first;
   this->iCount++;
} 

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
   SinglyCLLnode<T> *newn = NULL;
   SinglyCLLnode<T> *temp = NULL;

if(pos < 1 || pos > this->iCount +1)
{
    cout<<"Invalid position";
    return;
}
if(pos == 1)
{
    InsertFirst(no);
}
else if(pos == this->iCount+1)
{
    InsertLast(no);
}
else
{
    newn = new SinglyCLLnode<T>(no);

    temp= this->first;
    for(int i=1; i<pos-1;i++)
    {
        temp=temp->next;
    }
    newn->next = temp->next;
    temp->next = newn;
    this->iCount++;
}
}

template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
  SinglyCLLnode<T> *temp = NULL;
if(this->first == NULL && this->last == NULL)
{
    return;
}
else if(this->first == this->last)
{
    delete this->first;
    this->first=this->last=NULL;
}
else
{ 
    temp = this->first;
    this->first =this->first->next;
    delete temp;
}
  this->last->next=this->first;
  this->iCount--;
}

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;
if(this->first == NULL && this->last == NULL)
{
    return;
}
else if(this->first == this->last)
{
    delete this->first;
    this->first=this->last=NULL;
}
else
{ 
    temp = this->first;
    while(temp->next != this->last)
    {
        temp = temp->next;
    }
    delete this->last;
    this->last = temp;
    this->last->next= this->first;
}
this->iCount--;
}

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
   
if(pos < 1 || pos >this-> iCount)
{
    cout<<"Invalid position";
    return;
}
if(pos == 1)
{
    DeleteFirst();
}
else if(pos == this->iCount)
{
    DeleteLast();
}
else
{
    temp= this->first;
    for(int i=1; i<pos-1;i++)
    {
        temp=temp->next;
    }
     target = temp->next;
    temp->next=target->next;
    delete target;
    this->iCount--;
}
}

template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> *temp = this->first;
do
{
    cout<< "|" <<temp ->data<< "| <->";
    temp = temp->next;
}while(temp != this->first);
  cout<<"\n";
}

template<class T>
int SinglyCLL<T> :: Count()
{
   return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///          Doubly Linear List using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLLLnode
{
    public:
         T data;
         DoublyLLLnode *next;
         DoublyLLLnode *prev;

         DoublyLLLnode(T no)
         {
            this ->data = no;
            this ->next = NULL;
            this ->prev = NULL;
         }
};

template<class T>
class DoublyLLL
{
    private:
      DoublyLLLnode<T> *first;
      int iCount;

    public:
        DoublyLLL();

     void InsertFirst(T);
     void InsertLast(T);
     void InsertAtPos(T,int);
     
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int);

     void Display();
     int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
     cout<<"Linked list gets Created\n";

     this->first= NULL;
     this->iCount = 0;
}

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this -> first == NULL)
    {
       this ->first = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T> ::InsertLast(T no)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this -> first == NULL)
    {
       this ->first = newn;
    }
    else
    {
       temp = this->first;

       while(temp ->next != NULL)
       {
           temp = temp -> next;
       }
       temp->next= newn;
       newn->prev = temp;
    }
    this->iCount++;
    
}

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
    int iCnt =0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;

        newn = new DoublyLLLnode<T>(no);

        for(iCnt = 1; iCnt< pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev= newn;

        temp->next=newn;
        newn->prev = temp;

        this->iCount++;

    }
}

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
   if(this->first == NULL)                    
    {
        return;
    }
    else if(this->first->next == NULL)           
    {
       delete this->first;
       this->first= NULL;
    }
    else                                         
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                    
    {
        return;
    }
    else if(this->first->next == NULL)           
    {
       delete this->first;
       this->first= NULL;
    }
    else                                         
    {
        temp = this -> first;

        while(temp ->next->next != NULL)
        {
              temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
       
    }
    this->iCount--;
}

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt =0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteFirst();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt< pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;

        this->iCount--;

    }
}

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T>*temp = NULL;

    temp = this-> first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp ->data<<" |<=>";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Doubly Circular linked list using generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
    public:
         T data;
         DoublyCLLnode<T> *next;
         DoublyCLLnode<T> *prev;

         DoublyCLLnode(T no)
         {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;

         }
};

template <class T>
class DoublyCLL
{
    private:
         DoublyCLLnode<T> * first;
         DoublyCLLnode<T> * last;
         int iCount;

        public:
          DoublyCLL();
          void InsertFirst(T);
          void InsertLast(T);
          void InsertAtPos(T ,int);
          void DeleteFirst();
          void DeleteLast();
          void DeleteAtPos(int);
          void Display();
          int Count();
};

    template <class T>
    DoublyCLL<T> :: DoublyCLL()
    {
       cout<<"Object of DoublyC gets Created.\n";
       this ->first = NULL;
       this ->last =NULL;
       this ->iCount = 0;

    }

    template <class T>
    void DoublyCLL<T> :: InsertFirst(T no)
    {
        DoublyCLLnode<T> * newn = NULL;

        newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = this->last=newn;
        this->first->next=this->first;
        this->first->prev= this->first;
    }
    else                              
    {
        newn -> next = this->first;
        newn->prev = this->last;

        this->first->prev = newn;
        this->last->next = newn;

        this->first = newn;
    }   
        this->iCount++;    
}

    template <class T>
    void DoublyCLL<T> :: InsertLast(T no)
    {
        DoublyCLLnode<T> *newn = NULL;

        newn = new DoublyCLLnode<T>(no);
    
    if(first == NULL)
    {
        this->first =this->last= newn;
        this->first->next = this->first;
        this->first->prev = this->first;
    }
    else
    {
        newn->prev = this->last;
        newn->next = this->first;

        this->last->next = newn;
        this->first->prev = newn;

        this->last = newn;
    } 
        this->iCount++;
    } 

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *newn = NULL;
    DoublyCLLnode<T> *temp = NULL;

    if((pos < 1) || (pos > this->iCount + 1))
    {
        cout<<"Invalid Position";
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);
        temp= this->first;
        
        for(int i= 1;i < pos-1; i++)
        {
            temp = temp ->next;
        }
        newn ->next = temp->next;
        newn->prev= temp;

        temp->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
    }

      this->first->prev= this->last;
      this->last->next = this->first;
      this->iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLnode<T> * temp = this->last;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        this->last->next = this->first;
        this->first->prev = this->last;

        delete temp;
    }
        this->iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    if((pos < 1) || (pos > this->iCount))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        DoublyCLLnode<T> * temp = this->first;

        for(int i= 1; i < pos-1; i++)
        {
            temp = temp ->next;
        }
        
        DoublyCLLnode<T> * targ = temp->next;

        temp->next = targ->next;
        targ ->next->prev = temp;

        delete targ;
        this->iCount--;
    }
}

template <class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> * temp= this->first;

    if(this->first == NULL)
    {
        return;
    }
    do
    {
        cout<< "| " << temp->data << " | <=> ";
        temp = temp->next;
    }while(temp != this->first);
    cout <<"\n";
}

template <class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Stack using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
         T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();
        void push(T);          
        T pop();              
        T peep();
        void Display();
        int Count();

};

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets Cretaed Successfully...\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next=this->first;
    this->first = newn;
    this->iCount++;

}

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first= this->first->next;
    delete temp;
    this->iCount--;
    return Value;

}   

template<class T>
T Stack<T> :: peep()
{
     T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;
    return Value;

}

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;
    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<" | \t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//           Queue using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();
        void enqueue(T);          
        T dequeue();              
        void Display();
        int Count();

};

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets Cretaed Successfully...\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
       this->last->next=newn;
       this->last = this->last->next;
    }
    this->iCount++;

}

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first= this->first->next;
    delete temp;
    this->iCount--;
    return Value;

}   

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"queue is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int Queue<T>:: Count()
{
    return this->iCount;
}


///////////////////////////////////////////////End of Library/////////////////////////////////////////////////////////////

int main()
{
   SinglyLLL<int> *obj = new SinglyLLL<int>();

   int iRet = 0;
   bool bRet = false;

   obj->InsertFirst(51);
   obj->InsertFirst(21);
   obj->InsertFirst(11);

   cout<<"Elements of linked list are:\n";
   obj->Display();

   iRet = obj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   obj->InsertLast(101);
   obj->InsertLast(111);
   obj->InsertLast(121);

   obj->Display();

   iRet = obj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   obj->DeleteFirst();
   
   obj->Display();


   iRet = obj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   obj->DeleteLast();

   obj->Display();

   iRet = obj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   obj->InsertAtPos(105,4);

    obj->Display();

   iRet = obj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   obj->DeleteAtPos(4);

   obj->Display();

   iRet = obj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   cout<<"Before Replacing\n";
   obj->Display();
   obj->Set(3,60);
   cout<<"After Replacing\n";
   obj->Display();

   bRet = obj->Search(51);

   if(bRet == true)
   {
      cout<<"Number is Found\n";
   }
   else
   {
      cout<<"Number is Found\n";
   }

   iRet = obj->Frequency(11);
   cout<<"Frequency of 11 is :"<<iRet<<"\n";

   delete obj;

   ////////////////////////////////////////////////////////////////////////////////
   //
   //
   ////////////////////////////////////////////////////////////////////////////////

   SinglyCLL<int> *SCobj = new SinglyCLL<int>();

   SCobj->InsertFirst(51);
   SCobj->InsertFirst(21);
   SCobj->InsertFirst(11);

   cout<<"Elements of linked list are:\n";
   SCobj->Display();

   iRet = SCobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   SCobj->InsertLast(101);
   SCobj->InsertLast(111);
   SCobj->InsertLast(121);

   SCobj->Display();

   iRet = SCobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   SCobj->DeleteFirst();
   
   SCobj->Display();


   iRet = SCobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   SCobj->DeleteLast();

   SCobj->Display();

   iRet = SCobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   SCobj->InsertAtPos(105,4);

    SCobj->Display();

   iRet = SCobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   SCobj->DeleteAtPos(4);   

   SCobj->Display();

   iRet = SCobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n"; 


   ////////////////////////////////////////////////////////////////////////////////
   //
   //
   ////////////////////////////////////////////////////////////////////////////////

   DoublyLLL<char> *dobj = new DoublyLLL<char>();

   dobj->InsertFirst('A');
   dobj->InsertFirst('B');
   dobj->InsertFirst('C');

   dobj->Display();
   cout<<"Number of Elements are :"<<dobj->Count()<<"\n";

   dobj->InsertLast('X');
   dobj->InsertLast('Y');
   dobj->InsertLast('Z');

   dobj->Display();
   cout<<"Number of Elements are :"<<dobj->Count()<<"\n";

   dobj->DeleteFirst();

   dobj->Display();
   cout<<"Number of Elements are :"<<dobj->Count()<<"\n";

   dobj->DeleteLast();

   dobj->Display();
   cout<<"Number of Elements are :"<<dobj->Count()<<"\n";

   dobj->InsertAtPos('$',4);

   dobj->Display();
   cout<<"Number of Elements are :"<<dobj->Count()<<"\n";

   dobj->DeleteAtPos(4);

   dobj->Display();
   cout<<"Number of Elements are :"<<dobj->Count()<<"\n";
   
   delete dobj;

   //////////////////////////////////////////////////////////////////////////////////
   //
   /////////////////////////////////////////////////////////////////////////////////

   DoublyCLL<int> *dcobj = new DoublyCLL<int>();


   dcobj->InsertFirst(51);
   dcobj->InsertFirst(21);
   dcobj->InsertFirst(11);

   cout<<"Elements of linked list are:\n";
   dcobj->Display();

   iRet = dcobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   dcobj->InsertLast(101);
   dcobj->InsertLast(111);
   dcobj->InsertLast(121);

   dcobj->Display();

   iRet = dcobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   dcobj->DeleteFirst();
   
   dcobj->Display();


   iRet = dcobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   dcobj->DeleteLast();

   dcobj->Display();

   iRet = dcobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   dcobj->InsertAtPos(105,4);

    dcobj->Display();

   iRet = dcobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";

   dcobj->DeleteAtPos(4);

   dcobj->Display();

   iRet = dcobj->Count();

   cout<<"Number of nodes are: "<<iRet<<"\n";


   ///////////////////////////////////////////////////////////////////////////////////
   //
   ///////////////////////////////////////////////////////////////////////////////////

   Stack<char> *sobj = new Stack<char>();

   sobj->push('a');
   sobj->push('b');
   sobj->push('c');
   sobj->push('d');

   sobj->Display();
   cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

   cout<<"return value of peep is :"<<sobj->peep()<<"\n";

   sobj->Display();
   cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

   cout<<"poped element is :"<<sobj->pop()<<"\n";

   sobj->Display();
   cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

   cout<<"poped element is :"<<sobj->pop()<<"\n";

   sobj->Display();
   cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

   sobj->push('e');

    sobj->Display();
   cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

     delete sobj;

   ///////////////////////////////////////////////////////////////////////////////////
   //
   ///////////////////////////////////////////////////////////////////////////////////
   
   Queue<double> *qobj = new Queue<double>();

   qobj->enqueue(11.5679);
   qobj->enqueue(21.5679);
   qobj->enqueue(51.5679);
   qobj->enqueue(101.578);

   qobj->Display();
   cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

   cout<<"removed element is :"<<qobj->dequeue()<<"\n";

   qobj->Display();
   cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

   cout<<"removed element is :"<<qobj->dequeue()<<"\n";

   qobj->Display();
   cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

   qobj->enqueue(121.456);

    qobj->Display();
   cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

   delete qobj;


     return 0;
}
