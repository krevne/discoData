#include "main.h"
#include "mymain.h"

struct Led
{
    explicit Led(GPIO_TypeDef* t_gpio, uint16_t t_pin)
        : gpio(t_gpio)
        , pin(t_pin)
    {
    }
    void on()
    {
        HAL_GPIO_WritePin(gpio, pin, GPIO_PIN_SET);
    }
    void off()
    {
        HAL_GPIO_WritePin(gpio, pin, GPIO_PIN_RESET);
    }
    void toggle()
    {
        HAL_GPIO_TogglePin(gpio, pin);
    }
    auto state() -> bool
    {
        return HAL_GPIO_ReadPin(gpio, pin);
    }

private:
    GPIO_TypeDef* gpio;
    uint16_t pin;
};

void myMain()
{
    Led led(GPIOD,LD3_Pin);
    while(true)
    {
        led.toggle();
        HAL_Delay(600);
        /*
        HAL_GPIO_WritePin(GPIOD,LD3_Pin,GPIO_PIN_SET);
        HAL_Delay(600);
        HAL_GPIO_WritePin(GPIOD,LD3_Pin,GPIO_PIN_RESET);
        HAL_Delay(600);
        */
    }
}