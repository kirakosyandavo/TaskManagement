#include <iostream>
#include <vector>
#include <string>
using namespace std;
 enum class Prio{
	Low=0,
    Mid=1,
    High=2,
    Urgent=99,
 };
istream& operator>>(istream& give,Prio &p){
  int a;
  give>>a;
  switch(a){
case static_cast<int>(Prio::Low):
	p=Prio::Low;
         break;
case static_cast<int>(Prio::Mid):
	p=Prio::Mid;
	break;
case static_cast<int>(Prio::High):
	p=Prio::High;
	break;
case static_cast<int>(Prio::Urgent):
	p=Prio::Urgent;
	break;
default:cout<<"this is invalid";
	  break;
  }
return give;
}	

 
enum class Stat{
	Not_Started=0,
	In_Progress=1,
	Urg=99,
};
istream& operator>>(istream& give,Stat& s){
  int a;
  give>>a;
  switch(a){
case static_cast<int>(Stat::Not_Started):
	s=Stat::Not_Started;
         break;
case static_cast<int>(Stat::In_Progress):
	s=Stat::In_Progress;
	break;
case static_cast<int>(Stat::Urg):
	s=Stat::Urg;
	break;
default:cout<<"this is invalid";
	  break;
  }
return give;
}


class Task {
private:
    int m_task_id;
    static int s_task_id_gen; 
    int m_uid;  
    string m_title;
    string m_description;
    string m_deadline;
    Stat m_status;
    Prio m_priority;
    string m_category;
    bool m_completed;
   
public:
    Task():m_uid{0},m_title{""},m_description{""},m_deadline{""},m_category{""},m_priority{Prio::Low},m_status{Stat::Not_Started},m_completed{0}{
        m_task_id=++s_task_id_gen;
    }
    Task(const int uid,const string& title, const string& description, const string& deadline,Stat status, Prio priority, const string& category, bool completed):
	    m_uid(uid),m_title(title),m_description(description),m_deadline(deadline),m_status(status),m_priority(priority),m_category(category),m_completed(completed){m_task_id=++s_task_id_gen;}
    Task(const Task& other):m_uid(other.m_uid),m_title(other.m_title),m_description(other.m_description),m_deadline(other.m_deadline),m_status(other.m_status),m_priority(other.m_priority),m_category(other.m_category),m_completed(other.m_completed){m_task_id=++s_task_id_gen;}
   Task(Task&& other)noexcept: m_uid(other.m_uid),m_title(move(other.m_title)),m_description(move(other.m_description)),m_deadline(move(other.m_deadline)),m_status(other.m_status),m_priority(other.m_priority),m_category(move(other.m_category)),m_completed(other.m_completed) {m_task_id=++s_task_id_gen;}
 ~Task()=default;

void set_Status(Stat status){
       m_status=status;
}
void set_Priority(Prio priority){
	m_priority=priority;
}

bool operator<(const Task& other){
   if(static_cast<int>(m_priority)<static_cast<int>(other.m_priority)){
    return true;
   }
   else return false;
} 
Task& operator++(){
    if(m_status==Stat::Not_Started){
        m_status=Stat::In_Progress;
    }
    if(m_status==Stat::In_Progress){
        m_status=Stat::Urg;
    }
    
    return *this;
}
friend ostream& operator<<( ostream & print,const Task& other){
        print<<other.m_task_id<<endl<<other.m_uid<<endl;
        print<<other.m_title<<endl<<other.m_description<<endl;
        print<<other.m_deadline<<endl<<static_cast<int>(other.m_status)<<endl;
        print<<static_cast<int>(other.m_priority)<<endl<<other.m_category<<endl;
        print<<other.m_completed; 
        return print; 
     }



friend istream& operator>>( istream& give, Task& other){
        give>>other.m_task_id>>other.m_uid>>other.m_title>>other.m_description;
        give>>other.m_deadline>>other.m_category;
        give>>other.m_completed;
	give>>other.m_priority>>other.m_status;
        return give;
    
     }
    
Task operator++(int){
    Task obj(*this);
      ++(*this);
      return obj; 
}
bool operator==(const Task& other)const{
    if(m_task_id==other.m_task_id){
        return true;
    }
	else return false;
}  

void display()const{
cout<<m_task_id<<endl<<m_uid<<endl<<m_title<<m_description<<endl<<m_deadline<<endl<<static_cast<int>(m_status)<<endl<<static_cast<int>(m_priority)<<endl<<m_category<<endl<<m_completed;
}
int get_task_id()const{
	return m_task_id;
}
void editTask(int new_id,int new_uid,const string& newTitle, const string& newDescription, const string& newDeadline,Stat new_status,Prio new_priority,  const  string& newCategory,bool new_completed){
	m_task_id = new_id;
	m_uid = new_uid;
	m_title = newTitle;
	m_description = newDescription;
	m_deadline = newDeadline;
	m_status = new_status;
	m_priority = new_priority;
	m_category = newCategory;
}
}; 
int Task::s_task_id_gen=0;


