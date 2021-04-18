
// ANANt JAIN MCS20005 experiment 1


int task1Param = 0x1111;
int task2Param = 0x2222;
int task3Param = 0x3333;

void task1(void * task1Param){
  for(;;)
  {
   task1Param++;
  delay(1000);
  Serial.printf("the value of task1 %X\n",*(int*)task1Param);
  }}
void task2(void * task2Param){
  for(;;){
    task2Param++;
  delay(2000);
  Serial.printf("the value of task2 %X\n",*(int*)task2Param);
  }
}
void task3(void * task3Param){
   for(;;){
    task3Param++;
  delay(3000);
  Serial.printf("the value of task3 %X\n",*(int*)task3Param);
  }}

TaskHandle_t task1Handle;
TaskHandle_t task2Handle;
TaskHandle_t task3Handle;
eTaskState task1State;

void setup() {
  pinMode(2,OUTPUT);
  static int cpuID_0 = 0;
  Serial.begin(115200);
  xTaskCreate(task1, "Task1", 10000,(void *)&task1Param,2,&task1Handle); 
  xTaskCreate(task2, "Task2", 10000,(void *)&task2Param,2,&task2Handle); 
  xTaskCreate(task3, "Task3", 10000,(void *)&task3Param,2,&task3Handle); 
}

void loop() {
digitalWrite(2, HIGH);
  delay(1000);        
  digitalWrite(2, LOW);
  delay(1000);
  
  Serial.printf("Number of tasks in the system: %d\n", uxTaskGetNumberOfTasks());
  task1State = eTaskGetState(task1Handle);
  
  Serial.printf("Name of the task1 is %s\n", pcTaskGetTaskName(task1Handle));
  Serial.printf("Name of the task2 is %s\n", pcTaskGetTaskName(task2Handle));
  Serial.printf("Name of the task3 is %s\n", pcTaskGetTaskName(task3Handle));  
}
