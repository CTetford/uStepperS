#include <Arduino.h>

/** Chip select for AEAT-8800-Q24 - Pin 10 on ATmega328p */
#define CS PB2 

/** Data in for AEAT-8800-Q24 - Pin 11 on ATmega328p (MOSI) */
#define DIN PB3 

/** Data out for AEAT-8800-Q24 - Pin 12 on ATmega328p (MISO) */
#define DO PB4 

/** Clock signal for AEAT-8800-Q24 - Pin 13 on ATmega328p (SCK) */
#define CLK PB5 


class uStepperEncoder
{
	public:

		/**
		 * @brief	Constructor of uStepperEncoder class
		 */
		uStepperEncoder(void);

		void initiate( uStepperS * _pointer );

		/**
		 * @brief      Return the current shaft angle
		 *
		 *             This function returns the last captured shaft angle.
		 *             The resolution of the angle returned by this function is
		 *             0.0054931640625 degrees (16 bits)
		 *
		 * @return     Floating point representation of the current motor shaft
		 *             angle
		 */
		float getAngle(void);

		uint16_t getRaw(void);

		/**
		 * @brief      Capture the current shaft angle
		 *
		 *             This function is used by the ISR to read the current angle of the motor shaft.
		 *             The Angle is read by means of the SSI interface, using the hardware SPI port.
		 */
		void captureAngle(void);

		

	private:
		
		/* Reference to the main object */
		uStepperS * pointer;

		/** This variable always contain the current rotor angle, relative
		  * to a single revolution */
		volatile uint16_t angle;

		void chipSelect(bool state);
	
};

