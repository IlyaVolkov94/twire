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

void clean(void) //Чистим буфер ввода
{
    while (getchar() != '\n')
        continue;
}


int main (void)
{
    while (1)
    {
        printf("\nДля расчета введите:\n\t0 - расчет тока\n\t1 - расчет температуры\n");
        int choice;
        int state = scanf("%d", &choice);
        if (EOF == state)
            break;
        if(0 == state)
        {
            clean();
            continue;
        }
        clean();
        switch (choice)
        {
            case 0:
                calculateCurrent();
                continue;
            case 1:
                calculateTemperature();
                continue;
            default:
                continue;
        }
        break;
    }
      
    return 0;
}