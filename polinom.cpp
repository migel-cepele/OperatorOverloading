#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "polinom.h"
using namespace std;

Polinom::Polinom(int polSize): size{(polSize > 0 ? static_cast<size_t>(polSize):
throw invalid_argument{"Polinomi duhet te kete graden me te madhe se 0"})},
ptr{ new int[size] {}} {
     //rezervon nje hapsire ne memorje per array
    

}

Polinom::~Polinom() {
    delete[] ptr; //liron hapsiren e zene nga pointeri kur nuk na duhet me
}

size_t Polinom::getSize() const{
    return size;
}

void Polinom::setPol(int polSize) {
    

    for(size_t i{0}; i < polSize; ++i) {
        cout << "Vendosni koeficientin per fuqine " << i <<endl;
        size_t k;
        cin >> k;
        ptr[i] = k;
    }
}

//overloadin operators implemented

Polinom Polinom::operator+(const Polinom& pol1) {
    Polinom rez;
    size_t min;
    if (this->size > pol1.size) {
        rez.size = this->size;
        min = pol1.size;

        for(size_t i{0}; i < min; ++i) {
            rez.ptr[i] = this->ptr[i] + pol1.ptr[i];
        }
        for(size_t i{min}; i < this->size; ++i) {
            rez.ptr[i] = this->ptr[i];
        }

    } else {
        rez.size = pol1.size;
        min = this->size;

        for(size_t i{0}; i < min; ++i) {
            rez.ptr[i] = this->ptr[i] + pol1.ptr[i];
        }
        for(size_t i{min}; i < pol1.size; ++i) {
            rez.ptr[i] = pol1.ptr[i];
        }
    }
    
    return rez;

}

Polinom Polinom::operator-(const Polinom& pol1) {
    Polinom rez;
    size_t min;
    if (this->size > pol1.size) {
        rez.size = this->size;
        min = pol1.size;

        for(size_t i{0}; i < min; ++i) {
            rez.ptr[i] = this->ptr[i] - pol1.ptr[i];
        }
        for(size_t i{min}; i < this->size; ++i) {
            rez.ptr[i] = this->ptr[i];
        }

    } else {
        rez.size = pol1.size;
        min = this->size;

        for(size_t i{0}; i < min; ++i) {
            rez.ptr[i] = this->ptr[i] - pol1.ptr[i];
        }
        for(size_t i{min}; i < pol1.size; ++i) {
            rez.ptr[i] = -1*pol1.ptr[i];
        }
    }
    
    return rez;

}

const Polinom& Polinom::operator=(const Polinom& p1) {
    if(size != p1.size) {
        delete[] ptr;
        size = p1.size;
        ptr = new int[size];
        for(size_t i{0}; i < p1.size; ++i) {
            ptr[i] = p1.ptr[i];
        }
    } else {
        for(size_t i{0}; i < p1.size; ++i) {
            ptr[i] = p1.ptr[i];
        }
    }
    return *this;
} 

Polinom Polinom::operator*(const Polinom& pol1) {
    Polinom rez(this->size + pol1.size);  
        
    for(size_t i{0}; i < this->size; ++i) {
        Polinom shuma_perkohshme(rez.size);
        
        for(size_t j{0}; j < pol1.size; ++j) {
            
            shuma_perkohshme.ptr[i+j]= this->ptr[i] * pol1.ptr[j];//fuqite mblidhen ndersa koeficientet shumezohen   
        }
        rez = rez + shuma_perkohshme; //problemi qendron tek shumezimi        
                     
    }    
    return rez;
}

Polinom& operator*=(Polinom& p1, const Polinom p2) {
    Polinom rez(p1.size + p2.size);  
        
    for(size_t i{0}; i < p1.size; ++i) {
        Polinom shuma_perkohshme(rez.size);
        
        for(size_t j{0}; j < p2.size; ++j) {
            
            shuma_perkohshme.ptr[i+j]= p1.ptr[i] * p2.ptr[j];//fuqite mblidhen ndersa koeficientet shumezohen   
        }
        rez = rez + shuma_perkohshme; //problemi qendron tek shumezimi        
                     
    }
    p1 = rez;
    return p1;
    
}

Polinom& operator+=(Polinom& p1, Polinom p2) {

    Polinom rez;
    size_t min;
    if (p1.size > p2.size) {
        rez.size = p1.size;
        min = p2.size;

        for(size_t i{0}; i < min; ++i) {
            rez.ptr[i] = p1.ptr[i] + p2.ptr[i];
            
        }
        for(size_t i{min}; i < p1.size; ++i) {
            rez.ptr[i] = p1.ptr[i];
        }

    } else {
        rez.size = p2.size;
        min = p1.size;

        for(size_t i{0}; i < min; ++i) {
            rez.ptr[i] = p1.ptr[i] + p2.ptr[i];
        }
        
        for(size_t i{min}; i < p2.size; ++i) {
            rez.ptr[i] = p2.ptr[i];
        }
        
    }
    
    p1 = rez;
    return p1;

}

Polinom& operator-=(Polinom& p1, Polinom p2) {

    Polinom rez;
    size_t min;
    if (p1.size > p2.size) {
        rez.size = p1.size;
        min = p2.size;

        for(size_t i{0}; i < min; ++i) {
            rez.ptr[i] = p1.ptr[i] - p2.ptr[i];
        }
        for(size_t i{min}; i < p1.size; ++i) {
            rez.ptr[i] = p1.ptr[i];
        }

    } else {
        rez.size = p2.size;
        min = p1.size;

        for(size_t i{0}; i < min; ++i) {
            rez.ptr[i] = p1.ptr[i] - p2.ptr[i];
        }
        for(size_t i{min}; i < p2.size; ++i) {
            rez.ptr[i] = -1*p2.ptr[i];
        }
    }
    
    p1 = rez;
    return p1;

}



ostream& operator<<(ostream& output, const Polinom& p) {
    for(size_t i{0}; i < p.size; ++i) {
        output << p.ptr[i] << " ";
    }
    output << endl;
    return output;

}

int main() {
    Polinom p1{2};
    Polinom p2{3};

    cout << (p1 + p2);

    p1.setPol(2);
    p2.setPol(3);

    cout << p1;
    cout << (p1-=p2);
    cout << p1;

    
    

}