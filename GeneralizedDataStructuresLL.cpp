
///////////////////////////////GNERALISED DATA STRUCTURE LIBRARY///////////////////////////
/*
--------------------------------------------------------------------------------------------------------------
     Type                       Name of class for node              Name of class for functionality
--------------------------------------------------------------------------------------------------------------
                        
    SinglyLinear                    SinglyLLLnode                        SinglyLLL            DONE
    SinglyCircular                  SinglyCLLnode                        SinglyCLL            DONE
    DoublyLinear                    DoublyLLLnode                        DoublyLLL            DONE
    DoublyCircular                  DoublyCLLnode                        DoublyCLL            DONE
--------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////
//   SINGLY LINEAR LINKED LIST USING GENERIC APPROACH
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode 
{
    public : 
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:                                //IMPORTANT
        SinglyLLLnode<T> *first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T , int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();

};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of singly ll gets created"<<"\n";
    this->first = NULL;
    this->iCount = 0;

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertFirst
// Input  :          Data of node
// Output  :         Nothing
// Description :     Used to insert node at first Position
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    newn = new SinglyLLLnode<T>(no);
            
    newn->next = this->first;
    this->first = newn;
    
    this->iCount++;

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Input  :          Data of node
// Output  :         Nothing
// Description :     Used to insert node at last Position
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> ::InsertLast(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    SinglyLLLnode<T> * temp = NULL;

    
    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;

        }
        temp->next = newn;  
        
    }
    this->iCount++;


}


///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertAtPos
// Input  :          Data of node
// Output  :         Nothing
// Description :     Used to insert node at given Position
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no , int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position"<<"\n";
    }
    if(pos == 1 )
    {
        this->InsertFirst(no);
    
    }
    else if(pos == this->iCount + 1) 
    {
        this->InsertLast(no);
        

    }
    else
    {
        newn = new SinglyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 0; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;

    }

}


///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteFirst
// Input  :          Data of node
// Output  :         Nothing
// Description :     Used to delete node at first Position
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)   // else if(this->iCount == 1)
    {
            delete this->first;
            this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
            
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteLast
// Input  :          Data of node
// Output  :         Nothing
// Description :     Used to delete node at first Position
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;
        if(this->first == NULL)
    {
            return;
    }
    else if(this->first->next == NULL)   // else if(iCount == 1)
    {
            delete this->first;
            this->first = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next->next != NULL)
        {
            temp =  temp->next;

        }
        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteAtPos
// Input  :          Data of node
// Output  :         Nothing
// Description :     Used to delete node at given Position
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position"<<"\n";
    }
    if(pos == 1 )
    {
        this->DeleteFirst();
    
    }
    else if(pos == this->iCount) 
    {
        this->DeleteLast();
        

    }
    else
    {
        temp = this->first;

        for(iCnt = 0; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        delete target;

        this->iCount--;

    }

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Display
// Input  :          Data of node
// Output  :         Nothing
// Description :     Used to display all the nodes in linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    temp = this->first;
    

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Count
// Input  :          Data of node
// Output  :         Nothing
// Description :     Used to count the no of nodes in the given linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////
//   SINGLY CIRCULAR LINKED LIST USING GENERIC APPROACH
/////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyCLLnode 
{
    public : 
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:                                //IMPORTANT
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T , int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   SinglyCLL (Constructor)
// Input  :          None
// Output  :         None
// Description :     Initializes singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Object of singly circular ll gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertFirst
// Input  :          Data of node
// Output  :         Nothing
// Description :     Inserts node at first position in singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = this->last = newn;
        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
        this->last->next = this->first;
    }
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Input  :          Data of node
// Output  :         Nothing
// Description :     Inserts node at last position in singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = this->last = newn;
        this->last->next = this->first;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
        this->last->next = this->first;
    }
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertAtPos
// Input  :          Data of node, Position
// Output  :         Nothing
// Description :     Inserts node at specified position in singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertAtPos(T no , int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
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
        newn = new SinglyCLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteFirst
// Input  :          None
// Output  :         Nothing
// Description :     Deletes first node from singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = this->last = NULL;
    }
    else
    {
        SinglyCLLnode<T> * temp = this->first;
        this->first = this->first->next;
        delete temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteLast
// Input  :          None
// Output  :         Nothing
// Description :     Deletes last node from singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = this->last = NULL;
    }
    else
    {
        SinglyCLLnode<T> * temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }

        delete this->last;
        this->last = temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteAtPos
// Input  :          Position
// Output  :         Nothing
// Description :     Deletes node at specified position in singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
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
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Display
// Input  :          None
// Output  :         Displays linked list
// Description :     Displays all elements of singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }

    SinglyCLLnode<T> * temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != this->first);

    cout<<"(First)\n";
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Count
// Input  :          None
// Output  :         Integer
// Description :     Returns number of nodes in singly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}


/////////////////////////////////////////////////////////////////
//   DOUBLY LINEAR LINKED LIST USING GENERIC APPROACH
/////////////////////////////////////////////////////////////////


#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public : 
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;
    
        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
    
       DoublyLLLnode<T> *first;
       int iCount;  //hold no of elements in LL

    public:

       DoublyLLL();

       void InsertFirst(T);
       void InsertLast(T);
       void InsertAtPos(T , int);

       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int);

       void Display();
       int Count();
};

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DoublyLLL (Constructor)
// Input  :          None
// Output  :         None
// Description :     Initializes doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Doubly Linear Linked list gets cretaed\n";
    this->first = NULL;
    this->iCount = 0;

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertFirst
// Input  :          Data of node
// Output  :         Nothing
// Description :     Inserts node at first position in doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> ::  InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    newn = new DoublyLLLnode<T>(no);
    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;

    }
    this->iCount++;

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Input  :          Data of node
// Output  :         Nothing
// Description :     Inserts node at last position in doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> ::  InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);
    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;

    }
    this->iCount++;

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertAtPos
// Input  :          Data of node, Position
// Output  :         Nothing
// Description :     Inserts node at given position in doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> ::  InsertAtPos(T no , int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount + 1))
    {
        cout<<"Invalid position \n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);

    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt ++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
        
        this->iCount++;
    }
   
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteFirst
// Input  :          None
// Output  :         Nothing
// Description :     Deletes first node from doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> ::  DeleteFirst()
{
    
    if(this->first == NULL) //LL is empty
    {
        cout<<"Linked list is empty";
        return;
    }
    else if(this->first->next == NULL)  //LL contains one node
    {
        delete this->first;
        this->first = NULL;

    }
    else                               //LL contains more than one node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;

    }
    this->iCount--;

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteLast
// Input  :          None
// Output  :         Nothing
// Description :     Deletes last node from doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> ::  DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;
    if(this->first == NULL) //LL is empty
    {
        cout<<"Linked list is empty";
        return;
    }
    else if(this->first->next == NULL)  //LL contains one node
    {
        delete this->first;
        this->first = NULL;

    }
    else                               //LL contains more than one node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;

}
///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteAtPos
// Input  :          Position
// Output  :         Nothing
// Description :     Deletes node at given position in doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> ::  DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position \n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();

    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt ++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;


        this->iCount--;
    }
    

}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Display
// Input  :          None
// Output  :         Displays linked list
// Description :     Displays all nodes of doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> ::  Display()
{
     DoublyLLLnode<T> *temp = NULL;
     temp = this->first;

     cout<<"NULL<=>";
     while(temp != NULL)
     {
       cout<<"| "<<temp->data<<" |<=>";
       temp = temp->next;
     
     }
      cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Count
// Input  :          None
// Output  :         Integer
// Description :     Returns number of nodes in doubly linear linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////
//   DOUBLY CIRCULAR LINKED LIST USING GENERIC APPROACH
/////////////////////////////////////////////////////////////////

#pragma pack(1)

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
    private:                                // IMPORTANT
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DoublyCLL (Constructor)
// Input  :          None
// Output  :         None
// Description :     Initializes doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of doubly circular ll gets created\n";
    this->first = NULL;
    this->last  = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertFirst
// Input  :          Data of node
// Output  :         Nothing
// Description :     Inserts node at first position in doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = this->last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
        newn->next = this->first;
        newn->prev = this->last;

        this->first->prev = newn;
        this->last->next  = newn;

        this->first = newn;
    }
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Input  :          Data of node
// Output  :         Nothing
// Description :     Inserts node at last position in doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = this->last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
        newn->prev = this->last;
        newn->next = this->first;

        this->last->next  = newn;
        this->first->prev = newn;

        this->last = newn;
    }
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertAtPos
// Input  :          Data of node, Position
// Output  :         Nothing
// Description :     Inserts node at given position in doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
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
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);
        DoublyCLLnode<T> *temp = this->first;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteFirst
// Input  :          None
// Output  :         Nothing
// Description :     Deletes first node from doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = this->last = NULL;
    }
    else
    {
        DoublyCLLnode<T> *temp = this->first;

        this->first = this->first->next;
        this->first->prev = this->last;
        this->last->next  = this->first;

        delete temp;
    }
    this->iCount--;
}
///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteLast
// Input  :          None
// Output  :         Nothing
// Description :     Deletes last node from doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = this->last = NULL;
    }
    else
    {
        DoublyCLLnode<T> *temp = this->last;

        this->last = this->last->prev;
        this->last->next  = this->first;
        this->first->prev = this->last;

        delete temp;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteAtPos
// Input  :          Position
// Output  :         Nothing
// Description :     Deletes node at specified position in doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
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
        DoublyCLLnode<T> *temp = this->first;

        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Display
// Input  :          None
// Output  :         Displays linked list
// Description :     Displays all nodes of doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }

    DoublyCLLnode<T> *temp = this->first;

    cout<<"<=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != this->first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Count
// Input  :          None
// Output  :         Integer
// Description :     Returns number of nodes in doubly circular linked list
// Author :          Neha Navin Desai
// Date :            06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}




////////////////////////////////////END OF LIBRARY//////////////////////////////////////////////////

int main()
{
    return 0;
}
