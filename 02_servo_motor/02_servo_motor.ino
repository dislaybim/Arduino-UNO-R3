#include <Servo.h> //incluir a biblioteca do servo-motor
#define SERVO 6   //definir a porta numero 6 como controle do servo
#define AUMENTA 7 //comando para aumentar o angulo estará associado ao pino 7
#define DIMINUI 8 //comando para diminuir o ângulo estará associado ao pino 8

int pos=0;     //posição do servo
Servo s;     //variável servo

void setup() {
  pinMode(AUMENTA, INPUT);
  pinMode(DIMINUI, INPUT);
  s.attach(SERVO);     
  Serial.begin(9600);   //inicializa o monitor serial
  s.write(0);    //inicia o motor na posição 0
}

void loop() {

   int botao_aumenta = digitalRead(AUMENTA);
   int botao_diminui = digitalRead(DIMINUI);

if(botao_aumenta == HIGH){
   for(pos = 0; pos < 180; pos++){  //laço for, para acrescentar cada posição
    s.write(pos);
    delay(30);
    if(pos==180){
      pos = 0;
    }
    Serial.print("Angulo °: ");
    Serial.println(pos);
  }
}else if(botao_diminui == HIGH){
   for(pos = 180; pos >= 0; pos--){
    s.write(pos);
    delay(2);
    Serial.print("Angulo °: ");
    Serial.println(pos);

  }
}
/*
  for(pos = 0; pos < 180; pos++){  //laço for, para acrescentar cada posição
    s.write(pos);
    delay(30);
    Serial.print("Angulo °: ");
    Serial.println(pos);

  }
  delay(1000);   //1 segundo para variar cada grau

  for(pos = 180; pos >= 0; pos--){
    s.write(pos);
    delay(2);
    Serial.print("Angulo °: ");
    Serial.println(pos);

  }
  delay(1000);


  */

}
