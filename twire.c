#include <stdio.h>

float sqRoot(float f_sq) //Возвращает квадратный корень числа f_sq
{
    if (f_sq >= 1) //Расчет тока менее 1А считаю нецелесообразным 
    {
        float f_i, f_sqrt; 
        for (f_sqrt = 1.0, f_i = f_sqrt; f_sq - f_i > 0.0001; f_sqrt += 0.0001)
        {
            f_i = f_sqrt;
            f_i *= f_i;
        }
        return f_sqrt;
    }

    else return 0;    
}

void calculateTemperature(void) //Рассчитывает температуру жилы
{
    const float f_nominalTemperatureDiff = 40;

    float f_realWireTemperature,
        f_realAtmosphereTemperature,
        f_nominalCurrent,
        f_realCurrent;

    printf("\nВыбран расчет температуры."
        "\nЧерез пробел вводим: температуру окружающей среды, табличный ток, желаемый ток\n"
        );

    scanf("%f %f %f",
        &f_realAtmosphereTemperature,
        &f_nominalCurrent,
        &f_realCurrent
        );

    f_realWireTemperature = f_realAtmosphereTemperature
        + f_nominalTemperatureDiff * (f_realCurrent*f_realCurrent)/(f_nominalCurrent*f_nominalCurrent);

    printf("\nРассчетная температура жилы: %.1f\n", f_realWireTemperature);
}

void calculateCurrent(void) //Расчитывает ток жилы
{
    const float f_nominalTemperatureDiff = 40;

    float f_realWireTemperature,
        f_realAtmosphereTemperature,
        f_nominalCurrent,
        f_realCurrent;

    printf("\nВыбран расчет тока."
        "\nЧерез пробел вводим: температуру окружающей среды, табличный ток, желаемую температуру жилы\n"
        );
        
    scanf("%f %f %f",
        &f_realAtmosphereTemperature,
        &f_nominalCurrent,
        &f_realWireTemperature
        );

    float f_sqRealCurrent = (f_nominalCurrent * f_nominalCurrent * (f_realWireTemperature - f_realAtmosphereTemperature)) 
        / f_nominalTemperatureDiff;

    f_realCurrent = sqRoot(f_sqRealCurrent);
    printf("\nРассчетный допустимый ток: % .1f\n", f_realCurrent);
}



int main (void)
{
    int i_isTemperature;

    printf("\nРасчет тока - 0, расчет температуры - 1\n");
    scanf("%u", &i_isTemperature);
    
    if(i_isTemperature)
    {
        calculateTemperature();
    }

    else
    {
        calculateCurrent();
    }

    return 0;

}