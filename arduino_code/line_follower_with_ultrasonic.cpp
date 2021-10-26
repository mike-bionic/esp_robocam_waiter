// ultrasonic
#define echoPin 8
#define trigPin 9
long duration;
int distance;
int minDistance = 40;
int backwardDistance = 80;

// motor
int S_A = 10;  //speed motor a
int M_A1 = 2; //motor a = +
int M_A2 = 3; //motor a = -
int M_B1 = 4; //motor b = -
int M_B2 = 5; //motor b = +
int S_B = 11;  //speed motor b

int R_S = A0; //sincer R
int S_S = A1; //sincer S
int L_S = A2; //sincer L

int reverseMode = 0;

void setup() {
	// ultrasonic
	pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
	// ultrasonic

	pinMode(M_B1, OUTPUT);
	pinMode(M_B2, OUTPUT);
	pinMode(M_A1, OUTPUT);
	pinMode(M_A2, OUTPUT);
	pinMode(S_B, OUTPUT);
	pinMode(S_A, OUTPUT);

	pinMode(L_S, INPUT);
	pinMode(S_S, INPUT);
	pinMode(R_S, INPUT);

	analogWrite(S_A, 150);
	analogWrite(S_B, 150);
	delay(200);
}

void loop() {
	int left_sensor_state = digitalRead(L_S);
	int right_sensor_state = digitalRead(R_S);
	int mid_sensor_state = digitalRead(S_S);

	runLineSensor();
}

void runLineSensor(){
	if (left_sensor_state == 0) && (mid_sensor_state == 1) && (right_sensor_state == 0)){
		if (reverseMode == 0){
			forward();
		} else {
			backward()
		}
	}
	if (left_sensor_state == 1) && (mid_sensor_state == 1) && (right_sensor_state == 0)){
		if (reverseMode == 0){
			turnLeft();
		} else {
			bcwturnLeft();
		}
	}
	if (left_sensor_state == 1) && (mid_sensor_state == 0) && (right_sensor_state == 0)){
		if (reverseMode == 0){
			turnLeft();
		} else {
			bcwturnLeft();
		}
	}
	if (left_sensor_state == 0) && (mid_sensor_state == 1) && (right_sensor_state == 1)){
		if (reverseMode == 0){
			turnRight();
		} else {
			bcwturnRight();
		}
	}
	if (left_sensor_state == 0) && (mid_sensor_state == 0) && (right_sensor_state == 1)){
		if (reverseMode == 0){
			turnRight();
		} else {
			bcwturnRight();
		}
	}

	if (left_sensor_state == 1) && (mid_sensor_state == 1) && (right_sensor_state == 1)){
		Stop();
	}
}


void forward(){
	if (distance > minDistance) {
		digitalWrite(M_A1, 0);
		digitalWrite(M_A2, 1);
		digitalWrite(M_B1, 1);
		digitalWrite(M_B2, 0);
	}
}

void backward(){
	digitalWrite(M_A1, 1);
	digitalWrite(M_A2, 0);
	digitalWrite(M_B1, 0);
	digitalWrite(M_B2, 1);
}

void turnRight(){
	if (distance > minDistance) {
		digitalWrite(M_A1, 0);
		digitalWrite(M_A2, 0);
		digitalWrite(M_B1, 1);
		digitalWrite(M_B2, 0);
	}
}
void bcwturnRight(){
	digitalWrite(M_A1, 0);
	digitalWrite(M_A2, 0);
	digitalWrite(M_B1, 0);
	digitalWrite(M_B2, 1);
}

void turnLeft(){
	if (distance > minDistance) {
		digitalWrite(M_A1, 0);
		digitalWrite(M_A2, 1);
		digitalWrite(M_B1, 0);
		digitalWrite(M_B2, 0);
	}
}
void bcwturnLeft(){
	digitalWrite(M_A1, 1);
	digitalWrite(M_A2, 0);
	digitalWrite(M_B1, 0);
	digitalWrite(M_B2, 0);
}

void Stop(){
	digitalWrite(M_A1, 0);
	digitalWrite(M_A2, 0);
	digitalWrite(M_B1, 0);
	digitalWrite(M_B2, 0);
}

void readUltrasonicSensor() {
	digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);
  duration = pulseIn(echoPin, 1);
  distance = duration * 0.034 / 2;
	if (distance < minDistance) {
		Stop();
	}
}



// void getaround(){
// 	x = millis();
// 	for (x, x<)
// 	turnAround();
// 	delay(1000);
// }


void turnAround(){
	digitalWrite(M_A1, 1);
	digitalWrite(M_A2, 0);
	digitalWrite(M_B1, 1);
	digitalWrite(M_B2, 0);
	// int backwardDone = 0;
	// if (distance < backwardDistance) {
	// 	backwardDone = 0;
	// 	backward();
	// } else {
	// 	backwardDone = 1;
	// }

	// if (backwardDone == 1){
	// 	turnRight();
	// 	delay(1000)
	// }

}