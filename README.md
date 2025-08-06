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

### 7. Configuración de puertos en PlatformIO con Mega2560 + FT232BL (UART3)
Cuando trabajas con el **Arduino Mega2560** y un módulo **FT232BL** conectado a **UART3**, es fundamental identificar correctamente los puertos serie en tu sistema. Estos puertos pueden variar según el equipo, el sistema operativo y el orden en que conectes los dispositivos.

#### 🔍 ¿Cómo saber qué puerto corresponde a cada dispositivo?

PlatformIO ofrece una herramienta muy útil para listar los dispositivos conectados:

1. Abre **PlatformIO** en VSCode.
2. Ve al menú lateral izquierdo y haz clic en el ícono de **PlatformIO (alienígena)**.
3. Selecciona **"Devices"** en el menú.
4. Se mostrará una lista de puertos disponibles con información como:
   - Nombre del dispositivo
   - Descripción del chip (por ejemplo, "Arduino Mega 2560")
   - Puerto asignado (ej. `COM3`, `COM4`, `/dev/ttyUSB0`, etc.)

> 💡 **Consejo:** Conecta primero el Mega2560 por USB, observa qué puerto aparece. Luego conecta el FT232BL y verifica cuál es el nuevo puerto que se añade.

#### 📐 Diagrama ASCII de conexión FT232BL a UART3

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

#### ⚙️ Ejemplo completo y explicación del archivo `platformio.ini`

```ini
[env:megaatmega2560]
platform = atmelavr
board = megaatmega2560
framework = arduino

; Elimina el estándar gnu++11 y lo reemplaza por gnu++17
build_unflags = -std=gnu++11
build_flags = -std=gnu++17 -DAVR8_UART_NUMBER=3

; Puerto USB del Mega2560 para cargar el firmware
upload_port = COM3

; Usa la librería 'avr-debugger' para simular depuración
debug_tool = avr-stub

; Puerto del FT232BL conectado a UART3
debug_port = COM4

; Puerto del FT232BL para comunicación serial
monitor_port = COM4

; Velocidad en baudios (debe coincidir con Serial3.begin())
monitor_speed = 115200

[platformio]
description = Sensores
```

##### 🧾 Explicación línea por línea

- `platform = atmelavr`: Define la plataforma para microcontroladores AVR.
- `board = megaatmega2560`: Especifica el modelo de placa (Arduino Mega2560).
- `framework = arduino`: Usa el framework Arduino para compilar el proyecto.
- `build_unflags = -std=gnu++11`: Elimina el estándar C++11 por defecto.
- `build_flags = -std=gnu++17 -DAVR8_UART_NUMBER=3`: Usa C++17 y define que se usará UART3.
- `upload_port = COM3`: Puerto USB del Mega2560 para cargar el firmware.
- `debug_tool = avr-stub`: Activa la depuración simulada con la librería `avr-debugger`.
- `debug_port = COM4`: Puerto serie del FT232BL para depuración.
- `monitor_port = COM4`: Puerto serie del FT232BL para comunicación con el monitor serial.
- `monitor_speed = 115200`: Velocidad de comunicación (debe coincidir con `Serial3.begin()`).
- `[platformio] description = Sensores`: Descripción del proyecto.

#### 🧪 Verificación rápida

- Ejecuta en terminal:

  ```bash
  platformio device list
  ```

- Si tienes dudas, desconecta y vuelve a conectar cada dispositivo por separado y observa qué puerto aparece o desaparece.
- Asegúrate de que el puerto asignado en `upload_port` sea el del USB nativo del Mega2560 (UART0).
- El puerto del **FT232BL** debe usarse para `debug_port` y `monitor_port` si estás trabajando con **UART3**.

--
#### 🚫 No inicializar `Serial3` ni `Serial` manualmente

> ⚠️ **Importante:** No debes llamar a `Serial3.begin()` en tu código si estás usando **ARV-Debugger**.

La configuración en `platformio.ini` con `-DAVR8_UART_NUMBER=3` y `debug_tool = avr-stub` ya se encarga de inicializar automáticamente el puerto UART correspondiente para la depuración. Si lo inicializas manualmente, puedes interferir con el funcionamiento del debugger o provocar conflictos en el puerto serie.

