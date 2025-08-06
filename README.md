# Sistema de pruebas de sensores en C++ con placa Mega2560

Este proyecto es un sistema modular para la creación, prueba y validación de funciones que interactúan con sensores utilizando C++ y la placa Arduino Mega2560. Está diseñado para facilitar el desarrollo incremental de funciones, permitiendo pruebas rápidas y organización clara del código.

## 🚀 Objetivos del proyecto

- Crear funciones reutilizables para sensores.
- Probar cada sensor de forma independiente.
- Usar PlatformIO para gestionar el entorno de desarrollo.
- Mantener una estructura clara y escalable del código.

## 🛠️ Tecnologías utilizadas

- **Arduino Mega2560**: Microcontrolador principal del sistema.
- **PlatformIO**: Entorno de desarrollo para compilar y cargar el firmware.
- **ARV-Debugger**: Herramienta para depuración y análisis del comportamiento del código.
- **FT232BL**: Módulo USB a serie para comunicación y programación externa.




---
## ⚙️ Instalación base
Sigue estos pasos para configurar el entorno de desarrollo y comenzar a trabajar con el proyecto:

### 1. Instalar PlatformIO
PlatformIO puede instalarse como extensión de VSCode o desde la terminal.

- **VSCode**: Instala la extensión "PlatformIO IDE" desde el marketplace.
- **Terminal (opcional)**:
  ```bash
  pip install platformio

### 2. Clonar el repositorio
  git clone https://github.com/edujimser/SensorsArduinoC.git
  cd tu-repositorio
  
### 3. Seleccionar la placa Mega2560
El archivo `platformio.ini` ya está configurado para usar la placa Arduino Mega2560:

```ini
[env:mega2560]
platform = atmelavr
board = mega2560
framework = arduino
```

### 4. Conectar el hardware
- Conecta la placa **Mega2560** al PC mediante USB.
- Si usas el módulo **FT232BL**, asegúrate de que esté correctamente cableado al puerto serie de la placa.
- Si usas **ARV-Debugger**, conecta según el esquema de depuración que estés utilizando.


### 5. Compilar y cargar el firmware
**Desde PlatformIO:**
- Haz clic en el ícono de **Build** 🛠️ para compilar.
- Haz clic en **Upload** ⬆️ para cargar el firmware a la placa.

**O desde la terminal:**
```bash
platformio run --target upload
```
### 6. Configuración del módulo FT232BL usando UART3

El Arduino Mega2560 dispone de múltiples puertos UART. Para usar el **UART3**, debes conectar el módulo **FT232BL** a los pines correspondientes:

#### 🔌 Cableado para UART3

| FT232BL Pin | Mega2560 Pin | Descripción             |
|-------------|--------------|--------------------------|
| TXD         | RX3 (Pin 15) | Transmisión desde FT232 |
| RXD         | TX3 (Pin 14) | Recepción hacia FT232   |
| VCC         | 5V           | Alimentación            |
| GND         | GND          | Tierra común            |
| DTR         | *No necesario* | No se usa con UART3     |

> ⚠️ **Nota:** Al usar UART3, el pin **DTR** no se conecta al pin RESET, ya que no se utiliza el auto-reset para cargar firmware. La carga del firmware sigue haciéndose por USB nativo (UART0), mientras UART3 se usa para comunicación adicional.

---

#### 📐 Diagrama ASCII de conexión

```
+------------------+        +----------------------+
|   FT232BL        |        |   Arduino Mega2560   |
|------------------|        |----------------------|
| TXD ------------> RX3     | Pin 15               |
| RXD <------------ TX3     | Pin 14               |
| VCC ------------> 5V      |                      |
| GND ------------> GND     |                      |
| DTR ---✖ (no usar)        |                      |
+------------------+        +----------------------+
```
