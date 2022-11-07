uint8_t info2;
uint8_t EstadoAdelate;
uint8_t EstadoAtras;


int Adelante = 11;
int Atras = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(Adelante, INPUT_PULLUP);  // We setup the PushButton's pins
  pinMode(Atras, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  info2 = 0;
  // put your main code here, to run repeatedly:
   EstadoAdelate = digitalRead(Adelante);    // We read the value of PB1 and store it in its indicated position
    EstadoAdelate = (!EstadoAdelate) << 3;
    EstadoAtras = digitalRead(Atras);    // We read the value of PB2 and store it in its indicated position 
    EstadoAtras = (!EstadoAtras) << 4;

    
    info2 |= EstadoAdelate;    //Store all controller information in the P1_Data Variable
    info2 |= EstadoAtras;
    Serial.write(info2);  //Send3 P1_Data to the master
    delay(100);
} 
