#include "big_int.h"



using namespace std;


// non member funciton
void remove_sign(string &s){
    if(s[0] == '+' || s[0] == '-' ){
        s.erase(0,1);
    }
}
// function sums to string to use in overloading + and -
string sum(string a, string b){
    string ans = "";
    remove_sign(a); 
    remove_sign(b); 
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    // add 0's to the string with min length
    if(a.size() > b.size()){
        for(int i = b.size();i < a.size();i++){
            b.push_back('0');
        }
    }
    else if (a.size() < b.size()){
        for(int i = a.size();i < b.size();i++){
            a.push_back('0');
        }
    } 
    int carry = 0,i = 0;
    for(i; i < a.size(); i++){
        int digit_sum = ((a[i] - '0')+ (b[i] - '0') + carry); 
        ans.push_back( digit_sum % 10 + '0');
        carry = digit_sum / 10;
    }
    if(carry)
        ans.push_back(carry+ '0');    
    reverse(ans.begin(),ans.end());
    return ans;
}
string difference(string a, string b){
    string ans = "";
    remove_sign(a); 
    remove_sign(b); 
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    // add 0's to the string with min length
    if(a.size() > b.size()){
        for(int i = b.size();i < a.size();i++){
            b.push_back('0');
        }
    }
    else if (a.size() < b.size()){
        for(int i = a.size();i < b.size();i++){
            a.push_back('0');
        }
    } 
    int carry = 0,i = 0;
    for(i; i < a.size(); i++){
        int digit_diff = (a[i] - '0') -  (b[i] - '0') - carry; 

        if(digit_diff < 0){
            digit_diff += 10;
            carry = 1;
        }
        else 
            carry = 0;

        ans.push_back(digit_diff + '0');
    }    
    reverse(ans.begin(),ans.end());
    // remove leading zeros
    if(ans.size() >1){
        int indx = 0;
        while(true){
            if(ans[indx] - '0' >= 1){
                break;
            }
            else{
                if(ans.size() - 1 >= 1)
                    ans.erase(0,1);
                else
                    break;
            }
        }
    }
    return ans;
}


int BigDecimalInt::size(){
    return big_decimal.size();
}
char BigDecimalInt::sign(){
    char sign = big_decimal[0];
    if(sign == '-')
        return '-';
    return '+';
}

// constructors 




BigDecimalInt::BigDecimalInt(){
    big_decimal = '0';
}
BigDecimalInt::BigDecimalInt(string dec_str){
    // validation 

    regex valid("[- +]?[1-9][0-9]*");
    
    if(regex_match(dec_str,valid))
        big_decimal = dec_str;
    else{
        cout << "the input is not valid\n";
        big_decimal = "0";        // will not change if input isn't correct 
    }
}
BigDecimalInt::BigDecimalInt(int dec_str){
    big_decimal =  to_string(dec_str);
}


/* BigDecimalInt& BigDecimalInt::operator=(BigDecimalInt another_dec){

    big_decimal = another_dec.big_decimal;
    return *this;

} */


bool BigDecimalInt::operator>(BigDecimalInt another_dec){
    string bd = big_decimal;
    string anoter_bd = another_dec.big_decimal;
    remove_sign(bd);
    remove_sign(anoter_bd);
    if(another_dec.sign() == '-' && sign() == '+'){
        return true;
    }
    else if (another_dec.sign() == '+' && sign() == '-'){
        return false;
    }
    else if(another_dec.sign() == '+' && sign() == '+'){
        if(bd.size() > anoter_bd.size()){
            return true;
        }
        else if(bd.size() < anoter_bd.size()){
            return false;
        }

        else{
            for(int i = 0; i < bd.size();i++){
                if(bd[i] > anoter_bd[i]){
                    return true;
                }
                else if (bd[i] < anoter_bd[i]){
                    return false;
                }
            }        
        }
        return false;
    }
    // -  - 
    else{
         if(bd.size() < anoter_bd.size()){
            return true;
        }
        else if(bd.size() > anoter_bd.size()){
            return false;
        }
        // size == size
        else{
            for(int i = 0; i < big_decimal.size();i++){
                if(bd[i] < anoter_bd[i]){
                    return true;
                }
                else if (bd[i] > anoter_bd[i]){
                    return false;
                }
            }        
        }
        return false;

    }
}

bool BigDecimalInt::operator<(BigDecimalInt another_dec){
    string bd = big_decimal;
    string anoter_bd = another_dec.big_decimal;
    remove_sign(bd);
    remove_sign(anoter_bd);
    if(another_dec.sign() == '-' && sign() == '+'){
        return false;
    }
    else if (another_dec.sign() == '+' && sign() == '-'){
        return true;
    }
    else if(another_dec.sign() == '+' && sign() == '+'){
        if(bd.size() > anoter_bd.size()){
            return false;
        }
        else if(bd.size() < anoter_bd.size()){
            return true;
        }

        else{
            for(int i = 0; i < bd.size();i++){
                if(bd[i] > anoter_bd[i]){
                    return false;
                }
                else if (bd[i] < anoter_bd[i]){
                    return true;
                }
            }        
        }
        
    }
    // -  - 
    else{
         if(bd.size() < anoter_bd.size()){
            return false;
        }
        else if(bd.size() > anoter_bd.size()){
            return true;
        }
        // size == size
        else{
            for(int i = 0; i < big_decimal.size();i++){
                if(bd[i] < anoter_bd[i]){
                    return false;
                }
                else if (bd[i] > anoter_bd[i]){
                    return true;
                }
            }        
        }
    }
    // a == b
    return false;
}


