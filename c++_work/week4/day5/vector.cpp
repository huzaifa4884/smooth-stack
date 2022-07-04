#include<iostream>

template <typename T>
class Vector
{
    private:
        T* data;
        int mSize;
        int mCapacity;
        T mUndefined;
    public:
        Vector() 
        {
            data = new T[1];
            mSize = 0;
            mCapacity = 1;
        };

        void pushBack(T val)
        {
            if (mSize == mCapacity)
            {
                T *temp = new T[mCapacity + 3];

                for (int i = 0; i < mSize+1; i++)
                {
                    temp[i] = data[i];
                }
                delete[] data;
                mCapacity += 3;
                data = temp;
            }
            data[mSize] = val;
            mSize += 1;
        }

        void popBack()
        {
            if (mSize == 0)
            {
                throw("Empty vector cannot pop");
            }
            data[mSize-1] = mUndefined;
            mSize--;
        }

        void clear()
        {
            delete[] data;
            mSize = 0;
            mCapacity =0;
        }

        //copy constructor
        Vector(const Vector<T> &obj)
        {
            mSize = obj.getSize();
            mCapacity = mSize;
            data = new T[mSize];

            for (int i=0; i<mSize; i++)
            {
                data[i] = obj.data[i];
            }
        }
        //copy constructor for Rvlue reference
        Vector(Vector<T> &&obj)
        {
            mSize = obj.getSize();
            mCapacity = mSize;
            data = new T[mSize];

            for (int i =0; i < mSize; i++)
            {
                data[i] = obj.data[i];
            }
        }
//*****************************************************************************operators*********************************************************************
        
        Vector& operator = (Vector<T> &obj)
        {
            mSize = obj.getSize();
            mCapacity = obj.getCapacity();
            delete[] data;
            data = new T[mSize];
            for (int i=0; i<mSize; i++)
            {
                data[i] = obj.data[i];
            }
            return *this;

        }
        //overloading for ==
        
        bool operator ==(Vector<T> &obj)
        {
            if (this->mSize != obj.mSize)
                return false;
            for (int i = 0; i < mSize; i++)
            {
                if (data[i] != obj.data[i])
                {
                    return false;
                }
            }
            return true;
        }
        //overloading for []

        T& operator [](int offset) const
        {
            if (offset > mSize)
            {
                throw("vector index out of rang");
            }
            return data[offset];
        }


        int getSize() const
        {
            return mSize;
        }

        int getCapacity() const
        {
            return mCapacity;
        }

        void insert(T val , int index)
        {
            if (index > mSize)
            {
                throw("index of out of range");
            }
            if (index == mSize)
            {
                pushBack(val);
                return;
            }
            if (mSize == mCapacity)
            {
                T *temp = new T[mCapacity +3];

                for (int i=0;i < index; i++)
                {
                    temp[i] = data[i];
                }
                
                temp[index] = val;
                
                for (int i = index; i<mSize; i++)
                {
                    temp[i+1] = data[i];
                }
                delete[] data;
                mCapacity += 3;
                mSize += 1;
                data = temp;
                return;
            }

            T temp = data[index];
            data[index] = val;
            for (int i =index+1; i<mSize+1; i++)
            {
                std::swap(temp , data[i]);
            }
            mSize += 1;
        }


        void print()
        {
            for (int i=0; i<mSize; i++)
            {
                std::cout << data[i] << " , ";
            }
            std::cout << std::endl;
        }

        ~Vector()
        {
            delete[] data;
            mSize =0;
            mCapacity=0;
            mUndefined=0;
        }

        class Iterator
        {
            private:
                friend Vector<T>;
                Vector<T> vc;
                int current;
            public:
                Iterator(Vector<T> v , int offset)
                {
                    vc = v;
                    current = offset;
                }
                void operator++(T)
                {
                    current++;
                }
                void operator--(T)
                {
                    current--;
                }
                bool operator==(const Iterator &obj)
                {
                    if (vc[current] == obj.vc[current])
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                    
                }

                bool operator !=(const Iterator &obj)
                {
                    if (current != obj.getSize() )
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }

                }
                
                T operator *()
                {
                    return vc[current];
                }

                int getSize() const
                {
                    return vc.getSize();
                }

        };

        Iterator Begin() const
        {
            Iterator it(*this , 0);
            return it;
        }
        Iterator End() const
        {
            return Iterator(*this , mSize);
        }


};

int main()
{
    Vector <int>v;
    v.pushBack(2);
    v.pushBack(3);
    v.pushBack(4);
    v.pushBack(5);
    v.insert(8 , 1);
    v.print();
    Vector <int>v2;
    v2 = v;
    v2.print();
    if (v == v2)
       std::cout << "equal vectors"<<std::endl;
    std::cout << v2[2] << std::endl;
    v2.popBack();
    v2.print();
    //Vector<int>::Iterator it = v.Begin();
    //std::cout << *it << std::endl;

    std::cout << "Printin using iterator" << std::endl;
    for (Vector<int>::Iterator it = v.Begin(); it != v.End(); it++)
    {
        std::cout << *it << " , ";
    } 
    std::cout << std::endl;
    return 0;
}
