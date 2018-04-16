const byte EA = 5;
const byte IA = 10;
const byte IA2 = 9;

const byte EB = 6;
const byte IB = 8;
const byte IB2 = 7;

const byte decrease_right_motor_speed = 10;
const byte decrease_left_motor_speed = 0;

void loop() {
//  controlMotor ( 255 , 255 ); 
//  delay(1000);
//  controlMotor ( -255 , -255 ); 
//  delay(1000);
}

void setup() {
  pinMode(IA, OUTPUT);
  pinMode(IB, OUTPUT);
  pinMode(IA2, OUTPUT);
  pinMode(IB2, OUTPUT);
}

void controlMotor ( int L_speed, int R_speed) {
    if(Serial.available()) {
        Serial.println("L:"+String(L_speed) +"R:"+ String(R_speed) ); 
    }

    L_speed = L_speed - decrease_left_motor_speed;
    R_speed = R_speed - decrease_right_motor_speed;

    if (L_speed >= 0 ) {
       digitalWrite(IA, HIGH);
       digitalWrite(IA2, LOW);
    }else{
      digitalWrite(IA, LOW);
      digitalWrite(IA2, HIGH);
    }

    if (R_speed >= 0 ) {
       digitalWrite(IB, HIGH);
       digitalWrite(IB2, LOW);
    }else{
      digitalWrite(IB, LOW);
      digitalWrite(IB2, HIGH);
    }

    int L_S = (abs(L_speed) > 255 )?255:abs(L_speed);
    int R_S = (abs(R_speed) > 255 )?255:abs(R_speed);
    analogWrite(EA, L_S);
    analogWrite(EB, R_S);
}