bool BigDecimalInt::operator==(BigDecimalInt another_dec){
    string bd = big_decimal;
    string another_bd = another_dec.big_decimal;
    remove_sign(bd);
    remove_sign(another_bd);
    if(bd == another_bd && sign() == another_dec.sign()){
        return true;
    }

    return false;
}

BigDecimalInt BigDecimalInt::operator=(const BigDecimalInt& another_dec){
    big_decimal = another_dec.big_decimal;
    return *this;
}

ostream& operator<<(ostream &out,BigDecimalInt another_dec){
    if(another_dec.sign() == '+'){
        remove_sign(another_dec.big_decimal);
    }
    out << another_dec.big_decimal;
    return out;
}
istream& operator>>(istream &in,BigDecimalInt &another_dec){
    in >> another_dec.big_decimal;
    regex valid("[- +]?[1-9][0-9]*");
    if(!regex_match(another_dec.big_decimal,valid)){
        another_dec.big_decimal = "0";
        cout << "the input is not valid\n";
    }
    return in;
}





BigDecimalInt BigDecimalInt::operator+(BigDecimalInt another_dec){
    BigDecimalInt ans;
    ans.big_decimal = "";
    BigDecimalInt bd (big_decimal);
    BigDecimalInt another_bd (another_dec.big_decimal);
    remove_sign(bd.big_decimal);
    remove_sign(another_bd.big_decimal);
    // + +     or  - -    : sum them and put the sign
    if(sign() == another_dec.sign()){
        if(sign() == '-')
            ans.big_decimal.push_back('-');
            ans.big_decimal += sum(bd.big_decimal,another_bd.big_decimal);
    }

    // different signs   -700 + 500     or 59 + -5          difference
    else{    
        // -700 + 500 = -200   700 > 500      or  -500 + 700 = 200
        if( bd > another_bd){
            bd = difference(bd.big_decimal,another_bd.big_decimal);
            if(sign() == '-'){
                ans.big_decimal.push_back('-');
            }
            ans.big_decimal += bd.big_decimal;
        }
        else if( bd < another_bd){
            bd = difference(another_bd.big_decimal,bd.big_decimal);
            if(another_dec.sign() == '-'){
                ans.big_decimal.push_back('-');
            }
            ans.big_decimal += bd.big_decimal;
        }
        // -500 + 500 = 0
        else{
            ans.big_decimal = "0";
        }
    }
    return ans;
}


BigDecimalInt BigDecimalInt::operator-(BigDecimalInt another_dec){
    BigDecimalInt ans;
    ans.big_decimal = "";
    BigDecimalInt bd = big_decimal;
    BigDecimalInt another_bd = another_dec.big_decimal;
    remove_sign(bd.big_decimal);
    remove_sign(another_bd.big_decimal);
    
    // different signs   -700 - +500  sum with the sign -1200  or 59 - -5   == 64 
    if(sign() != another_dec.sign()){
        if(sign() == '-')
            ans.big_decimal.push_back('-');
            ans.big_decimal += sum(bd.big_decimal,another_bd.big_decimal);
    }

    // same signs -> diff with the sign of the bigger     300  - 200   = 100 or -200 - -400  =200 
    else{
        // 9 - 9 = 0 or  -9 - (-9) = 0    
        if( bd == another_bd){
            ans.big_decimal = '0';
        }

        // + and +  ex. 9 - 2 = 7 or 2 - 9 = -7
        if(sign() == '+'){
            // 9 - 2 = +7
            if( bd > another_bd){
                ans.big_decimal = difference(bd.big_decimal,another_bd.big_decimal);
            }
            // 2 - 9 = -7
            else if(bd < another_bd){
                ans.big_decimal.push_back('-');
                ans.big_decimal += difference(another_bd.big_decimal,bd.big_decimal);
            }


        }
        //  - and -  (-2) - (-9) = 7  or -9 - (-2) = -7
        else if(sign() == '-'){
                // -2 - (-9)  = 7       wihtout signs   9 > 2         
                if( bd < another_bd){
                    ans.big_decimal = difference(another_bd.big_decimal,bd.big_decimal);
                }
                // -9 - (-2) = -7
                else if( bd > another_bd){
                    ans.big_decimal.push_back('-');
                    ans.big_decimal += difference(bd.big_decimal,another_bd.big_decimal);
                }

        }
    
    }

    return ans;
}
