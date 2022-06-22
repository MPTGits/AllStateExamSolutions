#include <iostream>

using namespace std;


template <typename T=double, typename S=double>
class Function {
    public:
        virtual S calculate(S x) = 0;
        virtual ~Function(){};

};

template <typename T=int, typename S=double>
class LinearFunction: public Function<S,S> {
    private:
        T a;
        T b;

    public:

        LinearFunction(T x, T y): a(x), b(y) {};
        virtual S calculate(S x){
            return a*x + b;
        }

};

template <typename T=int>
class CharacteristicFunction: public Function<T, T>{
    private:
        T * set;
        int size;
        void copyData(const CharacteristicFunction & o){
            size = o.size;
            set = new T[size];
            for(int i = 0;i<size;++i)
                set[i]=o.set[i];
        };
        void deleteData(){
            delete[] set;
        };
    public:


        CharacteristicFunction(T * arr, int oSize){
            size = oSize;
            set = new T[size];
            for(int i = 0;i<size;++i)
                set[i]=arr[i];
        }

        CharacteristicFunction(const CharacteristicFunction & o){
            copyData(o);
        }

        CharacteristicFunction& operator=(const CharacteristicFunction & o){
            if(this != &o){
                deleteData();
                copyData(o);

            }
            return *this;
        }

        ~CharacteristicFunction() {
            deleteData();
        }

        T calculate(T x){
            for(int i = 0; i<size; ++i)
                if(set[i] == x) return 1;
            return 0;
        }
};

template <typename T=int>
class Superposition{
    private:
        Function<T, T> * f;
        Function<T, T> * g;

    public:
        Superposition(Function<T,T> * f1, Function<T,T> * g1){
            f = f1;
            g = g1;
        }

        T calculate(T x){
            return g->calculate(f->calculate(x));
        }



};


int main()
{
    Function<int, int> * f = new LinearFunction<int, int>(1, 2);
    cout<<f->calculate(5)<<endl;
    int arr[] = {1,2,3,4};
    Function<int, int> * f2 = new CharacteristicFunction<int>(arr, 4);
    cout<<f2->calculate(5)<<endl;
    cout<<f2->calculate(2)<<endl;
    Function<int, int> * f3 = new LinearFunction<int, int>(4, 2);
    Superposition<int> sp(f, f3);
    cout<<sp.calculate(2)<<endl;

    delete f2;
    delete f;
    return 0;
}
