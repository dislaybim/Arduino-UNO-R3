//fazer uma calculadora, utilizarei o o display lcd, no caso poderia utilizar o monitor serial do arduino
//primeiramente, criarei o vetor de caracteres a ser percorrido pelo teclado matricial.
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <math.h>
#define l1 3  //define todos os pinos que serão utilizados para controlar o teclado matricial.
#define l2 4
#define l3 5
#define l4 6
#define c1 7
#define c2 8
#define c3 9
#define c4 10

int linha[4] = {l1, l2, l3, l4};  //poderia ser uma alternativa de percorrer um vetor
int coluna[4] = {c1, c2, c3, c4}; //poderia ser tambem uma alternativa
int contador = 0;

char tecla;
char teclado[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};//de caracteres declarados para ser percorrido durante a leitura do teclado matricial.

int aciona=0; //variável para controlar a quantidade de eximibição do número clicado, para somente uma vez no terminal do monitor seria
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //declarar as variáveis de entrada que corresponderá a coluna e as saídas que serão as linhas.
  pinMode(l1, OUTPUT); // saída para a linha 1
  pinMode(l2, OUTPUT); // saída para a linha 2 PULL-DOWN
  pinMode(l3, OUTPUT); // saída para a linha 3
  pinMode(l4, OUTPUT); // saída para a linha 4
  pinMode(c1, INPUT_PULLUP);  //entrada para a coluna 1,definir resistor de pull-up
  pinMode(c2, INPUT_PULLUP);  //entrada para a coluna 2, definir resistor de pull-up
  pinMode(c3, INPUT_PULLUP);  //entrada para a coluna 3, definir resistor de pull-up
  pinMode(c4, INPUT_PULLUP);  //entrada para a coluna 4, definir resistor de pull-up
  
  Serial.begin(9600); //inicializa o monitor serial
  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  //criarei o vetor que percorrerá o teclado matricial
  int i, j; //variável para percorrer a matrix 4x4
 
  //dentro desses laços for ocorrerá o processo de varredura do teclado matricial
  for(i = 0; i < 4; i++){ // percorrerá o número das quatro linhas.
    digitalWrite( linha[i], LOW); // a cada intremento da variável contadora, será deslocado um bit para a porta do arduino.
    for(j=0; j < 4; j++){
       if(digitalRead(coluna[j])==LOW){ //verifica se o botão foi apertado
        tecla = teclado[i][j];  //acrescentao conteúdo das coordenadas do botão a variável tecla
        aciona = 1;
        contador++;
        if ((tecla=='A')||(tecla=='B')||(tecla=='C')||(tecla=='D')||(tecla=='#')){
          contador = 0;
        }
        delay(400);
        
       }
    }
    digitalWrite(linha[i], HIGH);//coloca em nível lógico alto todas as saídas correspondentes as linhas.
  }
 
  lcd.setCursor(7, 1);
  lcd.print(contador);

if(aciona == 1){
  switch(tecla){// aqui vamos realizar a verificação de cada tecla apertada, pois, posteriormente, vamos fazer uma calculadora.

    //no teclado matricial, vamos definir os seguintes casos como
    // A é soma
    // B é subtração
    // C é multiplicação
    // D é divisão
    // # é igual
    case '1': 
    Serial.write("1");
    //lcd.setCursor(7, 1);
    //lcd.print("1");
      break;
    case '2': Serial.write("2");
    //lcd.setCursor(7, 1);
    //lcd.print("2");
      break;
    case '3': Serial.write("3");
    //lcd.setCursor(7, 1);
    //lcd.print("3");
      break;
    case '4': Serial.write("4");
    //lcd.setCursor(7, 1);
    //lcd.print("4");
      break;
    case '5': Serial.write("5");
    //lcd.setCursor(7, 1);
    //lcd.print("5");
      break;
    case '6': Serial.write("6");
    //lcd.setCursor(7, 1);
    //lcd.print("6");
      break;
    case '7': Serial.write("7");
    //lcd.setCursor(7, 1);
    //lcd.print("7");
      break;
    case '8': Serial.write("8");
    //lcd.setCursor(7, 1);
    //lcd.print("8");
      break;   
    case '9': Serial.write("9");
    //lcd.setCursor(7, 1);
    //lcd.print("9");
      break;
    case '*': Serial.write("*");
    //lcd.setCursor(7, 1);
    //lcd.print("*");
      break;
    case '0': Serial.write("0");
    //lcd.setCursor(7, 1);
    //lcd.print("0");
      break;   
    case '#': Serial.write("#");
    //lcd.setCursor(7, 1);
    //lcd.print("#");
      break;
    case 'A': Serial.write("A");
    //lcd.setCursor(7, 1);
    //lcd.print("A");
      break;
    case 'B': Serial.write("B");
    //lcd.setCursor(7, 1);
    //lcd.print("B");
      break;
    case 'C': Serial.write("C");
    //lcd.setCursor(7, 1);
    //lcd.print("C");
      break;
    case 'D': Serial.write("D");
    //lcd.setCursor(7, 1);
    //lcd.print("D");
      break;  
    };
  aciona = 0; //quando acabar esse processo todo retorna para 0.
  }

//tratamento matemático necessário para tornar o arduíno um negócio mais complexo.


  
}


//Bom, metade do trabalho foi solucionado, agora basta criar funções para realizar operações matemáticas.
