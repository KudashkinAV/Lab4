#include <iostream>
#include <cstring>
using namespace std;
char nibble_to_hex(uint8_t i){
    char symbols[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    return symbols[i];
}
void print_byte(uint8_t byte){
    uint8_t low = byte & 0b00001111;
    uint8_t hight = (byte & 0b11110000)>>4;
    cout<<nibble_to_hex(hight)<<nibble_to_hex(low);
}
void print_in_hex(const void* data, size_t size){
    const uint8_t* p = reinterpret_cast<const uint8_t*>(data);
    for(int i=0;i<size;i++){
        print_byte(p[i]);
        cout<<" ";
        }
    cout<<endl;
}
struct Student {
    char name[17];
    uint16_t year;
    float mark;
    int gender: 1;
    size_t courses;
    Student* str;
};
int
main() {
    Student S[3];
    strcpy(S[0].name,"Ivan");
    S[0].year=2016;
    S[0].mark=3.6;
    S[0].gender = 1;
    S[0].courses = 1;
    S[0].str = &S[2];

    strcpy(S[1].name,"Satan");
    S[1].year=666;
    S[1].mark=4.666;
    S[1].gender = 0;
    S[1].courses = 1334 ;
    S[1].str = &S[2];

    strcpy(S[2].name,"Guk");
    S[2].year=1969;
    S[2].mark=3.45;
    S[2].gender = 1;
    S[2].courses = 47;
    S[2].str = nullptr;

    for(int i=0;i<3;i++){
        cout<<S[i].name<<endl;
        print_in_hex(&S[i],sizeof(S[i]));
        cout<<endl;
    }


    return 0;
}