#include <vector>
#include <numeric>

long result;   //variable for the result of the tx_rx measurement.
int analog_pin_1 = 4;
int analog_pin_2 = 2;
int tx_pin = 19;

int interval = 40;
int iterations = 1000 / interval;
unsigned long prev_ms = 0;
std::vector<long> sumVal;

void setup() {
    pinMode(tx_pin, OUTPUT);      //Pin 19 provides the voltage step
    Serial.begin(9600);
}

void loop() {
    result = tx_rx(analog_pin_1);
    averaging(result);
    //Serial.println(result);
}

void averaging(long result) {
  unsigned long current_ms = millis();
  if (current_ms - prev_ms >= interval) {
    prev_ms = current_ms;
    sumVal.push_back(result);
    if (sumVal.size() == iterations) {
      float avg = std::accumulate(sumVal.begin(), sumVal.end(), 0) / iterations;
      Serial.println(avg);
      Serial.println(pencil_location(avg));
      sumVal.resize(0);
    }
  }
}

int pencil_location(float avg) {
  if (avg >= 11000) {
    return 1;
  }
  else if ((avg < 11000) && (avg >= 9300)) {
    return 2;
  } 
  else if ((avg < 9300) && (avg >= 8100)) {
    return 3;
  }
  else if ((avg < 8100) && (avg >= 7300)) {
    return 4;
  }
  else if ((avg < 7300) && (avg >= 6900)) {
    return 5;
  }
  else if ((avg < 6900) && (avg >= 6200)) {
    return 6;
  }
  else if ((avg < 6200) && (avg >= 5900)) {
    return 7;
  }
  else if ((avg < 5900) && (avg >= 5200)) {
    return 8;
  }
  else if ((avg < 5200) && (avg >= 4600)) {
    return 9;
  }
  else if ((avg < 4600) && (avg >= 4350)) {
    return 10;
  }
  else if ((avg < 4350) && (avg >= 3600)) {
    return 11;
  }
  else {
    return 12;
  }
}

long tx_rx(int analog_pin){         // Function to execute rx_tx algorithm and return a value
                      // that depends on coupling of two electrodes.
                      // Value returned is a long integer.
  int read_high;
  int read_low;
  int diff;
  long int sum;
  int N_samples = 100;    // Number of samples to take.  Larger number slows it down, but reduces scatter.

  sum = 0;

  for (int i = 0; i < N_samples; i++){
   digitalWrite(tx_pin,HIGH);              // Step the voltage high on conductor 1.
   read_high = analogRead(analog_pin);     // Measure response of conductor 2.
   delayMicroseconds(100);                 // Delay to reach steady state.
   digitalWrite(tx_pin,LOW);               // Step the voltage to zero on conductor 1.
   read_low = analogRead(analog_pin);      // Measure response of conductor 2.
   diff = read_high - read_low;            // desired answer is the difference between high and low.
   sum += diff;                            // Sums up N_samples of these measurements.
 }
  return sum;
}                                          // End of tx_rx function.