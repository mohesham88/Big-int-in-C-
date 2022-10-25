#include "big_int.cpp"

#include<iostream>
using namespace std;











int main(){

    BigDecimalInt a("-985659562151655451213215654");
    BigDecimalInt b("-785654231132115488797979865");

    cin >> a;
    cin >> b;
    cout << "the sum : " << a + b << '\n';
    cout << "a - b : " << a - b;           // -

    cout << '\n';

    /*
    test case
    -5984942524952549569467946796496749679649746
    -
    -15149514951959159459154915495194591594
    =
    -5984927375437597610308487641581254485058152

    
    */

    return 0;
}




