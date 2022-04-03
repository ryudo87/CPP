#include "all.h"
template<class T>
class BlockingQueue
{
	T* arr;
	int sz;
	int curIndex;
	pthread_mutex_t mu;
	pthread_cond_t full;
	pthread_cond_t empty;
public:

	BlockingQueue(int sz):curIndex(0),sz(sz){
		arr=new T[sz];
		pthread_mutex_init(&mu,NULL);
		pthread_cond_init(&full,NULL);
		pthread_cond_init(&empty,NULL);
	}
  
//	void printBQ(char *s){
//		pthread_mutex_lock(&mu);
//		cout<<s;
//		for(int i=0;i<curIndex;++i){
//			cout<<arr[i]<<",";
//		}
//		cout<<endl;
//		pthread_mutex_unlock(&mu);
//	}
  
	void push(T obj){
		pthread_mutex_lock(&mu);
		while(curIndex==sz){
			cout<<"PROC:"<<getpid()<<"wait"<<endl;
			pthread_cond_wait(&full,&mu);
			cout<<"PROC:"<<getpid()<<" wake up"<<endl;
		}
		arr[curIndex++]=obj;
		pthread_mutex_unlock(&mu);
		pthread_cond_signal(&empty);
		cout<<"PROC:"<<getpid()<<"signal empty"<<endl;
	}
	T pop(){
		pthread_mutex_lock(&mu);
		while(curIndex<=0){
			cout<<"PROC:"<<getpid()<<"wait"<<endl;
			pthread_cond_wait(&empty,&mu);
			cout<<"PROC:"<<getpid()<<" wake up"<<endl;
		}
		T obj=arr[--curIndex];
		pthread_mutex_unlock(&mu);
		pthread_cond_signal(&full);
		cout<<"PROC:"<<getpid()<<"signal full"<<endl;
		return obj;
	}
};

static pthread_mutex_t printLock;
static pthread_t ntid;
BlockingQueue<int> bq(2);

void printids(const char *s){
    pthread_mutex_lock(&printLock);
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    cout<<s<<" pid="<<pid<<", tid="<<tid<<endl;
    pthread_mutex_unlock(&printLock);
}

void* thread_function(void* arg){
	printids("new thread:");
	bq.push(1);
	bq.printBQ("son:");
	bq.push(3);
	bq.printBQ("son:");
	bq.push(5);
	bq.printBQ("son:");
	return ((void *)0);
}
int main()
{
	pthread_mutex_init(&printLock,NULL);
	int err=pthread_create(&ntid,NULL,thread_function,NULL);
	sleep(3);
	bq.pop();
	bq.printBQ("main BQ:");
	sleep(3);
	bq.pop();
	bq.printBQ("main BQ:");
	sleep(3);
	bq.pop();
	bq.printBQ("main BQ:");
	pthread_join(ntid,NULL);
	sleep(5);
	printids("main thread:");
}



////////////////////////////////////////////
template <typename T> class SynchronizedQueue
{
  std::queue<T> queue_;
  std::mutex mutex_;
  std::condition_variable condvar_;
  
  typedef std::lock_guard<std::mutex> lock;
  typedef std::unique_lock<std::mutex> ulock;
  
public:
  void push(T const &val)
  {
    lock l(mutex_); // prevents multiple pushes corrupting queue_
    bool wake = queue_.empty(); // we may need to wake consumer
    queue_.push(val);
    if (wake) condvar_.notify_one();
  }
  
  T pop()
  {
    ulock u(mutex_);
    while (queue_.empty())
      condvar_.wait(u);
    // now queue_ is non-empty and we still have the lock
    T retval = queue_.front();
    queue_.pop();
    return retval;
  }
};
////////////////////////////////////////////

//	　通过创建线程，线程将会执行一个线程函数，该线程格式必须按照下面来声明：
//	　　void * Thread_Function(void *)
//	　　创建线程的函数如下：
//	　　int pthread_create(pthread_t *restrict thread,
//	　　const pthread_attr_t *restrict attr,
//	　　void *(*start_routine)(void*), void *restrict arg);
//
//	　　下面说明一下各个参数的含义：
//
//	　　thread：所创建的线程号。
//
//	　　attr：所创建的线程属性，这个将在后面详细说明。
//
//	　　start_routine：即将运行的线程函数。
//
//	　　art：传递给线程函数的参数。




//最后说一下线程的本质。其实在Linux中，新建的线程并不是在原先的进程中，
//而是系统通过 一个系统调用clone()。该系统copy了一个和原先进程完全一样的进程，并在这个进程中执行线程函数。
//不过这个copy过程和fork不一样。 copy后的进程和原先的进程共享了所有的变量，运行环境。这样，原先进程中的变量变动在copy后的进程中便能体现出来。

//
//代码中如果没有pthread_join主线程会很快结束从而使整个进程结束，从而使创建的线程没有机会开始执行就结束了。加入pthread_join后，主线程会一直等待直到等待的线程结束自己才结束，使创建的线程有机会执行。
//
//　　pthread_join函数及linux线程
//
//　　pthread_join使一个线程等待另一个线程结束。
//
//　　代码中如果没有pthread_join主线程会很快结束从而使整个进程结束，从而使创建的线程没有机会开始执行就结束了。加入pthread_join后，主线程会一直等待直到等待的线程结束自己才结束，使创建的线程有机会执行。
//
//　　所有线程都有一个线程号，也就是Thread ID。其类型为pthread_t。通过调用pthread_self()函数可以获得自身的线程号。



