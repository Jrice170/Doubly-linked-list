

#include "MyList.h"


void get_identity(std::string &my_id)
{

  my_id = "jmr3by";

}

// if leak de bug here
template <typename T>
MyList<T>::~MyList()
{
    if(size() > 0)
    {

      Node<T> * delete_pointer;
      delete_pointer = m_sentinel;

      if(delete_pointer->m_next != nullptr)
      {

        delete_pointer = m_sentinel->m_next;
        while(delete_pointer != m_sentinel)
        {
          /// sets m_prev to point to sentinel
          delete_pointer->m_next->m_prev = m_sentinel;
          /// the next pointer to semtinel equal to the none deleted node
          m_sentinel->m_next = delete_pointer->m_next;
          delete  delete_pointer;
          delete_pointer = m_sentinel->m_next;

        }

      }
      delete  m_sentinel; // base node

    }
    else
    {

      delete m_sentinel; // base node

    }



}

template <typename T>
MyList<T>::MyList()
{

    m_sentinel = new Node<T>(nullptr,nullptr);

    m_size =  0;

}

template <typename T>
MyList<T> & MyList<T>::operator =(const MyList<T> &source)
{
    clear();

    Node<T> * pterr = source.m_sentinel;
    for(int i =0;i<source.m_size;i++)
    {
        pterr = pterr->m_next;
        push_back(pterr->m_element);
    }

}


template <typename T>
MyList<T>::MyList(const MyList<T> & source)
{

    m_sentinel = nullptr;
    m_size =0;
    m_sentinel = new Node<T>(nullptr,nullptr); // contruct base node
    Node<T> * ptr = source.m_sentinel;

    for(int i =0;i<source.m_size;i++)
    {
        ptr = ptr->m_next;
        push_back(ptr->m_element);

    }


}

template <typename T>
T & MyList<T>::front()
{
    return (m_sentinel->m_next->m_element);

}


template <typename T>
T & MyList<T>::back()
{
    return (m_sentinel->m_prev->m_element);
}

template <typename T>
void MyList<T>::assign(int count, const T &value)
{

  clear();
  for(int i =0;i<count;i++)
  {
      push_front(value);

  }

}
template <typename T>
void MyList<T>::clear()
{

  if(m_sentinel->m_next != nullptr && m_sentinel->m_next != nullptr)
  {
    Node<T> * remove = m_sentinel;
    remove = remove->m_next;
    while(remove !=m_sentinel)
    {

        remove->m_next->m_prev = m_sentinel;
        m_sentinel->m_next = remove->m_next;
        delete  remove;
        remove = m_sentinel->m_next;
    }
    m_sentinel->m_next = nullptr;
    m_sentinel->m_prev = nullptr;
  }
  m_size = 0;
}
template <typename T>
void MyList<T>::push_front(const T &x)
{
  /// if not empty
  if((m_sentinel->m_next != nullptr) && (m_sentinel->m_prev != nullptr))
  {

     Node<T> * Curr = new Node<T>(x,m_sentinel,m_sentinel->m_next);
     // bug fix
     m_sentinel->m_next->m_prev = Curr; //
     m_sentinel->m_next = Curr;

     m_size = m_size + 1;
  } /// start off empty list so that others can build on it
  else
  {
    Node<T> * Curr = new Node<T>(x,m_sentinel,m_sentinel);
    m_sentinel->m_next = Curr;
    m_sentinel->m_prev = Curr;
    m_size = m_size + 1;

  }

}
template <typename T>
void MyList<T>::push_back(const T &x)
{
  if((m_sentinel->m_next != nullptr) && (m_sentinel->m_prev != nullptr))
  {

    Node<T> * Curr = new Node<T>(x,m_sentinel->m_prev,m_sentinel);

    m_sentinel->m_prev->m_next = Curr;
    m_sentinel->m_prev = Curr;

    m_size = m_size + 1;

  }
  else
  {

    Node<T> * Curr = new Node<T>(x,m_sentinel,m_sentinel);
    m_sentinel->m_next = Curr;
    m_sentinel->m_prev = Curr;
    m_size = m_size + 1;

  }

}

template <typename T>
void MyList<T>::insert(int i, const T &x)
{
    if(size() != 0)
    {
        Node<T> * Curr = m_sentinel;
        Node<T> * Track_pos;
        Curr = Curr->m_next;
        for(int move =0;move<i && i<size();move++)
        {
          Curr = Curr->m_next;

        }
        Track_pos = new Node<T>(x,Curr->m_prev,Curr);
        Curr->m_prev->m_next = Track_pos; /// no errors here
        Curr->m_prev = Track_pos;
        m_size = m_size + 1;


    }

}


template <typename T>
void MyList<T>::remove(T value)
{

  if(size() !=0)
  {
      Node<T> * Target = m_sentinel;
      Node<T> * Delete;
      Target = Target->m_next;
      while(Target != m_sentinel)
      {
          if(Target->m_element == value)
          {
              Delete = Target;
              Delete->m_next->m_prev = Delete->m_prev;
              Delete->m_prev->m_next = Delete->m_next;
              delete Delete;
              Target = Target->m_next;
              // remove that node
              m_size--;
          }
          else
          {

              Target = Target->m_next;

          }


      }

  }

}


template <typename T>
void MyList<T>::erase(int i)
{

    Node<T> * Tracker = m_sentinel;
    Tracker = Tracker->m_next;
    for(int j = 0;j<i;j++)
    {

      Tracker = Tracker->m_next;


    }
    Tracker->m_next->m_prev = Tracker->m_prev;
    Tracker->m_prev->m_next = Tracker->m_next;
    delete Tracker;
    m_size--;
}


template <typename T>
bool MyList<T>::empty()
{
    return (size()==0);

}


template <typename T>
int MyList<T>::size()
{

    return m_size;

}



template <typename T>
void MyList<T>::pop_back()
{

    Node<T> * Delete = m_sentinel->m_prev;
    m_sentinel->m_prev = Delete->m_prev;
    Delete->m_prev->m_next = m_sentinel;
    delete  Delete;
    m_size--;

}

template <typename T>
void MyList<T>::pop_front()
{
    Node<T> * Delete = m_sentinel->m_next;
    m_sentinel->m_next = Delete->m_next;
    Delete->m_next->m_prev = m_sentinel;
    delete Delete;
    m_size--;

}


template <typename T>
void MyList<T>::Display_all()
{
  Node<T> * track = m_sentinel;

  for(int i = 0;i<size();i++)
  {
      track = track->m_next;
      cout<<track->m_element<<" ";


  }
  cout<<endl;

}
template <typename T>
void MyList<T>::reverse()
{
    /// how to reverse the linked list
    // one pointer going one way the other way
    // ???? ??? ??? flip flop values

  if(size() != 0)
  {
      T Change_over,Change_over_2;
      Node<T> * reverse_pointer = m_sentinel;
      Node<T> * Forward_pointer = m_sentinel;
      //reverse_pointer = reverse_pointer->m_next; // update position
      //Forward_pointer = Forward_pointer->m_prev; // update position
      int count =0;
      while(count<size()/2)
      {
          reverse_pointer = reverse_pointer->m_next;
          Forward_pointer = Forward_pointer->m_prev;
          Change_over =  Forward_pointer->m_element;
          Change_over_2 = reverse_pointer->m_element;
          reverse_pointer->m_element = Change_over;
          Forward_pointer->m_element = Change_over_2;

          count = count + 1;
      }
  }


}
