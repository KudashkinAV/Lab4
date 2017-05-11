#include <iostream>
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
    }

}
int
main() {
    int n;
    cin>>n;
    print_in_hex(&n, sizeof(n));
    return 0;
}