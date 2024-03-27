//termômetro digital com DHT-11
//O objeto desde o projeto é enviar os dados de um sensor de temperatura e umidade.

#include <dht.h>


//pino analógico ao qual vai ser ligado ao pino 2 do DHT11:
const int DHT11 = A0; //referenciando a entrada analógico, sensor tem uma leitura analógica.
const int ATRASO = 5000;
int temperatura = 0;
int umidade = 0;

dht sensor;  //atribuindo essa variável a sensor.

void setup() {
  Serial.begin(9600);

}

void loop() {
  sensor.read11(DHT11); //Obtém os dados analógicos do sensor.
  temperatura = sensor.temperature; //Obtém a temperatura
  umidade = sensor.humidity;  //Obtém a umidade

  Serial.print("Temperatura(C): ");
  Serial.println(temperatura);
  Serial.print("Umidade(%): ");
  Serial.println(umidade);

  delay(ATRASO);
}
