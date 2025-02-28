#include"Task.h"
class User{	
private:
    int m_id;
    string m_name;
    string m_password;
    vector<Task*>m_tasks;
    bool is_logged;	    
public:
    User():m_id(0),m_name(""),m_password(""),m_tasks{nullptr},is_logged(false){}
    User(int id,string name,string password): m_id(id), m_name(name), m_password(password),is_logged (false) {}
    User(User&& other) noexcept{
    m_id=other.m_id;
    m_name=move(other.m_name);
    m_password=move(other.m_password);
    m_tasks=move(other.m_tasks);
    is_logged=other.is_logged;
    }
    User(const User& other){
        m_id=other.m_id;
        m_password=other.m_password;
        for(int i=0;i<other.m_tasks.size();i++){
        m_tasks.push_back(new Task(*other.m_tasks[i]) );
        
    }
}
operator bool(){
    return is_logged; 
}
friend ostream& operator<<( ostream& print,const User& other){
    print<<other.m_id<<endl<<other.m_name<<endl<<other.m_password;
    for(int i=0;i<other.m_tasks.size();i++){
        print<<other.m_tasks[i];
    }
    print<<other.is_logged;
    return print;
  }
  friend istream& operator>>( istream& give,User& other){
    give >>other.m_id>>other.m_name>>other.m_password;
    for(int i=0;i<other.m_tasks.size();i++){
        give>>*(other.m_tasks[i]);
    }
    give >>other.is_logged;
    return give;
}
User& operator=(const User& other){
    if(this==&other){
        return *this;
    }
    m_id=other.m_id;
    m_name=other.m_name;
    m_password=other.m_password;
    for(int i=0;i<m_tasks.size();i++){
        delete m_tasks[i];
    }
    m_tasks.clear();
    for(int i=0;i<other.m_tasks.size();i++){
        m_tasks.push_back(new Task(*(other.m_tasks[i])) );

    } 
    return *this;
}
    ~User();
    int get_id(){
	    return m_id;
    }

    void addTask(Task* task){
	    if(task){
     m_tasks.push_back(task);
	    }
   else{cout<<"No";
   }
    }
    void deleteTask(int task_id){
	    for(int i=0;i<m_tasks.size();i++){
		    if(m_tasks[i]->get_task_id()==task_id){
			    delete m_tasks[i];
			    m_tasks.erase(m_tasks.begin()+i);
			    break;
		    }
	    }
    }
 void list_task()const{
	 for(int i=0;i<m_tasks.size();i++){
		m_tasks[i]->display();
		 cout<<endl;
	 }
 }
 void login(){
      is_logged=true;
 } 
 void logout(){
	 is_logged=false;
 }
    void edit_Task(int task_id,int uid,string title,string description,string deadline,Stat status,Prio priority,string category,bool completed){
	    for(int i=0;i<m_tasks.size();i++){
		    if(m_tasks[i]->get_task_id()==task_id){
			    m_tasks[i]->editTask( task_id, uid, title, description, deadline, status,priority, category, completed);
			    break;
		    }
        }
    }


    Task* searchTask(int task_id){
	    for(int i=0;i<m_tasks.size();i++){
		    if(task_id==m_tasks[i]->get_task_id()){
                              return m_tasks[i];
		    }
	    }
    }  


};
                          



