
 // some code 
int main(void)
{
	// some code 

  I2CSoftware i2c2(GPIOB, GPIO_PIN_11 /*SDA*/, GPIO_PIN_10/*SCL*/, 12 /* delay */ );
  I2CSoftware i2c1(GPIOB, GPIO_PIN_7, GPIO_PIN_6, 15);

   adc.Init(&hadc1);
   Track track;
   Chair chair;
   DriveController driveController;
   Accelerometer accelerometerBlock(address::accelerometerChair);
   Accelerometer accelerometerChair(address::accelerometerBlock);

   accelerometerBlock.SetDescriptor(&hspi2);
   accelerometerChair.SetDescriptor(&i2c2);

   accelerometerBlock.Init();
   accelerometerChair.Init();


   Battery battery;
   Charg charg;

   AdditionalWheel additionalWheel;

   ActuatorsController actuatorController(track, chair, additionalWheel, accelerometerBlock, accelerometerChair);

   adc.RegisterClass(ADC::BATTERY, &battery);
   adc.RegisterClass(ADC::PLATFORM_CURRENT, &track);
   adc.RegisterClass(ADC::PLATFORM_SENS, &track);
   adc.RegisterClass(ADC::CHAIR_CURRENT, &chair);
   adc.RegisterClass(ADC::ADDITIONAL_WHEEL_CURRENT, &additionalWheel);
   adc.RegisterClass(ADC::ADDITIONAL_WHEEL_SENS, &additionalWheel);
   adc.RegisterClass(ADC::LW_CURRENT, &driveController);
   adc.RegisterClass(ADC::RW_CURRENT, &driveController);
   adc.RegisterClass(ADC::LEFT_BRAKE, &driveController);
   adc.RegisterClass(ADC::RIGHT_BRAKE, &driveController);
   CommunicationsManager communicationsManager(i2c1,
 		  	  	  	  	  	  	  	  	  	  actuatorController,
 											  adc,
 											  driveController,
 											  battery,
 											  charg);


  //some code

  while (1)
  {	  
  
	 actuatorController.Update(driveController.GetJoystic());
	 if(!charg.GetCharging())
	 {
		  driveController.UpDate(&actuatorController);
	 }

	//some code
		  
	communicationsManager.TalkToSlave();

  }
}
