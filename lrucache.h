#ifndef LRU_CACHE_TEST
#define LRU_CACHE_TEST

#include <map>

struct ListNode
{
  int _key, _value;
  ListNode* pre;
  ListNode* next;
  ListNode() : _key(0), _value(0), pre(nullptr), next(nullptr){}
  ListNode(int key, int value) : _key(key), _value(value), pre(nullptr), next(nullptr){}
};

class lrucache
{
public:
  lrucache(int capacity): _capacity(capacity), size(0)
  {
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->pre = head;
  }

  ~lrucache()
  {
    auto it = cache.begin();
    for(;it != cache.end();)
    {
      delete it->second;
      it->second = nullptr;
      cache.erase(it++);
    }
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
  }

  int set(int key, int value);
  void setHead(ListNode* node);
  int get(int key);
  void moveToHead(ListNode* node);
  void removeNode(ListNode* node);
  ListNode* removeTail();

private:
  int _capacity;
  int size;
  ListNode* head;
  ListNode* tail;
  std::map<int, ListNode*> cache;
};

#endif
