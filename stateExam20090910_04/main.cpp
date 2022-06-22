#include <iostream>

using namespace std;

class Sequence{
    protected:
        int * sequence;
        int size;
        void copyData(const Sequence & o){
            size = o.size;
            sequence = new int[o.size];
            for(int i = 0; i<size; ++i)
                sequence[i]=o.sequence[i];
        }
        void deleteData(){
            delete[] sequence;
        }

    public:

        Sequence() {
            sequence = nullptr;
            size = 0;
        };

        Sequence(const Sequence & o){
            copyData(o);
        }

        Sequence& operator=(const Sequence & o){
            if(this != &o){
                deleteData();
                copyData(o);
            }
            return *this;
        }

        virtual ~Sequence(){
            deleteData();
        }

        virtual int getMember(int idx) = 0;

};

class ArithmeticSequence: public Sequence{
    private:
        int d;

    public:
        ArithmeticSequence(int mainA,int mainD){
            d = mainD;
            sequence = new int[1];
            sequence[0] = mainA;
            size = 1;
        }

        ArithmeticSequence(const ArithmeticSequence & o):Sequence(o) {
            d = o.d;
        }

        ArithmeticSequence& operator=(const ArithmeticSequence & o){
            if(this != &o){
                Sequence::operator=(o);
                d = o.d;
            }
            return *this;
        }

        int getMember(int idx){
            if(size<idx-1){
                int * tmp = sequence;
                sequence = new int[idx-1];
                for(int i = 0; i<size; ++i){
                    sequence[i] = tmp[i];
                }
                delete[] tmp;
                for(int i=size; i<idx; ++i){
                    sequence[i] = sequence[i-1] + d;
                }
                size = idx;
            }
            return sequence[idx-1];
        }

};



int main()
{
    ArithmeticSequence as(1,4);
    Sequence * s = &as;
    cout<<s->getMember(5);
    return 0;
}
