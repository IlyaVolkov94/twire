#include <stdio.h>

void main (void)
{
    const int nominalAtmosphereTemperature = 25;
    const double nominalWireTemperature = 65.0;

    double realWireTemperature = 70.0,
        realAtmosphereTemperature = 60.0,
        nominalCurrent,
        realCurrent;

    _Bool isTemperature;
    
    scanf("\nРасчет тока - 0, расчет температуры - 1\n %u", &isTemperature);
    
    if(isTemperature)
    {
        scanf("\nЧерез пробел вводим: температуру окружающей среды, табличный ток, желаемый ток\n %f %f %f",
            &realAtmosphereTemperature,
            &nominalCurrent,
            &realCurrent
            );

        realWireTemperature = realAtmosphereTemperature + (nominalWireTemperature - nominalAtmosphereTemperature)
            * (realCurrent*realCurrent)/(nominalCurrent*nominalCurrent);
        printf("\nРассчетная температура жилы: %.1f/n", realWireTemperature);
    }

    return 0;

}