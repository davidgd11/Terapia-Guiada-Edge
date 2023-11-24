#include <Arduino.h>


const int pinPotenciometro = 34;  

int calcularSaturacaoOxigenio(int valorPotenciometro) {
    return map(valorPotenciometro, 0, 4095, 70, 100);
}

void setup() {
    Serial.begin(115200);  
}

void loop() {
    
    int valorPotenciometro = analogRead(pinPotenciometro);

    
    int saturacaoOxigenio = calcularSaturacaoOxigenio(valorPotenciometro);

    
    Serial.print("\n Valor do Potenciômetro: ");
    Serial.println(valorPotenciometro);
    Serial.print("Saturação de Oxigênio: ");
    Serial.print(saturacaoOxigenio);
    Serial.println("%");

    if (saturacaoOxigenio <= 92) {
      Serial.print("Você não pode fumar!\n");      
    }

    if (saturacaoOxigenio > 92){
      Serial.print("Tudo certo!\n");
    }

    delay(1000);  
}