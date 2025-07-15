#include <stdio.h>

#define A 1 //Пункты меню
#define B 2

int getChoice(int a, int b);
float calculateCurrent(void);
float calculateTemperature(void);

int main (void)
{
    int choice;
    while ((choice = getChoice(A, B)) != EOF)
    {
        switch (choice)
        {
            case A:
                printf("\nВыбран расчет тока."
                    "\nЧерез пробел вводим: температуру окружающей среды, табличный ток, желаемую температуру жилы\n"
                    );
                printf("\nДопустимый расчетный ток: %.1f\n", calculateCurrent());
                break;
            case B:
                printf("\nВыбран расчет температуры."
                    "\nЧерез пробел вводим: температуру окружающей среды, табличный ток, желаемый ток\n"
                    );
                printf("\nДопустимая расчетная температура: %.1f\n", calculateTemperature());
                break;
            default:
                printf("\nДля выхода из программы:\n\tctrl+Z для Windows\n\tctrl+D для Linux");
                break;
        }
    }
    printf("Завершение работы\n");
    return 0;
}

void clean(void) //Чистит буфер ввода
{
    while (getchar() != '\n')
        continue;
}

int getChoice(int a, int b) //Обрабатывает меню выбора операции
{
        printf("\nДля расчета введите:\n\t%d - расчет тока\n\t%d - расчет температуры\n", a, b);
        int choice;
        int state = scanf("%d", &choice);
        if (EOF == state)
            return EOF;
        if(1 == state)
        {
            clean();
            return choice;
        }
        clean();
        return 0;
}

float sqRoot(float sq) //Возвращает квадратный корень числа sq
{
    if (sq >= 1) //Расчет тока менее 1А считаю нецелесообразным 
    {
        float i, sqrt; 
        for (sqrt = 1.0, i = sqrt; sq - i > 0.0001; sqrt += 0.0001)
        {
            i = sqrt;
            i *= i;
        }
        return sqrt;
    }
    else return 0;    
}

float calculateTemperature(void) //Принимает данные из потока ввода и расчитывает температуру жилы
{
    const short NominalTemperatureDiff = 40;
    float realWireTemperature,
        realAtmosphereTemperature,
        nominalCurrent,
        realCurrent;

    scanf("%f %f %f",
        &realAtmosphereTemperature,
        &nominalCurrent,
        &realCurrent
        );

    realWireTemperature = realAtmosphereTemperature
        + (float)NominalTemperatureDiff * (realCurrent*realCurrent)/(nominalCurrent*nominalCurrent);
    return realWireTemperature;
}

float calculateCurrent(void) //Принимает данные из потока ввода и расчитывает ток жилы
{
    const short NominalTemperatureDiff = 40;
    float realWireTemperature,
        realAtmosphereTemperature,
        nominalCurrent,
        realCurrent;

    scanf("%f %f %f",
        &realAtmosphereTemperature,
        &nominalCurrent,
        &realWireTemperature
        );

    float f_sqRealCurrent = (nominalCurrent * nominalCurrent * (realWireTemperature - realAtmosphereTemperature)) 
        / (float)NominalTemperatureDiff;
    realCurrent = sqRoot(f_sqRealCurrent);
    return realCurrent;
}