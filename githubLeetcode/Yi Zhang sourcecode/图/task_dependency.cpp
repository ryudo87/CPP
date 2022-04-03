#include "all.h"
//Task dependency	Jun. 30, 2010 8:23pm
//You are implementing a task workflow framework that executes tasks serially based on their dependencies. The framework is to accept tasks in random order via an AddTask() member function. Another member function called GetRunList() is to return a sorted array/list/vector of tasks such that the first task in the container has no dependencies; the second task either has no dependencies or depends on the first task only, etc. 
//
//Each task knows about its own name and the names of its direct dependencies. Consider the below example (Normally, I draw this as a directed graph): 
//
//A --> B 
//B --> C 
//B --> D 
//C --> D 
//
//In the above case, Task D knows that its name is "D" and that its dependencies are called "B" and "C". 
//
//Describe the implementation of AddTask() and GetRunList(). 
//
//------------------------------ 
//
//One possible solution to the problem (in Python-like pseudo-code): 
//
//-- We keep track of a dict of {task: all-direct-and-indirect-dependencies}. 
//
//-- AddTask() just populates the above map. When a new task is presented, the dict is updated such that the tasks dependencies and the dependencies of dependencies, etc. are recursively added to the dict. 
//
//-- GetRunList() builds a list of tasks from the dict and then runs a sort over the list where the local comparator function between two tasks is: 
//
//def Comparator(task_a, task_b): 
//if task_manager.DependsOn(task_a, task_b): 
//return -1 
//if task_manager.DependsOn(task_b, task_a): 
//return 1 
//return 0 
//
//
//[How do you elaborate the question to candidates?] 
//
//Typically explaining the questions doesn't take any time or effort if I draw the dependency graph. The problem then becomes immediately obvious. 
//
//One point that might require clarification is the fact that AddTask() can be called with a random order of tasks, i.e. we might call AddTask(D) first and then AddTask(A) and then AddTask(B), etc. 
//
//Also note that, good candidates typically ask about whether cyclic dependencies are allowed and the answer is no for the sake of simplicity. 
//
//
//[Why this works well -- sell us!] 
//
//The problem is seemingly very simple but, depending on how it is implemented, requires understanding of graphs, associative data structures and recursion. If you ask it as a coding question, it will also test whether the candidate understands how to use custom comparators with the sort functionality in her/his language of choice (which is a good way to filter out senior candidates). 
//
//The question is also quite flexible so if the candidate nails it down quick, you can ask follow on questions and if the candidate is struggling, you can skip either AddTask() or GetRunList(). 
//
//
//[Areas that have tripped up candidates when you gave this before.] 
//
//Some struggle with the fact that tasks can be presented to AddTask() in a random order and they write code that assumes AddTask() will see the tasks in the "correct" order, which is why I emphasize this upfront and keep repeating it. 
//
//Also, some candidates think this is an enormously long question. If I sense that they are feeling that way, I try to emphasize that the question is not a trick question and it can be implemented in a minimal amount of lines of code if s/he uses the proper data structures. 
//
//
//[What hints do you give when the candidate is stuck?] 
//
//For AddTask(), I hint that using an associative container that relates a task to its direct and indirect dependencies might help. Once I say this, almost everyone except the weak candidates will write AddTask() just fine. 
//
//For GetRunList(), I hint that the problem can be stated as a sorting problem with a custom comparator. 
//
//
//[Follow-on questions this leads to.] 
//
//A quick follow up is to ask how to deal with task priorities. Depending on the quality of the candidate this might take 5 minutes to answer or 5 seconds: Just add a priority comparison at the end of the custom comparator; right before "return 0" line. 
//
//A more detailed follow up is to ask how to deal with parallel execution. This is an open ended question. The answer I am looking for is for the candidate to suggest that we might be able to "divide" the graph into smaller subgraphs that don't depend on each other except at the very last task and execute those subgraphs in parallel. 
//
//
//[What else?] 
//
//The fastest answer I got to this question was in 5 minutes (The candidate received an offer). It usually takes candidates 15-25 minutes to answer.
//

class task_workflow
{
public:
	class Task
	{
	public:
		char name;
		Task(const Task& t){name=t.name;}
		Task():name(0){}
		bool operator<(const Task& t2) const
		{	return name<t2.name;
		}

		bool operator==(const Task& t2){
			return name==t2.name;
		}	
	};


	static map<Task,vector<Task> > taskMap;
	static vector< pair<Task,Task> > direct;


	void add_depend(vector<Task> &vec, Task dependency){
		//vector<Task> v=[dependency];
		for(unsigned i=0;i<direct.size();++i){
			if(direct[i].first==dependency){
				vec.push_back(direct[i].second);
				add_depend(vec,direct[i].second);
			}
		
		}
	}
	void AddTask(const Task& task){
		vector<Task> vec;
		for(unsigned i=0;i<direct.size();++i){
			if(direct[i].first==task){
				vec.push_back(direct[i].second);
				add_depend(vec,direct[i].second);
			}
		}

		taskMap[task]=vec;

	}
	
	static bool compf(const Task& t1,const Task& t2){
			vector<Task> v1=taskMap[t1];
			for(unsigned i=0;i<v1.size();++i)
				if(v1[i]==t2) return true;//B depends on A
			return false;
	}

	vector<Task> GetRunList(){
		vector<Task> result;
		for(map<Task,vector<Task> >::iterator it=taskMap.begin();it!=taskMap.end();++it){
			result.push_back(it->first);
		}
		sort(result.begin(),result.end(),compf);
		return result;
	}
};

int main()
{
	
	return 0;
}
