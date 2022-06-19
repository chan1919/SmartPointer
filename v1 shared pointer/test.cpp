#include "shared_ptr.h"

using namespace std;
int main () {

    {
        SmartPointer<int> sp = new int(65);
        cout << sp.use_count();
    }
    

    
}