#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

class OSObject{
    private:
        char name[256];
        double diskSpace;
    public:

    const char * getName() const{
        return this->name;
    }

    void setName(const char * name){
        strcpy(this->name, name);
    }

    virtual void setDiskSpace(double diskSpace) = 0;

    virtual double getDiskSpace() const = 0;

    OSObject(char * objName){
        assert(strlen(objName) < 256);
        strcpy(this->name, objName);
    };

    OSObject(){
        this->name[0] = '\0';
    }

    virtual ~OSObject(){};

};

/*
class File: OSObject{
    File(){};
};
*/


int main()
{
    char name[256] = "Maria";
    OSObject o = OSObject(name);
    cout<<o.getName()<<endl;
    o.setDiskSpace(234.52);
    cout<<o.getDiskSpace()<<endl;
    o.setName("Sasha");
    cout<<o.getName()<<endl;
    return 0;
}
