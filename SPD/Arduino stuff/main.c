#include <Keypad.h>
#define filas 4
#define columnas 4

char keys[filas][columnas]= {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
byte fil[]= {9,8,7,6};
byte col[]= {5,4,3,2};
Keypad teclado = Keypad(makeKeymap(keys),fil,col,filas,columnas);
char tecla;
char password[7] = {"123456"};
byte indice = 0;
int ledRojo = 11;
int ledVerde = 10;


void titilar(int pin, int cant);

void setup()
{
    Serial.begin(9600);
    pinMode(ledRojo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
}

void loop()
{
    char tecla;
    char password[] = {"123456"};
    char clave[7];
    byte indice = 0;
    int ledRojo = 11;
    int ledVerde = 10;

    tecla = teclado.getKey();
    if(tecla != NO_KEY)
    {
        clave[indice] = tecla;
        indice++;

        Serial.print(tecla);
    }
    if(indice == 6)
    {
        if(strcmp(clave,password)==0)
        {
            Serial.print("\n Correcto!");
            titilar(ledVerde,3);
        }
        else
        {
            Serial.print("\nIncorrecto");
            titilar(ledRojo,1);
        }
        indice=0;
        delay(100);

    }
}

void titilar(int pin, int cant)
{
    for(int i=0; i<cant; i++)
    {
        digitalWrite(pin,HIGH);
        delay(500);
        digitalWrite(pin,LOW);
        delay(500);
    }
}
