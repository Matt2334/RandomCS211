#include <iostream>
#include <vector>
using namespace std;

class Task{
    private:
        string taskName;
        string priority;
        string status;
    public:
        Task(){
            taskName="";
            priority="";
            status="";
        }
        Task(string ts, string p, string s){
            taskName=ts;
            priority=p;
            status=s;
        }
        void setTaskName(string ts){taskName=ts;}
        void setPriority(string p){priority=p;}
        void setStatus(string s){status=s;}

        string getTaskName(){return taskName;}
        string getPriority(){return priority;}
        string getStatus(){return status;}
        
        Task(const Task &t){
            taskName=t.taskName;
            priority=t.priority;
            status=t.status;
        }
        Task& operator=(const Task &rhs){
            if(this==&rhs) return *this;
            taskName=rhs.taskName;
            priority=rhs.priority;
            status=rhs.status;
            return *this;
        }
};
void addTask(vector<Task> &a, string ts, string p, string s){
    Task b(ts, p, s);
    a.push_back(b);
}
void displayTasks(vector<Task> &a){
    for(int i=0;i<a.size();i++){
        cout<<a[i].getTaskName()<<" "<<a[i].getPriority()<<" "<<a[i].getStatus()<<endl;
    }
}
void deleteTasks(vector<Task> &a){
    a.clear();
}
int main(){
    vector<Task> TaskList;
    Task one("foo", "bar", "In Progress");
    cout<<one.getTaskName()<<endl;
    Task two(one);
    cout<<two.getPriority()<<endl;
    Task three("bro", "urgent", "Go Already");
    three=two;
    cout<<three.getTaskName()<<endl;

    addTask(TaskList, "Attack","High","In Progress");
    addTask(TaskList,"Hit","Medium","Not Started");
    addTask(TaskList,"Run","Low","Failed");
    displayTasks(TaskList);
    deleteTasks(TaskList);
    return 0;
}
