template <typename T>
class LinkedList
{
    struct node
    {
        node* next = nullptr;
        T data;
        int Identity;
        node(T _data, int Id)
        {
            data = _data;
            Identity = Id;
        };
    };
    node* head = nullptr;
    public:
        LinkedList(){};
        void addHead(int Id, T _data)
        {
            node* temp = new node(_data, Id);
            if (head != nullptr)
            {
                temp->next = head;
            };
            head = temp;
            
        };
        T* find(int Id)
        {
            node* cur = head;
            while(cur != nullptr)
                if(cur->Identity == Id)
                    return &cur->data;
                else
                    cur = cur->next;
            return nullptr;
        };
        void Delete(int Id)
        {
            node* cur = head;
            if (cur->Identity = Id)
            {
                head = cur->next;
                delete cur;
            }
            while(cur->next != nullptr)
                if(cur->next->Identity == Id)
                {
                    node* past = cur;
                    cur = cur->next;
                    past->next = cur->next;
                    delete cur;
                }
                else
                    cur = cur->next;  
        }
};