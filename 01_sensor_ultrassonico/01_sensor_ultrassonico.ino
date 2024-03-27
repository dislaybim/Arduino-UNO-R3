
int ECHO = 7; //pino 7 recebe o pulso
int TRIG = 8; //pino 8 envia o pulso
int BUZZER = 6;
int LED_1 = 2;
int LED_2 = 3;
int LED_3 = 4;


long duracao = 0;
long distancia = 0;

void setup() {
  Serial.begin(9600); //inicializa a comunicação serial
  pinMode(ECHO, INPUT); //pino 7 é entrada(receber)
  pinMode(TRIG, OUTPUT); //pino 8 é a saída(enviar)
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);  //pino trigger com um pulso baixo LOW(desligado)
  delayMicroseconds(10);    //delay de 10 microssegundos

  digitalWrite(TRIG, HIGH);  //pino do trigger com pulso high(ligado)
  delayMicroseconds(10);     //delay de 10 microssegundos

  digitalWrite(TRIG, LOW);  //pino trigger com um pulso baixo LOW(desligado)
  delayMicroseconds(10);    //delay de 10 microssegundos


 //A função pulseInt verifica o tempo que o pino ECHO ficou em nivel lógico alto
 //calculando assim a duração do tráfego do sinal
 duracao = pulseIn(ECHO, HIGH);

 //Cálculo da distância(centímetros): distância = duração/58.
 distancia = duracao/58;

 if(distancia > 20 && distancia <= 30){
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
 }
 else if((distancia<=20) && (distancia>10)){
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);
 }
 else if(distancia <= 10 && distancia > 0){
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, HIGH);
 }
 else if(distancia > 30){
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
 }
 

 if(distancia <= 5 && distancia >= 1){
  digitalWrite(BUZZER, HIGH);
 }else{
  digitalWrite(BUZZER, LOW);
 }

 Serial.print("Distancia em cm: ");
 Serial.println(distancia);
 

}
