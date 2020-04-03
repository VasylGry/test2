#include <string>
#include <iostream>

#define int8_t byte

using namespace std;
int main() 
{ 
    struct Button
    {
      int8_t w;
      int8_t h;
      int8_t x,y;
      int16_t color;
      int8_t state;
      string& name;
      Button(int8_t aX, int8_t aY, string aName) : x(aX), y(aY), name(aName)
      {
        w = 80;
        h = 40;
        state = 0;
        color = 0x00FF;
      }
      void print()
      {
          printf("x=%d y=%d, name=%s\n",x,y,name.c_str());
          printf("\x1B[31mTexting\033[0m\t\t"); 
      }
    };
    
    Button but = Button(10,20,"nBut");
    but.print();
    
} 

