#define O2_VALVE_GPIO 1
#define AIR_VALVE_GPIO 2
#define NUMBER_OF_PRESET_VALUE 9

typedef struct {
  float air;
  float o2;
} t_O2Controller_air_mix;

t_O2Controller_air_mix O2Controller_air_mix[NUMBER_OF_PRESET_VALUE] = {
  {1, 0}, // 21% O2
  {0.875, 0.125}, // 30% O2
  {0.75, 0.25}, // 40% O2
  {0.625, 0.375}, // 50% O2
  {0.5, 0.5}, // 60% O2
  {0.375, 0.625}, // 70% O2
  {0.25, 0.75}, // 80% O2
  {0.125, 0.875}, // 90% O2
  {0, 1} // 100% O2
};

float O2Controller_increment_to_percent[NUMBER_OF_PRESET_VALUE] = {
  21, 30, 40, 50, 60, 70, 80, 90, 100
};

int actual_setup = 0;

void O2Controller_Setup() {
  pinMode(O2_VALVE_GPIO, OUTPUT);
  pinMode(AIR_VALVE_GPIO, OUTPUT);
  O2Controller_updateO2(actual_setup);
}

void O2Controller_updateO2(int increment) {
  if (increment >= NUMBER_OF_PRESET_VALUE) {
    return;
  }
  actual_setup = increment;

  // Compute and set new mix
  byte air_duty_cycle = 255 * O2Controller_air_mix[increment].air;
  byte o2_duty_cycle = 255 * O2Controller_air_mix[increment].o2;
  analogWrite(AIR_VALVE_GPIO, air_duty_cycle);
  analogWrite(O2_VALVE_GPIO, o2_duty_cycle);

  // Print values
  sprintf(print_buffer, "O2 percent: %d \%,O2 valve: %d, air valve %d", O2Controller_increment_to_percent[increment], o2_duty_cycle, air_duty_cycle);
  Serial.println(print_buffer);
}

void O2Controller_calibrate() {

}
