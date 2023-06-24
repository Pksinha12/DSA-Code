
class LRUCache 
{
  public:
   struct node 
    {
      int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) 
      {
          key = _key;
          val = _val;
          next = NULL;
          prev = NULL;
      }
    }; 

  node* head = new node(-1, -1); // creating new dummy nodes
  node* tail = new node(-1, -1); // creating new dummy nodes 

  int sz;
  unordered_map<int, node*> mp;

  LRUCache(int capacity) {
    sz = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) 
  {
    node* temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node* delnode) 
  {
    node* delprev = delnode -> prev;
    node* delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key) 
  {
    if (mp.find(key) != mp.end()) 
    {
      node* resnode = mp[key];
      int res = resnode->val;
      mp.erase(key);
      deletenode(resnode);
      addnode(resnode);
      mp[key] = head->next;
      return res;
    }
    return -1;
  }

  void put(int key, int value) 
  {
    if (mp.find(key) != mp.end()) 
    {
      node * existingnode = mp[key];
      mp.erase(key);
      deletenode(existingnode);
    }
    if (mp.size() == sz) 
    {
      mp.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key, value));
    mp[key] = head -> next;
  }
};