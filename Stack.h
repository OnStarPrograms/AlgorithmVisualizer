template <typename T>
class Stack
{
    private:
        T* _Stack;
        int size = 0;
        int capacity = 10;
    public:
        Stack()
        {
            _Stack = new T[capacity];
        };
        void push(T data)
        {
            size++;
            if (size >= capacity)
            {
                T* Temp = new T[capacity*2];
                for (int i = 0; i < size; i++)
                {
                    Temp[i] = _Stack[i];
                }
                delete[] _Stack;
                capacity*=2;
                _Stack = Temp;
            }
            _Stack[size-1] = data;
        }
        T pop()
        {
            if (size > 0)
            {
                return _Stack[--size];
            }
            return _Stack[0];
        };
        int getSize()
        {
            return size;
        }
};