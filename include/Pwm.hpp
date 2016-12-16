#ifndef FLINKEEROS_PWM_HPP_
#define FLINKEEROS_PWM_HPP_

#include <string>
#include <flinklib.h>
#include <eeros/hal/ScalableOutput.hpp>
#include <FlinkDevice.hpp>
#include <limits>

extern "C"{
	eeros::hal::ScalableOutput<double> *createPwm(std::string id, std::string device, uint32_t subDeviceNumber, uint32_t channel, double scale, double offset, double rangeMin, double rangeMax, std::string unit);
}

namespace flink {
	class Pwm : public eeros::hal::ScalableOutput<double> {
	public:
	Pwm(std::string id, std::string device, uint32_t subDeviceNumber, uint32_t channel, double scale = 1, double offset = 0, double rangeMin = std::numeric_limits<double>::min(), double rangeMax = std::numeric_limits<double>::max(), std::string unit = "");
		virtual double get();
		virtual void set(double dutyCycle);
		virtual void setFrequency(double f);
		virtual void setDutyCycle(double d);
		
	private:
		flink_subdev* subdeviceHandle;
		uint32_t channel;
		double pwmFrequency;
		uint32_t baseFrequency;
	};
};

#endif /* FLINKEEROS_PWM_HPP_ */