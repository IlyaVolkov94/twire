#include <stdio.h>

float sqRoot(float sq) //Возвращает квадратный корень числа sq
{
    if (sq > 1)
    {
        float i, sqrt; 
        sqrt = 1.0001;
        i = sqrt;
        for (; sq - i > 0.0001; sqrt += 0.0001)
        {
            i = sqrt;
            i *= i;
        }
        return sqrt;
    }
    
}

int main (void)
{
    const int nominalAtmosphereTemperature = 25,
        nominalWireTemperature = 65.0;

    float realWireTemperature,
        realAtmosphereTemperature,
        nominalCurrent,
        realCurrent;

    int isTemperature;

    printf("\nРасчет тока - 0, расчет температуры - 1\n");
    scanf("%u", &isTemperature);
    
    if(isTemperature)
    {
        printf("\nВыбран расчет температуры."
            "\nЧерез пробел вводим: температуру окружающей среды, табличный ток, желаемый ток\n"
            );

        scanf("%f %f %f",
            &realAtmosphereTemperature,
            &nominalCurrent,
            &realCurrent
            );

        realWireTemperature = realAtmosphereTemperature
            + ((float)nominalWireTemperature - (float)nominalAtmosphereTemperature)
            * (realCurrent*realCurrent)/(nominalCurrent*nominalCurrent);

        printf("\nРассчетная температура жилы: %.1f\n", realWireTemperature);
    }

    else
    {
        printf("\nВыбран расчет тока."
            "\nЧерез пробел вводим: температуру окружающей среды, табличный ток, желаемую температуру жилы\n"
            );
        
        scanf("%f %f %f",
            &realAtmosphereTemperature,
            &nominalCurrent,
            &realWireTemperature
            );

        float sqRealCurrent = (nominalCurrent * nominalCurrent * (realWireTemperature - realAtmosphereTemperature)) 
            / (nominalWireTemperature - nominalAtmosphereTemperature);

        realCurrent = sqRoot(sqRealCurrent);
        printf("\nРассчетный допустимый ток: % .1f\n", realCurrent);
    }

    return 0;

}