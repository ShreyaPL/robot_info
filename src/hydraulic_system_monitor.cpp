#include "robot_info/agv_robot_info_class.h"
#include <ros/ros.h>
#include <string>

class HydraulicSystemMonitor{
    public:
        HydraulicSystemMonitor(const std::string &temperature, const std::string &fill_level, const std::string &pressure)
            :hydraulic_oil_temperature(temperature),
            hydraulic_oil_tank_fill_level(fill_level),
            hydraulic_oil_pressure(pressure) {}
        
        // Getter methods:
        std::string getHydraulicOilTemperature() const{
            return hydraulic_oil_temperature;
        }

        std::string getHydraulicOilTankFillLevel() const{
            return hydraulic_oil_tank_fill_level;
        }

        std::string getHydraulicOilPressure() const{
            return hydraulic_oil_pressure;
        }
    private:
        std::string hydraulic_oil_temperature;
        std::string hydraulic_oil_tank_fill_level;
        std::string hydraulic_oil_pressure;
};
