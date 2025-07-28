#ifndef PINS_H
#define PINS_H

// ----------------------------------------------
// Pines digitales del Arduino Mega 2560
// Documentación de modo: Entrada, Salida o Ambos
// ----------------------------------------------

// UART: Comunicación serial (RX = entrada, TX = salida)
#define PIN_RX0       0    // Entrada digital + Recepción serial UART0
#define PIN_TX0       1    // Salida digital + Transmisión serial UART0
#define PIN_RX1       19   // Entrada digital + UART1 RX + interrupción externa
#define PIN_TX1       18   // Salida digital + UART1 TX + interrupción externa
#define PIN_RX2       17   // Entrada digital + UART2 RX
#define PIN_TX2       16   // Salida digital + UART2 TX
#define PIN_RX3       15   // Entrada digital + UART3 RX
#define PIN_TX3       14   // Salida digital + UART3 TX

// PWM: Salidas digitales con capacidad de modulación por ancho de pulso
// Todos estos pines también se pueden configurar como entrada si no se usa PWM
#define PIN_PWM_2     2    // Entrada/Salida + PWM + interrupción externa
#define PIN_PWM_3     3    // Entrada/Salida + PWM + interrupción externa
#define PIN_PWM_4     4    // Entrada/Salida + PWM
#define PIN_PWM_5     5    // Entrada/Salida + PWM
#define PIN_PWM_6     6    // Entrada/Salida + PWM
#define PIN_PWM_7     7    // Entrada/Salida + PWM
#define PIN_PWM_8     8    // Entrada/Salida + PWM
#define PIN_PWM_9     9    // Entrada/Salida + PWM
#define PIN_PWM_10    10   // Entrada/Salida + PWM + pin SS SPI (salida recomendada)
#define PIN_PWM_11    11   // Entrada/Salida + PWM
#define PIN_PWM_12    12   // Entrada/Salida + PWM
#define PIN_PWM_13    13   // Entrada/Salida + PWM + LED integrado

// PWM extendido
#define PIN_PWM_44    44   // Entrada/Salida + PWM
#define PIN_PWM_45    45   // Entrada/Salida + PWM
#define PIN_PWM_46    46   // Entrada/Salida + PWM

// SPI: pines dedicados para comunicación rápida maestro-esclavo
#define PIN_MISO      50   // Entrada digital + SPI (entrada exclusiva para datos del esclavo)
#define PIN_MOSI      51   // Entrada/Salida + SPI (salida estándar, puede configurarse como entrada)
#define PIN_SCK       52   // Entrada/Salida + SPI (reloj, salida como maestro)
#define PIN_SS        53   // Entrada/Salida + SPI (selección de esclavo; salida recomendada)


// I2C / TWI: pines para comunicación de 2 hilos con sensores y periféricos
#define PIN_SDA       20   // Entrada/Salida + I2C datos + interrupción externa
#define PIN_SCL       21   // Entrada/Salida + I2C reloj + interrupción externa

// Interrupciones externas adicionales
#define INT_0         2    // Entrada digital + interrupción externa 0
#define INT_1         3    // Entrada digital + interrupción externa 1
#define INT_2         21   // Entrada digital + interrupción externa 2
#define INT_3         20   // Entrada digital + interrupción externa 3
#define INT_4         19   // Entrada digital + interrupción externa 4
#define INT_5         18   // Entrada digital + interrupción externa 5

// GPIO: Pines de propósito general configurables como entrada o salida
#define PIN_GPIO_22   22   // Entrada/Salida digital estándar
#define PIN_GPIO_23   23   // Entrada/Salida digital estándar
#define PIN_GPIO_24   24   // Entrada/Salida digital estándar
#define PIN_GPIO_25   25   // Entrada/Salida digital estándar
#define PIN_GPIO_26   26   // Entrada/Salida digital estándar
#define PIN_GPIO_27   27   // Entrada/Salida digital estándar
#define PIN_GPIO_28   28   // Entrada/Salida digital estándar
#define PIN_GPIO_29   29   // Entrada/Salida digital estándar
#define PIN_GPIO_30   30   // Entrada/Salida digital estándar
#define PIN_GPIO_31   31   // Entrada/Salida digital estándar
#define PIN_GPIO_32   32   // Entrada/Salida digital estándar
#define PIN_GPIO_33   33   // Entrada/Salida digital estándar
#define PIN_GPIO_34   34   // Entrada/Salida digital estándar
#define PIN_GPIO_35   35   // Entrada/Salida digital estándar
#define PIN_GPIO_36   36   // Entrada/Salida digital estándar
#define PIN_GPIO_37   37   // Entrada/Salida digital estándar
#define PIN_GPIO_38   38   // Entrada/Salida digital estándar
#define PIN_GPIO_39   39   // Entrada/Salida digital estándar
#define PIN_GPIO_40   40   // Entrada/Salida digital estándar
#define PIN_GPIO_41   41   // Entrada/Salida digital estándar
#define PIN_GPIO_42   42   // Entrada/Salida digital estándar
#define PIN_GPIO_43   43   // Entrada/Salida digital estándar
#define PIN_GPIO_47   47   // Entrada/Salida digital estándar
#define PIN_GPIO_48   48   // Entrada/Salida digital estándar
#define PIN_GPIO_49   49   // Entrada/Salida digital estándar

#endif /* PINS_H */