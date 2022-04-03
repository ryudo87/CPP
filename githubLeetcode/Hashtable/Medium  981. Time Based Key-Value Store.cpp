// 返回值的时间戳不能大于查询的时间戳，假如有多个相同值，返回时间戳最大的那个，若查询不到就返回空。
// 因为要同时保存三个量，而且还要提供快速查询功能，可以使用 Map of Maps 的数据结构，外层可以使用一个 HashMap，因为对于 key 值没有顺序要求，
// 而内层要使用一个 TreeMap，因为时间戳的顺序很重要。
//在 set 函数中直接将数据插入数据结构中，在 get 中，用一个 upper_bound 来进行快速查找第一个大于目标值的位置，往后退一位，就是不大于目标值的位置。
//但是在退之前要判断得到的位置是否是起始位置，是的话就没法再往前退一位了，直接返回空串，不是的话可以退一位并返回即可

class TimeMap {
    unordered_map<string /*key*/, map<int /*timestamp*/, string /*value*/>> dataMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dataMap[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = dataMap[key].upper_bound(timestamp);
        return (it == dataMap[key].begin()) ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
