// Singleton Class
//
//Good Candidate - A good candidate can explain non-lazy and lazy instantiation
// Can explain why early instantiation (static member) is thread safe. Can make the lazy instantiation approach thread safe with synchronization.



//the object used is not on the local stack. Some of the downfalls of the object include that, like a global variable, it can be hard to tell what chunk of code corrupted memory, when a bug is found, since everyone has access to it.
//
//
//The main advantage of the singleton is that its existence is guaranteed[citation needed].
//
//
//
//common use of the singleton design pattern is for application configurations. closest alternative would be to create a single global struct. This had the lack of clarity as to where this object was instantiated, as well as not guaranteeing the existence of the object.
//



class Singleton
{
    static volatile Singleton* instance;
	/*static bool m_destroyed;*/
  /*	 static RWLock rwlock_;  */
	Singleton(){}
	virtual ~Singleton(){}
public:
	static volatile Singleton* getInstance()
	{
        //因为每次判断是否为空都需要被锁定，如果有很多线程的话，就会造成大量线程的阻塞。
        //于是出现了双重锁定。
		if(NULL==instance){
			/*Lock(m_mutex);*/
			if(NULL==instance){
				//if(m_destroyed);
				//	/*OnDeadReference();*/
				//else
					instance=new Singleton();

			}
			/*UnLock(m_mutex);*/
		}
		return instance;
	}

};

volatile Singleton * Singleton::instance=NULL;



int _tmain(int argc, _TCHAR* argv[])
{
	volatile Singleton *sgn=Singleton::getInstance();
}

//c++11标准做法.
// c++11 局部静态变量已经是线性安全了
class Singleton {
public:
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }
    
private:
    Singleton(){}
};

// early instantiation
class Singleton
{
    static volatile Singleton* instance;
public:
    static volatile Singleton* getInstance() {return instance;}
    void  test() volatile {cout<<"test"<<endl;}
};
 
volatile Singleton* Singleton::instance =  new Singleton(); 
