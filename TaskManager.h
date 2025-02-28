#include"user.h"
class TaskManager{ 	
 vector<User*>m_users;
 vector<Task*>m_all_tasks;
	public:TaskManager()=default;
	       TaskManager(const TaskManager & other){
		       for(int i=0;i<other.m_users.size();i++){
			       m_users.push_back(new User(*(other.m_users[i])));
		       }
	         for(int i=0;i<other.m_all_tasks.size();i++){
			 m_all_tasks.push_back(new Task(*other.m_all_tasks[i]));
		 }
	       }
           TaskManager(TaskManager&& other):m_users(move(other.m_users)),m_all_tasks(move(other.m_all_tasks)){}
	           void  display_task(int task_id){
		       for(int i=0;i<m_all_tasks.size();i++){
			       if(m_all_tasks[i]->get_task_id()==task_id){
				       m_all_tasks[i]->display();
			       }
		       }
		   }
		  void  add_task_for_user(int user_id,Task*other){
			  for(int i=0;i<m_users.size();i++){
				  if(m_users[i]->get_id()==user_id){
					  m_users[i]->addTask(other);
					  break;
				  }
			  }
			 }
		  void register_user(string name,string password){
			  User*user=new User(m_users.size()+1,name,password);
			  m_users.push_back(user);
		  }
		  void add_task( int task_id,int uid,string title,string description,string deadline,Stat status,Prio priority,string category,bool completed ){
			  Task*task=new Task( task_id, uid, title, description, deadline, status, priority, category, completed );
			  m_all_tasks.push_back(task);
		  }
                 void  edit_task(int task_id, int uid,string title, string description, string deadline, Stat status,Prio priority,string category,bool completed ){
		      for(int i=0;i<m_all_tasks.size();i++){
		        if(m_all_tasks[i]->get_task_id()==task_id){
		             m_all_tasks[i]->editTask(task_id, uid, title, description, deadline, status,priority,category,completed );
			     break;
			}
		      }	
		 }
           void delete_task(int uid,int task_id){
		   for(int i=0;i<m_users.size();i++){
			   if(m_users[i]->get_id()==uid){
				   m_users[i]->deleteTask(task_id);
				   break;
			   }
		   }

                    for(int i=0;i<m_all_tasks.size();i++){
			    if(m_all_tasks[i]->get_task_id()==task_id){
				    delete m_all_tasks[i];
				    m_all_tasks.erase(m_all_tasks.begin()+i);
				    break;
			    }
		    }
	   }
};
     


		   





