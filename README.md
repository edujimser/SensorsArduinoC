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
### 6. Configuración del módulo FT232BL

El módulo **FT232BL** permite la comunicación serie entre el PC y la placa Arduino Mega2560. Asegúrate de realizar las siguientes conexiones correctamente:

#### 🔌 Cableado recomendado

| FT232BL Pin | Mega2560 Pin | Descripción             |
|-------------|--------------|--------------------------|
| TXD         | RX0 (Pin 0)  | Transmisión desde FT232 |
| RXD         | TX0 (Pin 1)  | Recepción hacia FT232   |
| VCC         | 5V           | Alimentación            |
| GND         | GND          | Tierra común            |
| DTR         | RESET (a través de un capacitor de 0.1µF) | Auto-reset para carga de firmware |

> ⚠️ **Importante:** El pin **DTR** debe conectarse al pin **RESET** de la placa a través de un condensador de **0.1µF** para permitir el auto-reset durante la carga del firmware.

#### 🧪 Verificación

- Una vez conectado, abre el **Monitor Serial** en PlatformIO o Arduino IDE.
- Selecciona el puerto COM correspondiente al FT232BL.
- Configura la velocidad de baudios adecuada (por ejemplo, `9600` o `115200` según tu sketch).

---

¿Quieres que te incluya un diagrama ASCII del cableado o una explicación de cómo identificar los pines en el módulo FT232BL? También puedo ayudarte a documentar el uso del ARV-Debugger si lo necesitas.
