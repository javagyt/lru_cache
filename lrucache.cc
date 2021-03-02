#include "lru_cache_test.h"

void lrucache::setHead(ListNode* node)
{
  node->pre = head;
  node->next = head->next;
  head->next->pre = node;
  head->next = node;
}

int lrucache::set(int key, int value)
{
  auto it = cache.find(key);
  if(it != cache.end())
  {
    //ListNode* node = it->second;
  }else {
    //key not exitst, create a new node
    ListNode* NewNode = new ListNode(key, value);
    //add to cache
    cache[key] = NewNode;
    setHead(NewNode);
    size++;
    if(size > _capacity)
    {
      //if cache full, remove node from tail
      ListNode* removeNode = removeTail();
      cache.erase(removeNode->_key);
      delete removeNode;
      size--;
    }
  }
}

int lrucache::get(int key)
{
  if(!cache.count(key))
	  return -1;
  //if key exitst in cache
  ListNode* node = cache[key];
  moveToHead(node);

  return node->_value;
}

void lrucache::moveToHead(ListNode* node)
{
  removeNode(node);
  setHead(node);
}

void lrucache::removeNode(ListNode* node)
{
  node->pre->next = node->next;
  node->next->pre = node->pre;
}

ListNode* lrucache::removeTail()
{
  ListNode* tailNode = tail->pre;
  removeNode(tailNode);

  return tailNode;
}
