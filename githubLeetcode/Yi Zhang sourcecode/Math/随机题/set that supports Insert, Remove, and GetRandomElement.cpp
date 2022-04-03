#include "all.h"
//Implement a set that supports Insert, Remove, and GetRandomElement
// Jul. 8, 2011 12:17am
//
//Implement a setlike data structure that supports Insert, Remove, and GetRandomElement efficiently.
//
//implementing this in the context of a load-balancer:
//the set represents the current available servers
//(which can come or go arbitrarily) and
//for every piece of traffic you want to route it to a randomly-chosen server.
//
//the dumbest version of GetRandomElement to
//pick a random number < size of collection, then iterate that many elements through.
//Sometimes that unsticks people. If it doesn't,
//I ask them about a data structure that supports GetRandomElement well but would be slow for Insert and Remove.
//I further insist that it be uniform with respect to the number of currently-live servers,
//not the number of insertions minus removals of those servers
//(so if I insert "A" once and "B" a million times, GetRandomElement still returns A as often as B).

//
//SOLUTIONS
//==========
//I know of two good solutions --- tree-based and hash-table / vector based.
//
//* The tree solution is just to implement your own binary search tree, use standard balanced-tree insert/remove, and use the "select-nth-element-from-a-tree" trick to get a random element.
//* The hash-table/vector solution is to keep a vector of all elements in the set and a hash-table that maps the element to its index in the vector.
//  - Insert adds the element to the end of the vector if it isn't already present in the hash table
//  - GetRandomElement picks a random element in the vector
//  - Remove finds the vector-index of the to-be-removed element via the hash table, swaps it with the last element in the vector, and then removes the last element of the vector (updating the newly-swapped element's index in the hash table as well)
//



template<class T>
class RandomSet
{
public:
	vector<T> vec;
	map<T,unsigned> mapVec;
	bool insert(const T& val)
	{
		if(mapVec.find(val)==mapVec.end()){
            vec.push_back(val);
            mapVec[val]=vec.size()-1;
            return true;
        }
        return false;
	}
	void remove(const T& val)
	{
		typename map<T,unsigned>::iterator it;
		if( (it=mapVec.find(val))!=mapVec.end()){
			unsigned index=it->second;
			vec.erase(vec.begin()+index);
			mapVec.erase(it);
		}
	}
	T getRandomElement() const
	{
        srand(time(NULL));
		return vec[rand()%vec.size()];
	}
};


int main()
{
    RandomSet<char*> rs;
    printf("%d\n",rs.insert("aa"));
    print_vector<char*> (rs.vec);
    printf("%d\n",rs.insert("aa"));
    print_vector<char*> (rs.vec);
    rs.insert("bb");
    print_vector<char*> (rs.vec);
    printf("%s\n",rs.getRandomElement());
    printf("%s\n",rs.getRandomElement());

    rs.remove("aa");
    print_vector<char*> (rs.vec);
    rs.remove("cc");
    print_vector<char*> (rs.vec);
}
