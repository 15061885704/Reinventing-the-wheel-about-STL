//#include<iostream>
//#include<algorithm>
//using namespace std;
//template <typename T>
//class myVector
//{
//private:
//    #define WALK_LENGTH 64 //vector 每次增加的步长
//private:
//    T* myArray;
//    unsigned int theSize;
//    unsigned int theCapacity;
//
//public:
//    myVector():myArray(0),theSize(0),theCapacity(0){}
//    myVector(const T& t,unsigned int n):myArray(0),theSize(0),theCapacity(0)
//    {
//        while(n--)
//        {
//            mypush_back(t);
//        }
//    }
//    myVector(const myVector<T> &other):myArray(0),theSize(0),theCapacity(0)
//    {
//
//        *this = other;
//    }
//    myVector<T> & operator = (myVector<T>& other)
//    {
//
//        if(this == &other)
//            return *this;
//        myclear();
//        theSize = other.theSize;
//        theCapacity = other.theCapacity;
//        myArray = new T[theCapacity];
//        for(int i = 0 ; i < theSize; i++)
//        {
//
//            myArray[i] = other[i];
//        }
//        return *this;
//    }
//    ~myVector()
//    {
//        myclear();
//    }
//    T& operator[](unsigned int pos)
//    {
//       // if(pos>=theSize)
//           // return 0;
//       // else
//            return myArray[pos];
//    }
//    unsigned int mysize()
//    {
//        return theSize;
//    }
//    unsigned int mycapacity()
//    {
//
//        return theCapacity;
//    }
//    bool myempty()
//    {
//
//        return theSize==0;
//    }
//    bool myfull()
//    {
//        return theSize== theCapacity;
//    }
//  //  bool my
//    void myclear()
//    {
//        deallocator(myArray);
//        myArray = 0;
//        theCapacity = 0;
//        theSize = 0;
//
//        //delete myArray;// 难道不行吗
//    }
//    void mypush_back(const  T &t)
//    {
//
//        myinsert_after(theSize-1,t);
//
//
//    }
//    void mypush_front(const T& t)
//    {
//
//        myinsert_before(0,t);
//    }
//    void myinsert_after(int pos, const T & t)
//    {
//
//        myinsert_before(pos+1,t);
//    }
//    void myinsert_before(int pos, const T& t)
//    {
//        if(theSize == theCapacity)
//        {
//            T* oldArray = myArray;
//            theCapacity = theCapacity + WALK_LENGTH;
//            myArray = myallocator(theCapacity);
//            for(int i = 0; i < theSize; i ++)
//                myArray[i] = oldArray[i];
//            deallocator(oldArray);
//        }
//        theSize++;
//        for(int i = theSize; i >pos; i--)
//            myArray[i] = myArray[i-1];
//        myArray[pos] = t;
//
//    }
//    void myerase(unsigned int pos)
//    {
//        if(pos<theSize)
//        {
//            theSize--;
//            for( int i = pos; i < theSize; i++)
//            {
//                myArray[i] = myArray[i+1];
//            }
//        }
//
//    }
//    void printfVector(myVector<T>& vector1)
//    {
//
//        for(unsigned int i = 0; i < vector1.mysize(); i++)
//        {
//
//            cout << vector1[i]<<"," ;
//        }
//        cout<< "allocd size =" << vector1.theCapacity << ",size = " <<vector1.mysize()<< endl;
//    }
//
//private:
//    T* myallocator(unsigned int num)
//    {
//        return new T[num];
//    }
//    void deallocator(T *arr)
//    {
//
//        if(arr)
//            delete [] arr;
//    }
//};
//int main()
//{
//    myVector<int> myVector1;
//    myVector<int> myVector2(0,100);
//    myVector2.mypush_front(1);
//    myVector2.mypush_back(2);
//    myVector2.printfVector(myVector2);
//    myVector2.myerase(11);
//    cout << "after erase : "; myVector2.printfVector(myVector2); cout << endl;
//
//
//
//    return 0;
//}
//
#include<iostream>
#include<algorithm>
using namespace std;
int x[105],y[105],z[105];
int total[105];
int totalWeigh[105][1005]={0};
int main()
{
    int totalNum;
    int totalBlood;
    cin >> totalNum; cin>> totalBlood;
    for(int i= 1; i <= totalNum;i++)
        cin>>x[i];
    for(int i= 1; i <= totalNum;i++)
        cin>>y[i];
    for(int i= 1; i <= totalNum;i++)
        cin>>z[i];


    for(int i= 1; i <= totalNum;i++) totalWeigh[i][0]=0;
    for(int j= 0; i <= totalNum;i++) totalWeigh[0][j]=0;
    for(int i = 1; i < totalNum; i++)
        for(int j = 1; j < totalBlood; j++)
    {
        int weigh1=0,weigh2=0;
        if(j > x[i-1])
            weigh1 = totalWeigh[i-1][j-x[i-1]] + y[i-1];
        if(j > z[i-1])
            weigh2 = totalWeigh[i-1][j-z[i-1]];
        totalWeigh[i][j] = max(weigh1,weigh2);
    }
    cout << totalWeigh[totalNum][totalBlood];

}
