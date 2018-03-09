
int motorPin = 5;

int leftPotPin = 1; // 5v sensor
float leftPotVal = 0.0;
float leftPotMin = 70.0;
float leftPotMax = 601.0;
float leftPercent = 0.0; // 0 to 100

int rightPotPin = 0; // 3.3v sensor
float rightPotVal = 0.0;
float rightPotMin = 49.0;
float rightPotMax = 399.0;
float rightPercent = 0.0; // 0 to 100

float averagePercent = 0.0;
float difBetweenInputs = 0.0;
float motorOutputValue = 0.0;



void setup()
{
	pinMode(leftPotPin, INPUT);
	pinMode(rightPotPin, INPUT);
	pinMode(motorPin, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	// Left sensor
	leftPotVal = analogRead(leftPotPin);
	if (leftPotVal*1.01 > leftPotMax)
		leftPotVal = leftPotMax;
	else if (leftPotVal*0.99 < leftPotMin)
		leftPotVal = leftPotMin;
	leftPercent = map(leftPotVal, leftPotMin, leftPotMax, 0, 100);
	/*Serial.print("left value: ");
	Serial.print(leftPotVal);
	Serial.print('\n');
	Serial.print("left percent: ");
	Serial.print(leftPercent);
	Serial.print('\n');
	Serial.print('\n');*/

	// Right sensor
	rightPotVal = analogRead(rightPotPin);
	if (rightPotVal*1.01 > rightPotMax)
		rightPotVal = rightPotMax;
	else if (rightPotVal*0.99 < rightPotMin)
		rightPotVal = rightPotMin;
	rightPercent = map(rightPotVal, rightPotMin, rightPotMax, 0, 100);
	/*Serial.print("right value: ");
	Serial.print(rightPotVal);
	Serial.print('\n');
	Serial.print("right percent: ");
	Serial.print(rightPercent);
	Serial.print('\n');
	Serial.print('\n');*/

	// Average
	difBetweenInputs = abs(leftPercent - rightPercent);
	averagePercent = (leftPercent + rightPercent) / 2.0;
	if(difBetweenInputs >=10)
		motorOutputValue = 0;
	else
		motorOutputValue = map(averagePercent, 0, 100, 0, 100);
	analogWrite(motorPin, motorOutputValue);
	//Serial.print("Difference in percents: ");
	//Serial.print(difBetweenInputs);
	Serial.print('\n');
	//Serial.print("AVERAGE: ");
	//Serial.print(averagePercent);
	//Serial.print('\n');
	Serial.print("motor output: ");
	Serial.print(motorOutputValue);
	Serial.print('\n');
	Serial.print('\n');
	Serial.print("--------------------------------------");
	Serial.print('\n');
	Serial.print('\n');

	delay(500);
}