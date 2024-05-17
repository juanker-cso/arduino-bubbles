const int button_pin = 2;
const int blower_pin = 10;
const int disc_pin = 9;
int init_state; // inicial del botón
int cur_state; // contínua del botón
int last_state; // anterior del botón
// estado inicial de dispositivos
int blower_switch = LOW;
int disc_switch = LOW;
int light_switch = HIGH;

void setup(){
  pinMode(blower_pin,OUTPUT);
  pinMode(disc_pin,OUTPUT);
  pinMode(button_pin,INPUT_PULLUP);
  init_state = digitalRead(button_pin);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,light_switch);
}

void loop(){
  // lectura del boton
  last_state = cur_state;
  cur_state = digitalRead(button_pin);
  if(last_state == HIGH && cur_state == LOW) // botón es presionado y soltado
  {
    // invertir estados
    blower_switch = !blower_switch;
    disc_switch = !disc_switch;
    light_switch = !light_switch;
    digitalWrite(blower_pin,blower_switch); // encender ventilador
    digitalWrite(LED_BUILTIN,light_switch); // apagar luz
  }
  if (disc_switch == HIGH)  // encender y apagar disco
  {
    analogWrite(disc_pin,150);
  }
  else
  {
    digitalWrite(disc_pin,LOW);
    digitalWrite(blower_pin,LOW);
  }
  if (cur_state == LOW)
  {
    digitalWrite(disc_pin,HIGH); // arranque inical de disco
    delay(50);
  }
}
